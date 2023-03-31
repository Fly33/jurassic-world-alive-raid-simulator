#include <cstdio>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <string>
#include <list>
#include <ctime>
#include <cstring>
#include <getopt.h>
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
    Dino *boss = team;
    int offset = 0;
    while (true) {
        if (round < boss->round + 1) {
            ++round;
            ERROR("Round %d", round);
        }
        ERROR("Turn %d", boss->turn+1);
        Stats::NextTurn(boss->round, boss->turn);
        auto ability = strategy.Next(team, team_size, offset);
        if (ability.size() == 0)
            break;
        for (int i = 0; i < team_size; ++i) {
            if (!team[i].Alive())
                continue;
            if (i == 0)
                boss->Prepare(boss->turn % (int)boss->kind->ability[boss->round].size());
            else if (team[i].team == 1) { // Teammates
                bool minor = ability[i-1] < 0;
                int ability_id = abs(ability[i-1])-1;
                if (!team[i].Prepare(ability_id, minor)) {
                    ERROR("%s Can't use %s because of cooldown", team[i].Name().c_str(), team[i].Ability(ability_id)->name.c_str());
                    return false;
                }
            } else { // Minions
                while (!team[i].Prepare(rand() % team[i].kind->ability[team[i].round].size()))
                    ;
            }
            WARNING("%s chose %s", team[i].Name().c_str(), team[i].Ability(team[i].ability_id)->name.c_str());
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
    Stats::on = true;
    Stats::Init(team_size);
    for (int i = 0; i < n_checks; ++i) {
        vector<Dino> team(team0, team0 + team_size);
        bool win = Check(team.data(), team_size, strategy);
        Stats::RegisterResult(win);
        if (win)
            ++result;
    }
    Logger::level = log;
    Stats::Print(team0, team_size);
    return 100 * result / n_checks;
}

string Explain(Dino team0[], int team_size, const Strategy &strategy, int n_checks = 1000)
{
    for (int i = 0; i < n_checks; ++i) {
        Logger::SetBuf();
        vector<Dino> team(team0, team0 + team_size);
        if (!Check(team.data(), team_size, strategy))
            return move(Logger::TakeBuf());
        Logger::TakeBuf();
    }
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

int ProcessCommonArgs(int argc, char *argv[])
{
    while (true) {
        static struct option long_options[] = {
            {"loglevel", required_argument, nullptr, 'l'},
            {0, 0, 0, 0}
        };
        int option_index;

        switch (getopt_long(argc, argv, "l:", long_options, &option_index)) {
        case -1:
            break;
        case 'l':
            if (sscanf(optarg, "%d", &Logger::level) != 1) {
                LOG("--loglevel takes a number from 0 to 4");
                return -1;
            }
            continue;
        case '?':
            return -1;
        }
        break;
    }
    return 0;
}

int CheckInput(int argc, char *argv[])
{
    Strategy strategy;
    vector<Dino> team;
    ProcessCommonArgs(argc, argv);
    if (int line = Input(team, strategy)) {
        LOG("Input error in line %d!", line);
        return -1;
    }
    Check(team.data(), (int)team.size(), strategy);
    return 0;
}

int ChanceInput(int argc, char *argv[])
{
    Strategy strategy;
    vector<Dino> team;
    ProcessCommonArgs(argc, argv);
    if (int line = Input(team, strategy)) {
        LOG("Input error in line %d!", line);
        return -1;
    }
    Chance(team.data(), (int)team.size(), strategy);
    return 0;
}

int ExplainInput(int argc, char *argv[])
{
    Strategy strategy;
    vector<Dino> team;
    ProcessCommonArgs(argc, argv);
    if (int line = Input(team, strategy)) {
        LOG("Input error in line %d!", line);
        return -1;
    }
    string result = Explain(team.data(), (int)team.size(), strategy);
    LOG("%s", result.c_str());
    return 0;
}

int Help()
{
    if (optarg != nullptr && (strcmp(optarg, "check") == 0 || strcmp(optarg, "chance") == 0 || strcmp(optarg, "explain") == 0)) {
        printf(R"--(Usage: JWAcalc --%s [file] --loglevel <loglevel>

Options:
        -l, --loglevel <loglevel>   Change the default log level to <loglevel>. It can be a number from 0 to 4.

Checks a strategy from input or <file> if specified. The strategy has the following format:
        <boss_name>
        <n_teammates> <n_turns>
        <teammate_1_name> <teammate_1_level> <teammate_1_health_boost> <teammate_1_damage_boost> <teammate_1_speed_boost>
        ...
        <teammate_N_name> <teammate_N_level> <teammate_N_health_boost> <teammate_N_damage_boost> <teammate_N_speed_boost>
        <teammate_1_turn_1_move> ... <teammate_1_turn_M_move>
        ...
        <teammate_N_turn_1_move> ... <teammate_N_turn_M_move>

A move is a number from 1 to 4. But it can be negative to manage the move order of the dinos with equal speed.
If two or more dinos have completely equal speed (equal speed, level and rarity), those with the positive move
act first from top to bottom, then those with the negative move act from bottom to top.

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
        <teammate_1_turn_X_move> ... <teammate_N_turn_X_move>
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
        --explain [file]        prints a log of a lost battle using a strategy from input or <file> if specified;
        -l, --list [regexp]     prints a list of available bosses and dinos which meets a match criteria.
        )--");
    }
    return 0;
}

int List(const char *regexp)
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
    return 0;
}

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
#ifdef DEBUG
    setbuf(stdout, NULL);
#endif

    while (true) {
        static struct option long_options[] = {
            {"check", optional_argument, nullptr, 'c'},
            {"chance", optional_argument, nullptr, 'p'},
            {"explain", optional_argument, nullptr, 'e'},
            {"help", optional_argument, nullptr, 'h'},
            {"list", optional_argument, nullptr, 'l'},
            {0, 0, 0, 0}
        };
        int option_index;

        switch (getopt_long(argc, argv, "h::l", long_options, &option_index)) {
        case -1:
            return 0;
        case 'c':
            if(optarg == nullptr && argv[optind] != nullptr && argv[optind][0] != '-')
                optarg = argv[optind++];
            if (optarg)
                freopen(optarg, "r", stdin);
            return CheckInput(argc, argv);
        case 'p':
            if(optarg == nullptr && argv[optind] != nullptr && argv[optind][0] != '-')
                optarg = argv[optind++];
            if (optarg)
                freopen(optarg, "r", stdin);
            return ChanceInput(argc, argv);
        case 'e':
            if(optarg == nullptr && argv[optind] != nullptr && argv[optind][0] != '-')
                optarg = argv[optind++];
            if (optarg)
                freopen(optarg, "r", stdin);
            return ExplainInput(argc, argv);
        case '?':
        case 'h':
            if(optarg == nullptr && argv[optind] != nullptr && argv[optind][0] != '-')
                optarg = argv[optind++];
            return Help();
        case 'l':
            if(optarg == nullptr && argv[optind] != nullptr && argv[optind][0] != '-')
                optarg = argv[optind++];
            return List(optarg);
        }
    }
    return 0;
}
