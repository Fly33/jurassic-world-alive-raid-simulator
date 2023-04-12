#ifndef __INPUT__H__
#define __INPUT__H__

#include <vector>
#include "dino.h"
#include <memory>
#include "expression.h"
#include <list>
#include "pack.h"

struct Instruction
{
    std::unique_ptr<Expression> expression;
    std::vector<int> abilities;
    int success, failure;
};

struct Strategy
{
    std::vector<Instruction> instructions;
public:
    Strategy()
    {}
    std::vector<int> Next(const Dino team[], int team_size, int &offset) const;
};

int Input(std::vector<Dino> &team, Strategy &strategy);

#include "unpack.h"

#endif // __INPUT__H__
