#include "input.h"
#include <cstdio>
#include "dex.h"
#include "logger.h"
#include <string>
#include <cstring>
#include "expression.h"
#include <stdexcept>

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

string Strategy::ToPlainString() const
{
    string result;
    for (int k = 0; k < (int)instructions.size(); ++k) {
        result += strprintf("%3d ", k);
        if (instructions[k].expression.get()) {
            result += '?';
            result += instructions[k].expression->ToString();
        } else {
            for (int i = 0; i < (int)instructions[k].abilities.size(); ++i) {
                result += strprintf("%d", instructions[k].abilities[i]);
                if (i + 1 < (int)instructions[k].abilities.size())
                    result += ' ';
            }
        }
        result += strprintf(" %3d %3d\n", instructions[k].success, instructions[k].failure);
    }
    return result;
}

string Strategy::ToString(int indent, int begin, int end) const
{
    if (end == -1)
        end = (int)instructions.size();
    string result;
    int offset = begin;
    while (offset != end) {
//#ifdef DEBUG
//        result += strprintf("%3d ", offset);
//#endif
        for (int i = 0; i < indent; ++i)
            result += "  ";
        if (instructions[offset].expression.get()) {
            result += '?';
            result += instructions[offset].expression->ToString();
//#ifdef DEBUG
//            result += strprintf(" %3d %3d", instructions[offset].success, instructions[offset].failure);
//#endif
            result += "\n";
            result += ToString(indent+1, instructions[offset].success, instructions[offset].next);
            if (instructions[offset].failure != instructions[offset].next) {
//#ifdef DEBUG
//                result += "    ";
//#endif
                for (int i = 0; i < indent; ++i)
                    result += "  ";
                result += ":\n";
                result += ToString(indent+1, instructions[offset].failure, instructions[offset].next);
            }
            offset = instructions[offset].next;
        } else {
            for (int i = 0; i < (int)instructions[offset].abilities.size(); ++i) {
                result += strprintf("%d", instructions[offset].abilities[i]);
                if (i + 1 < (int)instructions[offset].abilities.size())
                    result += ' ';
            }
//#ifdef DEBUG
//            result += strprintf(" %3d %3d", instructions[offset].success, instructions[offset].failure);
//#endif
            result += '\n';
            offset = instructions[offset].next;
        }
    }
    return result;
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

struct Command
{
    int number;
    virtual ~Command() {}
    virtual bool IsMalformed() const { return false; }
    virtual vector<Instruction> GetInstructions(int next) const = 0;
    virtual int Enumerate(int index) = 0;
};

struct MalformedCommand : public Command
{
    std::string message;
    MalformedCommand(const std::string &_message)
        : message(_message)
    {}
    virtual ~MalformedCommand() {}
    virtual bool IsMalformed() const { return true; }
    virtual vector<Instruction> GetInstructions(int next) const override { return {}; }
    virtual int Enumerate(int index) override { return 0; }
};

struct Block : public Command
{
    vector<unique_ptr<Command>> commands;
    virtual ~Block() {}
    virtual int Enumerate(int index = 0) override
    {
        number = index;
        for (int i = 0; i < (int)commands.size(); ++i) {
            index = commands[i]->Enumerate(index);
        }
        return index;
    }
    virtual vector<Instruction> GetInstructions(int next) const override
    {
        vector<Instruction> result;
        for (int i = 0; i < (int)commands.size(); ++i) {
            auto instructions = commands[i]->GetInstructions(i+1 < (int)commands.size() ? commands[i+1]->number : next);
            for (auto &instruction: instructions)
                result.push_back(move(instruction));
        }
        return result;
    }
};

struct Condition : public Command
{
    unique_ptr<Expression> expression;
    unique_ptr<Command> success, failure;
    virtual ~Condition() {}
    virtual int Enumerate(int index) override
    {
        number = index++;
        index = success->Enumerate(index);
        if (failure.get())
            index = failure->Enumerate(index);
        return index;
    }
    virtual vector<Instruction> GetInstructions(int next) const override
    {
        vector<Instruction> result;
        Instruction condition;
        condition.expression = move(expression->Copy());
        condition.success = success->number;
        condition.failure = failure.get() ? failure->number : next;
        condition.next = next;
        result.push_back(move(condition));
        for (auto &instruction: success->GetInstructions(next))
            result.push_back(move(instruction));
        if (failure.get())
            for (auto &instruction: failure->GetInstructions(next))
                result.push_back(move(instruction));
        return result;
    }
};

struct Moveset : public Command
{
    vector<int> abilities;
    virtual ~Moveset() {}
    virtual int Enumerate(int index) override
    {
        number = index++;
        return index;
    }
    virtual vector<Instruction> GetInstructions(int next) const override
    {
        vector<Instruction> result;
        Instruction turn;
        turn.abilities = abilities;
        turn.success = next;
        turn.failure = next;
        turn.next = next;
        result.push_back(turn);
        return result;
    }
};

unique_ptr<Command> ParseMoveset(int team_size, const char *line, int offset)
{
    unique_ptr<Moveset> moveset(new Moveset);
    int n, ability;
    for (int j = 0; j < team_size + 2; ++j) {
        if (sscanf(line, "%d%n", &ability, &n) != 1) {
        	if (j < team_size)
        	    return unique_ptr<Command>(new MalformedCommand(strprintf("Expected a number near \"%.10s...\"", line)));
        	break;
        }
        if (4 < abs(ability))
            return unique_ptr<Command>(new MalformedCommand("Move should be between -4 and 4"));
        line += n;
        moveset->abilities.push_back(ability);
    }
    SkipWhite(line);
    if (*line != '\0')
        return unique_ptr<Command>(new MalformedCommand(strprintf("Invalid line format near \"%.10s...\"", line)));
    return moveset;
}

unique_ptr<Command> ParseBlock(int team_size, const string &indent, int offset);

unique_ptr<Command> ParseCondition(int team_size, const char *line, const string &indent, int offset)
{
    unique_ptr<Condition> result(new Condition);
    auto exp = ParseExpression(line);
    if (exp->IsMalformed())
        return unique_ptr<Command>(new MalformedCommand(exp->ToString()));
    result->expression = std::move(exp);

    auto curr_indent = GetIndent();
    if (curr_indent.length() <= indent.length() || curr_indent.substr(0, indent.length()) != indent)
        return unique_ptr<Command>(new MalformedCommand("Invalid indent"));
    UngetLine(curr_indent);

    auto success_block = ParseBlock(team_size, curr_indent, offset);
    if (success_block->IsMalformed())
        return success_block;
    result->success = std::move(success_block);

    curr_indent = GetIndent();
    if (curr_indent != indent) {
        UngetLine(curr_indent);
        return result;
    }
    auto ch = GetChar();
    if (ch != ':') {
        UngetChar(ch);
        UngetLine(curr_indent);
        return result;
    }

    auto curr_line = GetLine();
    if (*curr_line.c_str() == '?') {
        auto cond = ParseCondition(team_size, curr_line.c_str(), indent, offset);
        if (cond->IsMalformed())
            return cond;
        result->failure = std::move(cond);
    } else {
        const char *curr_line_str = curr_line.c_str();
        SkipWhite(curr_line_str);
        if (*curr_line_str != '\0')
            return unique_ptr<Command>(new MalformedCommand(strprintf("Invalid line format near \"%.10s...\"", curr_line_str)));
        auto curr_indent = GetIndent();
        if (curr_indent.length() <= indent.length() || curr_indent.substr(0, indent.length()) != indent)
            return unique_ptr<Command>(new MalformedCommand("Invalid indent"));
        UngetLine(curr_indent);
        auto failure_block = ParseBlock(team_size, curr_indent, offset);
        if (failure_block->IsMalformed())
            return failure_block;
        result->failure = std::move(failure_block);
    }
    return result;
}

unique_ptr<Command> ParseLine(int team_size, const string &indent, int offset)
{
    auto curr_indent = GetIndent();
    if (curr_indent != indent) {
        if (indent.substr(0, curr_indent.length()) != curr_indent)
            return unique_ptr<Command>(new MalformedCommand("Invalid indent"));
        UngetLine(curr_indent);
        return {};
    }
    auto line = GetLine();
    if (*line.c_str() == '?') {
        return ParseCondition(team_size, line.c_str(), indent, offset);
    } else if (isdigit(*line.c_str())) {
        return ParseMoveset(team_size, line.c_str(), offset);
    } else if (*line.c_str() == '\n' && indent == "") {
        return {};
    } else
        return unique_ptr<Command>(new MalformedCommand(strprintf("Invalid line format near \"%.10s...\"", line.c_str())));
}

unique_ptr<Command> ParseBlock(int team_size, const string &indent, int offset)
{
    unique_ptr<Block> result(new Block());
    while (true) {
        auto line = ParseLine(team_size, indent, offset);
        if (line.get() == nullptr)
            return result;
        if (line->IsMalformed())
            return line;
        result->commands.push_back(std::move(line));
    }
}

static int ReportError(const std::string &message)
{
    LOG("Error on line %d: %s", CurrLine, message.c_str());
    return CurrLine;
}

int Input(vector<Dino> &team, Strategy &strategy)
{
    int team_size, n_turns;
    char end[2];
    char boss[32];
    team.clear();
    if (sscanf(GetLine().c_str(), "%s%1s", boss, end) != 1)
        return ReportError("Expected boss name");
    auto boss_it = BossDex.find(boss);
    if (boss_it == BossDex.end())
        return ReportError(strprintf("Unable to find %s boss", boss));
    team.push_back(boss_it->second[0]);
    if (sscanf(GetLine().c_str(), "%d%d%1s", &team_size, &n_turns, end) != 2)
        return ReportError("Expected team size and number of turns");
    if (team_size < 1 || 4 < team_size)
        return ReportError("Invalid team size");
    if (n_turns < 0 || n_turns > 20)
        return ReportError("Invalid number of turns");
    for (int i = 0; i < team_size; ++i) {
        char dino[32];
        int level, health_boost, damage_boost, speed_boost;
        bool omega = false;
        int omega_health_points, omega_damage_points, omega_speed_points, omega_armor_points, omega_crit_chance_points, omega_crit_factor_points;
        auto line = GetLine();
        if (sscanf(line.c_str(), "%s%d%d%d%d%d%d%d%d%d%d%1s", dino, &level, &health_boost, &damage_boost, &speed_boost, &omega_health_points, &omega_damage_points, &omega_speed_points, &omega_armor_points, &omega_crit_chance_points, &omega_crit_factor_points, end) == 11) {
            omega = true;
        } else if (sscanf(line.c_str(), "%s%d%d%d%d%1s", dino, &level, &health_boost, &damage_boost, &speed_boost, end) != 5)
            return ReportError("Expected dino description");
        auto dino_it = DinoDex.find(dino);
        if (dino_it == DinoDex.end())
            return ReportError(strprintf("Unable to find %s", dino));
        if (level < 1 || 30 < level ||
            health_boost < 0 ||
            damage_boost < 0 ||
            speed_boost < 0)
            return ReportError("Invalid dino parameters");
        if (omega) {
            if (omega_health_points < 0 || omega_damage_points < 0 || omega_speed_points < 0 || omega_armor_points < 0 || omega_crit_chance_points < 0 || omega_crit_factor_points < 0)
                return ReportError("Invalid omega parameters");
        }
        if (omega)
            team.push_back(Dino(1, i+1, level, health_boost, damage_boost, speed_boost, omega_health_points, omega_damage_points, omega_speed_points, omega_armor_points, omega_crit_chance_points, omega_crit_factor_points, dino_it->second));
        else
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
                    return ReportError("Expected a number");
                if (ability[i][j] == 0 || 4 < abs(ability[i][j]))
                    return ReportError("Move should be between 1 and 4");
                offset += n;
            }
            if (sscanf(line.c_str() + offset, "%1s", end) == 1)
                return ReportError("Extra characters in line");
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
        auto block = ParseBlock(team_size, "", 0);
        if (block->IsMalformed())
            return ReportError(static_cast<MalformedCommand *>(block.get())->message);
        strategy.instructions = std::move(block->GetInstructions(block->Enumerate(0)));
    //    LOG(strategy.ToString().c_str());
    }
    return 0;
}

void MakeStrategy(const vector<vector<int>> &ability, Strategy &strategy)
{
    strategy.instructions.clear();
    int n_turns = 0;
    for (int j = 0; j < (int)ability.size(); ++j) {
        if (n_turns < (int)ability[j].size())
            n_turns = (int)ability[j].size();
    }
    for (int i = 0; i < n_turns; ++i) {
        Instruction instruction;
        for (int j = 0; j < (int)ability.size(); ++j)
            instruction.abilities.push_back(i < (int)ability[j].size() ? ability[j][i] : 0);
        instruction.failure = i + 1;
        instruction.success = i + 1;
        strategy.instructions.push_back(move(instruction));
    }
}
