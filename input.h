#ifndef __INPUT__H__
#define __INPUT__H__

#include <vector>
#include <string>
#include "dino.h"
#include <memory>
#include "expression.h"
#include <list>

struct Instruction
{
    std::unique_ptr<Expression> expression;
    std::vector<int> abilities;
    int success, failure, next;
    Instruction()
        : success(0)
        , failure(0)
        , next(0)
    {}
    Instruction(const Instruction &instruction)
        : expression(instruction.expression.get() ? instruction.expression->Copy() : nullptr)
        , abilities(instruction.abilities)
        , success(instruction.success)
        , failure(instruction.failure)
        , next(instruction.next)
    {}
    Instruction(Instruction &&instruction) = default;
};

struct Strategy
{
    std::vector<Instruction> instructions;
public:
    Strategy()
    {}
    std::vector<int> Next(const Dino team[], int team_size, int &offset) const;
    std::string ToPlainString() const;
    std::string ToString(int indent = 0, int begin = 0, int end = -1) const;
};

int Input(std::vector<Dino> &team, Strategy &strategy);
void MakeStrategy(const std::vector<std::vector<int>> &ability, Strategy &strategy);

#endif // __INPUT__H__
