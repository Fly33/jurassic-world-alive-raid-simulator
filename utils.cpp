#include "utils.h"
#include <random>
#include "pack.h"

using namespace std;

static random_device rd;
static mt19937 gen;

void Srand()
{
    gen.seed(rd());
}

int Rand(int n)
{
    return (int)(gen() % n);
}
