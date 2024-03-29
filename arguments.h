#ifndef __ARGUMENTS__H__
#define __ARGUMENTS__H__

#include <string>
#include <vector>
#include <getopt.h>
#include "pack.h"

struct Argument {
    char letter;
    const char *word;
    int has_value;
    bool (*checker)(int argc, char *argv[], const char *value, void *data);
    void *data;
};

bool ParseArguments(int argc, char *argv[], const std::vector<Argument> &argument);

#include "unpack.h"

#endif // __ARGUMENTS__H__
