#include "stats.h"
#include <vector>
#include "logger.h"

#undef SetTurn
#undef RegisterHit
#undef RegisterResult
#undef PrintStats

using namespace std;

/*
 * 1. разделение статистики на выигрышную и проигрышную
 * 2. Кто по кому и сколько ударил в среднем по каждому раунду
 * 3. Минимальное HP в каждом раунде
 * 4. Вероятность смерти в каждом раунде
 */


Stats::Stats(int _team_size)
    : team_size(_team_size)
{
}

void Stats::RegisterResult(bool result)
{
    if (result)
        win_count++;
    else
        defeat_count++;

    for (auto &t: turns) {
        int round, turn;
        tie(round, turn) = t;
        if ((int)round_turn_count[result].size() <= round)
            round_turn_count[result].resize(round+1);
        if ((int)round_turn_count[result][round].size() <= turn)
            round_turn_count[result][round].resize(turn+1, 0);
        ++round_turn_count[result][round][turn];
    }

    for (auto &hit: this->hit) {
        int round, turn;
        int attacker_index, target_index;
        int target_old_health, target_new_health;
        int dmg, full_dmg;
        tie(round, turn, attacker_index, target_index, target_old_health, target_new_health, dmg, full_dmg) = hit;

        if ((int)min_hp[result].size() <= round)
            min_hp[result].resize(round+1);
        if ((int)min_hp[result][round].size() <= turn)
            min_hp[result][round].resize(turn+1, vector<int>(team_size, -1));
        if (min_hp[result][round][turn][target_index] == -1 ||
            min_hp[result][round][turn][target_index] > target_new_health)
            min_hp[result][round][turn][target_index] = target_new_health;

        if ((int)death_count[result].size() <= round)
            death_count[result].resize(round+1);
        if ((int)death_count[result][round].size() <= turn)
            death_count[result][round].resize(turn+1, vector<int>(team_size, 0));
        if (target_old_health != 0 && target_new_health == 0)
            ++death_count[result][round][turn][target_index];

        if ((int)damage[result].size() <= round)
            damage[result].resize(round+1);
        if ((int)damage[result][round].size() <= turn)
            damage[result][round].resize(turn+1, vector<vector<int>>(team_size, vector<int>(team_size, 0)));
        damage[result][round][turn][attacker_index][target_index] += full_dmg;
    }

    curr_round = 0;
    curr_turn = 0;
    hit.clear();
    turns.clear();
}

void Stats::RegisterHit(int attacker, int target, int old_health, int new_health, int damage, int full_damage)
{
    hit.emplace_back(curr_round, curr_turn, attacker, target, old_health, new_health, damage, full_damage);
}

void Stats::NextTurn(int round, int turn)
{
    curr_round = round;
    curr_turn = turn;
    turns.emplace_back(round, turn);
}

void Stats::Print(Dino team[], int team_size)
{
    ERROR("Chance: %.1lf%%", win_count * 100. / (win_count + defeat_count));

    for (int w = 1; w >= 0; --w) {
        string s = strprintf("%-30s   ", w ? strprintf("Death (win: %.1lf%%)", win_count * 100. / (win_count + defeat_count)).c_str()
                                           : strprintf("Death (defeat: %.1lf%%)", defeat_count * 100. / (win_count + defeat_count)).c_str());
        WARNING("");
        for (int r = 0; r < (int)death_count[w].size(); ++r) {
            if (r != 0)
                s += "| ";
            for (int t = 0; t < (int)death_count[w][r].size(); ++t)
                s += strprintf("%5s ", strprintf("r%dt%d", r+1, t+1).c_str());
        }
        WARNING("%s", s.c_str());
        for (int i = 0; i < team_size; ++i) {
            string s = strprintf("%30s ", team[i].name.c_str());
            for (int r = 0; r < (int)death_count[w].size(); ++r) {
                s += "| ";
                for (int t = 0; t < (int)death_count[w][r].size(); ++t) {
                    s += strprintf("%4d%% ", death_count[w][r][t][i] * 100 / round_turn_count[w][0][0]);
                }
            }
            WARNING("%s", s.c_str());
        }
    }

    for (int w = 1; w >= 0; --w) {
        string s = strprintf("%-30s   ", w ? strprintf("Minimal HP (win: %.1lf%%)", win_count * 100. / (win_count + defeat_count)).c_str()
                                           : strprintf("Minimal HP (defeat: %.1lf%%)", defeat_count * 100. / (win_count + defeat_count)).c_str());
        INFO("");
        for (int r = 0; r < (int)min_hp[w].size(); ++r) {
            if (r != 0)
                s += "| ";
            for (int t = 0; t < (int)min_hp[w][r].size(); ++t)
                s += strprintf("%5s ", strprintf("r%dt%d", r+1, t+1).c_str());
        }
        INFO("%s", s.c_str());
        for (int i = 0; i < team_size; ++i)
        {
            string s = strprintf("%30s ", team[i].name.c_str());
            for (int r = 0; r < (int)min_hp[w].size(); ++r)
            {
                s += "| ";
                for (int t = 0; t < (int)min_hp[w][r].size(); ++t)
                    s += min_hp[w][r][t][i] != -1 ? strprintf("%5d ", min_hp[w][r][t][i]) : "    * ";
            }
            INFO("%s", s.c_str());
        }
    }

    for (int w = 1; w >= 0; --w) {
        string s = strprintf("%-30s   ", w ? strprintf("Rounds length (win: %.1lf%%)", win_count * 100. / (win_count + defeat_count)).c_str()
                                           : strprintf("Rounds length (defeat: %.1lf%%)", defeat_count * 100. / (win_count + defeat_count)).c_str());
        WARNING("");
        for (int t = 0; ; ++t) {
            int r;
            for (r = 0; r < (int)round_turn_count[w].size(); ++r) {
                if (t < (int)round_turn_count[w][r].size())
                    break;
            }
            if (r == (int)round_turn_count[w].size())
                break;
            s += strprintf("%5d ", t+1);
        }
        WARNING("%s", s.c_str());
        for (int r = 0; r < (int)round_turn_count[w].size(); ++r)
        {
            string s = strprintf("%30s | ", strprintf("Round %d", r+1).c_str());
            for (int t = 0; t < (int)round_turn_count[w][r].size(); ++t)
            {
                int rt_count = round_turn_count[w][r][t] - (t+1 < (int)round_turn_count[w][r].size() ? round_turn_count[w][r][t+1] : 0);
                s += strprintf("%4d%% ", rt_count * 100 / round_turn_count[w][0][0]);
            }
            WARNING("%s", s.c_str());
        }
    }

    for (int i = 0; i < team_size; ++i) {
        DEBUG("");
        DEBUG("%s avg. damage/heal", team[i].name.c_str());
        for (int w = 1; w >= 0; --w) {
            string s = strprintf("%-30s   ", w ? strprintf("Dealt to (win: %.1lf%%)", win_count * 100. / (win_count + defeat_count)).c_str()
                                               : strprintf("Dealt to (defeat: %.1lf%%)", defeat_count * 100. / (win_count + defeat_count)).c_str());
            for (int r = 0; r < (int)damage[w].size(); ++r) {
                if (r != 0)
                    s += "| ";
                for (int t = 0; t < (int)damage[w][r].size(); ++t)
                    s += strprintf("%5s ", strprintf("r%dt%d", r+1, t+1).c_str());
            }
            DEBUG("%s", s.c_str());
            for (int j = 0; j < team_size; ++j) {
                string s = strprintf("%30s ", team[j].name.c_str());
                for (int r = 0; r < (int)damage[w].size(); ++r) {
                    s += "| ";
                    for (int t = 0; t < (int)damage[w][r].size(); ++t) {
                        s += strprintf("%5d ", damage[w][r][t][i][j] / round_turn_count[w][r][t]);
                    }
                }
                DEBUG("%s", s.c_str());
            }
        }
        for (int w = 1; w >= 0; --w) {
            string s = strprintf("%-30s   ", w ? strprintf("Received from (win: %.1lf%%)", win_count * 100. / (win_count + defeat_count)).c_str()
                                               : strprintf("Received from (defeat: %.1lf%%)", defeat_count * 100. / (win_count + defeat_count)).c_str());
            for (int r = 0; r < (int)damage[w].size(); ++r) {
                if (r != 0)
                    s += "| ";
                for (int t = 0; t < (int)damage[w][r].size(); ++t)
                    s += strprintf("%5s ", strprintf("r%dt%d", r+1, t+1).c_str());
            }
            DEBUG("%s", s.c_str());
            for (int j = 0; j < team_size; ++j) {
                string s = strprintf("%30s ", team[j].name.c_str());
                for (int r = 0; r < (int)damage[w].size(); ++r) {
                    s += "| ";
                    for (int t = 0; t < (int)damage[w][r].size(); ++t) {
                        s += strprintf("%5d ", damage[w][r][t][j][i] / round_turn_count[w][r][t]);
                    }
                }
                DEBUG("%s", s.c_str());
            }
        }
    }
    DEBUG("");
    DEBUG("You can reduce log size using --loglevel command line argument.");
}
