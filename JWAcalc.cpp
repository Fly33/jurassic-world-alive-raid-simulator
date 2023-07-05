#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstring>
#include <cctype>
#include <regex>
#include <cmath>
#include "dino.h"
#include "actions.h"
#include "modifiers.h"
#include "logger.h"
#include "dex.h"
#include "input.h"
#include "stats.h"
#include "arguments.h"
#include "pack.h"

using namespace std;


bool SpeedCmp(const Dino &dino1, const Dino &dino2) {
    if (dino1.stun < dino2.stun)
        return true;
    if (dino1.stun > dino2.stun)
        return false;
    if (dino1.priority > dino2.priority)
        return true;
    if (dino1.priority < dino2.priority)
        return false;
    if (dino1.Speed() > dino2.Speed())
        return true;
    if (dino1.Speed() < dino2.Speed())
        return false;
    if (dino1.level > dino2.level)
        return true;
    if (dino1.level < dino2.level)
        return false;
    if (dino1.kind->rarity > dino2.kind->rarity)
        return true;
    if (dino1.kind->rarity < dino2.kind->rarity)
        return false;
    if (dino1.minor < dino2.minor)
        return true;
    if (dino1.minor > dino2.minor)
        return false;
    if ((!dino1.minor && dino1.index < dino2.index) ||
        (dino1.minor && dino1.index > dino2.index))
        return true;
//    if ((!dino1.minor && dino1.index > dino2.index) ||
//        (dino1.minor && dino1.index < dino2.index))
//        return false;
    return false;
}

int Step(Dino team[], int team_size)
{
    int i;
    Dino *boss = team;
    Dino *dino[team_size], *counter_team[team_size];
    for (i = 0; i < team_size; ++i) {
        dino[i] = &team[i];
        counter_team[i] = &team[i];
    }
    for (int j = 0; j < team_size; ++j) {
        for (i = team_size - 1; i - 1 >= j; --i) { // Oh, yeah, this is bubble sort :)
            if (SpeedCmp(*dino[i], *dino[i-1]))
                swap(dino[i-1], dino[i]);
        }
        if (!dino[j]->Alive())
            continue;
        dino[j]->Attack(team, team_size);
        for (int k = 0; k < team_size; ++k) {
            for (i = team_size - 1; i - 1 >= k; --i) { // Oh, yeah, this is bubble sort again
                if (SpeedCmp(*counter_team[i], *counter_team[i-1]))
                    swap(counter_team[i-1], counter_team[i]);
            }
            counter_team[k]->CounterAttack(team, team_size);
        }
        for (i = 0; i < team_size; ++i) {
            if (team[i].team == 0)
                continue;
            if (team[i].Alive())
                break;
        }
        if (i == team_size)
            return -1;
        if (!boss->Alive())
            return 1;
    }
    for (i = 0; i < team_size; ++i) {
        if (team[i].Alive())
            team[i].DamageOverTime(team, team_size);
    }
    for (i = 0; i < team_size; ++i) {
        if (team[i].team == 0)
            continue;
        if (team[i].Alive())
            break;
    }
    if (i == team_size)
        return -1;
    if (!boss->Alive())
        return 1;
    for (i = 0; i < team_size; ++i) {
        if (team[i].Alive())
            team[i].DevourHeal();
    }
    for (i = 0; i < team_size; ++i) {
        team[i].PassTurn();
    }
    if (boss->health == 0) {
        ++boss->round;
        boss->turn = 0;
        for (i = 0; i < team_size; ++i) {
            if (team[i].team != 0)
                continue;
            team[i].Revive(i != 0);
        }
    } else {
        ++boss->turn;
    }
    return 0;
}

bool Check(Dino team[], int team_size, const Strategy &strategy)
{
    int round = 0;
    Dino &boss = *team;
    int offset = 0;
    while (true) {
        if (round < boss.round + 1) {
            ++round;
            ERROR("Round %d", round);
        }
        ERROR("Turn %d", boss.turn+1);
        if (boss.stats)
            boss.stats->NextTurn(boss.round, boss.turn);
        auto ability = strategy.Next(team, team_size, offset);
        if (ability.size() == 0)
            break;
        for (int i = 0; i < team_size; ++i) {
            if (!team[i].Alive())
                continue;
            if (i == 0)
                boss.Prepare(boss.turn % (int)boss->ability.size());
            else {
                int ability_id = i-1 < (int)ability.size() ? ability[i-1] : 0;
                if (ability_id != 0) {
                    bool minor = ability_id < 0;
                    ability_id = abs(ability[i-1])-1;
                    if (!team[i].Prepare(ability_id, minor)) {
                        ERROR("%s Can't use %s because of cooldown", team[i].Name().c_str(), team[i]->ability[ability_id]->name.c_str());
                        return false;
                    }
                } else {
                    while (!team[i].Prepare(rand() % team[i]->ability.size()))
                        ;
                }
            }
            WARNING("%s chose %s (%d)", team[i].Name().c_str(), team[i]->ability[team[i].ability_id]->name.c_str(), team[i].ability_id + 1);
        }

        int result = Step(team, team_size);
        if (result == 0)
            continue;
        if (result == 1)
            ERROR("Win!");
        else
            ERROR("Defeat!");
        return result == 1;
    }
    ERROR("You are out of turns!");
    return false;
}

int Chance(Dino team0[], int team_size, const Strategy &strategy, int n_checks = 1000)
{
    int result = 0;
    auto log = Logger::level;
    Logger::level = 0;
    Stats stats(team_size);
    for (int i = 0; i < n_checks; ++i) {
        vector<Dino> team(team0, team0 + team_size);
        for (int j = 0; j < (int)team.size(); ++j)
            team[j].stats = &stats;
        bool win = Check(team.data(), team_size, strategy);
        stats.RegisterResult(win);
        if (win)
            ++result;
    }
    Logger::level = log;
    stats.Print(team0, team_size);
    return 100 * result / n_checks;
}

string Explain(Dino team0[], int team_size, const Strategy &strategy, bool win, int n_checks = 1000)
{
    for (int i = 0; i < n_checks; ++i) {
        Logger::SetBuf();
        vector<Dino> team(team0, team0 + team_size);
        if (Check(team.data(), team_size, strategy) == win)
            return move(Logger::TakeBuf());
        Logger::TakeBuf();
    }
    if (win)
        return "Always fail";
    return "Always succeed";
}

//int FindAll(Dino boss[], int boss_size, Dino team[], int team_size, int max_turns)
//{
//    ;
//}
//
//int Find(Dino team[], int team_size, int max_turns, int turn = 0, int teammate_id = 0)
//{
//    if (teammate_id == 0) { // boss
//        Dino boss = *team;
//        team->Prepare(team->turn % (int)team->kind->ability[team->round].size());
//        int r = Find(team, team_size, max_turns, turn, teammate_id + 1);
//        *team = boss;
//        return r;
//    } else if (team[teammate_id] == 1) { // teammate
//        if (!team[teammate_id].Alive())
//            return Find(team, team_size, max_turns, turn, teammate_id + 1);
//        for (int i = 0; i < (int)team[teammate_id].kind->ability[team[teammate_id].round].size(); ++i) {
//            if (!team[teammate_id].Prepare(i))
//                continue;
//            int r = Find(
//        }
//    }
//}

bool SetLogLevel(int, char *[], const char *loglevel, void *)
{
    if (sscanf(loglevel, "%d", &Logger::level) != 1) {
        LOG("--loglevel takes a number from 0 to 4");
        return false;
    }
    return true;
}

bool SetInt(int, char *[], const char *value, void *out)
{
    if (sscanf(value, "%d", (int *)out) != 1) {
        LOG("Argumet should be integer");
        return false;
    }
    return true;
}

bool SetBool(int, char *[], const char *, void *out)
{
    *(bool *)out = true;
    return true;
}

bool CheckInput(int argc, char *argv[], const char *filename, void *)
{
    if (filename) {
        if (freopen(filename, "r", stdin) == NULL) {
            LOG("File \"%s\" is not found.", filename);
            return false;
        }
    }
    vector<Argument> arguments = {
        {'l', "loglevel", required_argument, SetLogLevel, nullptr}
    };
    if (!ParseArguments(argc, argv, arguments))
        return false;
    Strategy strategy;
    vector<Dino> team;
    if (int line = Input(team, strategy)) {
        LOG("Input error in line %d!", line);
        return false;
    }
    Check(team.data(), (int)team.size(), strategy);
    return false;
}

bool ChanceInput(int argc, char *argv[], const char *filename, void *)
{
    if (filename) {
        if (freopen(filename, "r", stdin) == NULL) {
            LOG("File \"%s\" is not found.", filename);
            return false;
        }
    }
    int n_checks = 1000;
    vector<Argument> arguments = {
        {'l', "loglevel", required_argument, SetLogLevel, nullptr},
        {'n', "n-checks", required_argument, SetInt, &n_checks}
    };
    if (!ParseArguments(argc, argv, arguments))
        return false;
    Strategy strategy;
    vector<Dino> team;
    if (int line = Input(team, strategy)) {
        LOG("Input error in line %d!", line);
        return -1;
    }
    Chance(team.data(), (int)team.size(), strategy, n_checks);
    return false;
}

bool ExplainInput(int argc, char *argv[], const char *filename, void *)
{
    if (filename) {
        if (freopen(filename, "r", stdin) == NULL) {
            LOG("File \"%s\" is not found.", filename);
            return false;
        }
    }
    bool win = false;
    int n_checks = 1000;
    vector<Argument> arguments = {
        {'l', "loglevel", required_argument, SetLogLevel, nullptr},
        {'n', "n-checks", required_argument, SetInt, &n_checks},
        {'w', "win", no_argument, SetBool, &win}
    };
    if (!ParseArguments(argc, argv, arguments))
        return false;
    Strategy strategy;
    vector<Dino> team;
    if (int line = Input(team, strategy)) {
        LOG("Input error in line %d!", line);
        return -1;
    }
    string result = Explain(team.data(), (int)team.size(), strategy, win, n_checks);
    LOG("%s", result.c_str());
    return false;
}

bool Help(int, char *[], const char *optarg, void *)
{
    if (optarg != nullptr && (strcmp(optarg, "check") == 0 || strcmp(optarg, "chance") == 0 || strcmp(optarg, "explain") == 0)) {
        printf(R"--(Usage: JWAcalc --%s [file] [-w|--win] [-n|--n-checks <number_of_checks>] [-l|--loglevel <loglevel>]

Options:
        -l, --loglevel <loglevel>   Change the default log level to <loglevel>. It can be a number from 0 to 4.
        -n, --n-checks              (chance and explain only) The number of checks. (default: 1000)
        -w, --win                   (explain only) It searches for a won battle. (If it is missed it searches for a lost
                                    battle.)

Checks a strategy from input or <file> if specified. The strategy has the following format:
        <boss_name>
        <n_teammates> <n_turns>
        <teammate_1_name> <teammate_1_level> <teammate_1_health_boost> <teammate_1_damage_boost> <teammate_1_speed_boost>
        ...
        <teammate_N_name> <teammate_N_level> <teammate_N_health_boost> <teammate_N_damage_boost> <teammate_N_speed_boost>
        <teammate_1_turn_1_move> ... <teammate_1_turn_M_move>
        ...
        <teammate_N_turn_1_move> ... <teammate_N_turn_M_move>

A move is a number from -4 to 4. Positive value means an ability number. 0 means a random ability. Negative value manages
the move order of the dinos with equal speed. If two or more dinos have completely equal speed (equal speed, level and
rarity), those with the positive move act first from top to bottom, then those with the negative move act from bottom to
top.

Also there is alternarive format:
        <boss_name>
        <n_teammates> 0
        <teammate_1_name> <teammate_1_level> <teammate_1_health_boost> <teammate_1_damage_boost> <teammate_1_speed_boost>
        ...
        <teammate_N_name> <teammate_N_level> <teammate_N_health_boost> <teammate_N_damage_boost> <teammate_N_speed_boost>
        <block>

<block> ::=
        <line_1>
        ...
        <line_N>
The indent of all lines in the block must be the same.

<line> ::=
        <teammate_1_turn_X_move> ... <teammate_N_turn_X_move> [<minion_1_turn_X_move> [minion_2_turn_X_move]]
OR
        ?<condition>
        <indent><block>
        [:?<other_condition>
        <indent><block>
        ...
        [:
        <indent><block>]...]

<condition> ::= logical expression using operations ||, &&, <, <=, >, >=, ==, !=, +, -, *, /, !, + (unary), - (unary)
        over numbers and integer variables in the form <property>[<index>], where <index> is:
            0 - boss
            1..4 - teammates
            5..6 - minions (depends on the number of teammates you have)
        Properties are:
            health
            damage
            speed
            damage_factor (in percents)
            speed_factor (in percents)
            shield (in percents)
            dodge_chance (in percents)
            dodge_factor (in percents)
            alive
            cloak_factor (in percents)
            crit_chance (in percents)
            taunt
            max_health
            total_health
            max_total_health
            vulnerability (in percents)
            devour_heal
            damage_over_time
            stun
All properties are calculated at the beginning of the turn.
        )--", optarg);
    } else {
        printf(R"--(Usage: JWAcalc <options>

Options:
        -h, --help [command]    this help;
        --check [file]          checks a strategy from input or <file> if specified;
        --chance [file]         calculates a chance of winning using a strategy from input or <file> if specified;
        --explain [file]        prints a log of a won/lost battle using a strategy from input or <file> if specified;
        -l, --list [regexp]     prints a list of available bosses and dinos which meets a match criteria.
        )--");
    }
    return false;
}

bool List(int, char *[], const char *regexp, void *)
{
    regex r(regexp ? regexp : "", regex_constants::icase);
    smatch sm;
    LOG("Bossdex:");
    for (auto it = BossDex.begin(); it != BossDex.end(); ++it) {
        if (!regex_search(it->first, sm, r))
            continue;
        LOG("  %s", it->first.c_str());
    }
    LOG("");
    LOG("Dinodex:");
    for (auto it = DinoDex.begin(); it != DinoDex.end(); ++it) {
        if (!regex_search(it->first, sm, r))
            continue;
        LOG("  %s", it->first.c_str());
    }
    return false;
}

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
#ifdef DEBUG
    setbuf(stdout, NULL);
#endif

    vector<Argument> arguments = {
        {'c', "check", optional_argument, CheckInput, nullptr},
        {'p', "chance", optional_argument, ChanceInput, nullptr},
        {'e', "explain", optional_argument, ExplainInput, nullptr},
        {'l', "list", optional_argument, List, nullptr},
        {'h', "help", optional_argument, Help, nullptr},
        {':', nullptr, no_argument, Help, nullptr},
        {'?', nullptr, no_argument, Help, nullptr}
    };
    ParseArguments(argc, argv, arguments);
    return 0;
}
