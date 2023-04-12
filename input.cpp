#include "input.h"
#include <cstdio>
#include "dex.h"
#include "logger.h"
#include <string>
#include <cstring>
#include "expression.h"
#include <stdexcept>
#include "pack.h"

using namespace std;

vector<int> Strategy::Next(const Dino team[], int team_size, int &offset) const
{
    while (offset < (int)instructions.size()) {
        auto &instruction = instructions[offset];
        if (!instruction.expression.get()) {
            offset = instruction.success;
            return instruction.abilities;
        } else if (instruction.expression->Calc(team, team_size)) {
            offset = instruction.success;
        } else {
            offset = instruction.failure;
        }
    }
    return {};
}

static int CurrLine = 1;
static int NewLine = 1;

inline int GetChar()
{
    int ch = getchar();
    CurrLine = NewLine;
    if (ch == '\n')
        ++NewLine;
    return ch;
}

inline void UngetChar(int ch)
{
    if (ch == '\n')
        CurrLine = --NewLine;
    ungetc(ch, stdin);
}

string GetLine()
{
    string line;
    while(true) {
        int c = GetChar();
        if (c == '\n' || c == -1)
            break;
        line.push_back(c);
    }
    line.push_back('\n');
    return line;
}

string GetIndent()
{
    string line;
    int c;
    while(true) {
        c = GetChar();
        if (!isspace(c) || c == '\n' || c == -1)
            break;
        line.push_back(c);
    }
    if (c != -1)
        UngetChar(c);
    return line;
}

void UngetLine(const string &str)
{
    for (auto i = str.rbegin(); i != str.rend(); ++i)
        UngetChar(*i);
}

Instruction ParseInstruction(int team_size, const char *line, int offset)
{
    Instruction instruction;
    int n, ability;
    for (int j = 0; j < team_size; ++j) {
        if (sscanf(line, "%d%n", &ability, &n) != 1)
            throw invalid_argument(strprintf("Expected a number near \"%.10s...\"", line));
        if (ability == 0 || 4 < abs(ability))
            throw invalid_argument("Move should be between 1 and 4");
        line += n;
        instruction.abilities.push_back(ability);
    }
    SkipWhite(line);
    if (*line != '\0')
        throw invalid_argument(strprintf("Invalid line format near \"%.10s...\"", line));
    instruction.success = offset+1;
    instruction.failure = offset+1;
    return instruction;
}

vector<Instruction> ParseBlock(int team_size, const string &indent, int offset);

vector<Instruction> ParseCondition(int team_size, const char *line, const string &indent, int offset)
{
    vector<Instruction> result;
    Instruction instruction;
    instruction.expression = move(ParseExpression(line));
    instruction.success = instruction.failure = ++offset;
    result.push_back(move(instruction));

    auto curr_indent = GetIndent();
    if (curr_indent.length() <= indent.length() || curr_indent.substr(0, indent.length()) != indent)
        throw invalid_argument("Invalid indent");
    UngetLine(curr_indent);

    auto success_block = ParseBlock(team_size, curr_indent, offset);
    offset += success_block.size();
    result.front().failure += success_block.size();
    for (auto it = success_block.begin(); it != success_block.end(); ++it)
        result.push_back(move(*it));

    curr_indent = GetIndent();
    if (curr_indent != indent) {
        UngetLine(indent);
        return result;
    }
    auto ch = GetChar();
    if (ch != ':') {
        UngetChar(ch);
        UngetLine(indent);
        return result;
    }

    auto curr_line = GetLine();
    if (*curr_line.c_str() == '?') {
        auto failure_block = move(ParseCondition(team_size, curr_line.c_str(), indent, offset));
        result.back().success += failure_block.size();
        result.back().failure += failure_block.size();
        for (auto it = failure_block.begin(); it != failure_block.end(); ++it)
            result.push_back(move(*it));
    } else {
        const char *curr_line_str = curr_line.c_str();
        SkipWhite(curr_line_str);
        if (*curr_line_str != '\0')
            throw invalid_argument(strprintf("Invalid line format near \"%.10s...\"", curr_line_str));
        auto curr_indent = GetIndent();
        if (curr_indent.length() <= indent.length() || curr_indent.substr(0, indent.length()) != indent)
            throw invalid_argument("Invalid indent");
        UngetLine(curr_indent);
        auto failure_block = move(ParseBlock(team_size, curr_indent, offset));
        result.back().success += failure_block.size();
        result.back().failure += failure_block.size();
        for (auto it = failure_block.begin(); it != failure_block.end(); ++it)
            result.push_back(move(*it));
    }
    return result;
}

vector<Instruction> ParseLine(int team_size, const string &indent, int offset)
{
    auto curr_indent = GetIndent();
    if (curr_indent != indent) {
        if (indent.substr(0, curr_indent.length()) != curr_indent)
            throw invalid_argument("Invalid indent");
        return {};
    }
    auto line = GetLine();
    if (*line.c_str() == '?') {
        return move(ParseCondition(team_size, line.c_str(), indent, offset));
    } else if (isdigit(*line.c_str())) {
        vector<Instruction> result;
        result.push_back(move(ParseInstruction(team_size, line.c_str(), offset)));
        return result;
    } else if (*line.c_str() == '\n' && indent == "") {
        return {};
    } else
        throw invalid_argument(strprintf("Invalid line format near \"%.10s...\"", line.c_str()));
}

vector<Instruction> ParseBlock(int team_size, const string &indent, int offset)
{
    vector<Instruction> result;
    while (true) {
        auto line = ParseLine(team_size, indent, offset);
        if (line.size() == 0)
            return result;
        offset += line.size();
        for (auto line_it = line.begin(); line_it != line.end(); ++line_it)
            result.push_back(move(*line_it));
    }
}

Strategy ParseStrategy(int team_size)
{
    Strategy strategy;
    strategy.instructions = move(ParseBlock(team_size, "", 0));
    return strategy;
}

int Input(vector<Dino> &team, Strategy &strategy)
{
    int team_size, n_turns;
    char end[2];
    char boss[32];
    team.clear();
    try {
        if (sscanf(GetLine().c_str(), "%s%1s", boss, end) != 1)
            throw invalid_argument("Expected boss name");
        auto boss_it = BossDex.find(boss);
        if (boss_it == BossDex.end())
            throw invalid_argument(strprintf("Unable to find %s boss", boss));
        team.push_back(boss_it->second[0]);
        if (sscanf(GetLine().c_str(), "%d%d%1s", &team_size, &n_turns, end) != 2)
            throw invalid_argument("Expected team size and number of turns");
        if (team_size < 1 || 4 < team_size)
            throw invalid_argument("Invalid team size");
        if (n_turns < 0 || n_turns > 20)
            throw invalid_argument("Invalid number of turns");
        for (int i = 0; i < team_size; ++i) {
            char dino[32];
            int level, health_boost, damage_boost, speed_boost;
            if (sscanf(GetLine().c_str(), "%s%d%d%d%d%1s", dino, &level, &health_boost, &damage_boost, &speed_boost, end) != 5)
                throw invalid_argument("Expected dino description");
            auto dino_it = DinoDex.find(dino);
            if (dino_it == DinoDex.end())
                throw invalid_argument(strprintf("Unable to find %s", dino));
            if (level < 1 || 30 < level ||
                health_boost < 0 ||
                damage_boost < 0 ||
                speed_boost < 0)
                throw invalid_argument("Invalid dino parameters");
            team.push_back(Dino(1, i+1, level, health_boost, damage_boost, speed_boost, dino_it->second));
        }
        for (int i = 1; i < (int)boss_it->second.size(); ++i)
            team.push_back(boss_it->second[i]);
        if (n_turns != 0) {
            vector<vector<int>> ability;
            for (int i = 0; i < team_size; ++i) {
                ability.emplace_back(n_turns);
                int offset = 0, n;
                auto line = GetLine();
                for (int j = 0; j < n_turns; ++j) {
                    if (sscanf(line.c_str() + offset, "%d%n", &ability[i][j], &n) != 1)
                        throw invalid_argument("Expected a number");
                    if (ability[i][j] == 0 || 4 < abs(ability[i][j]))
                        throw invalid_argument("Move should be between 1 and 4");
                    offset += n;
                }
                if (sscanf(line.c_str() + offset, "%1s", end) == 1)
                    throw invalid_argument("Extra characters in line");
            }
            strategy.instructions.clear();
            for (int i = 0; i < n_turns; ++i) {
                Instruction instruction;
                for (int j = 0; j < team_size; ++j)
                    instruction.abilities.push_back(ability[j][i]);
                instruction.failure = i + 1;
                instruction.success = i + 1;
                strategy.instructions.push_back(move(instruction));
            }
        } else {
            strategy = move(ParseStrategy(team_size));
        }
    } catch(exception &e) {
        LOG("Error on line %d: %s", CurrLine, e.what());
        return CurrLine;
    }
    return 0;
}
