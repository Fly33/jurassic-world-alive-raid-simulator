#ifndef __ARGUMENTS__H__
#define __ARGUMENTS__H__

#include <string>
#include <vector>
#include <getopt.h>

struct Argument {
    char letter;
    const char *word;
    int has_value;
    bool (*checker)(int argc, char *argv[], const char *value, void *data);
    void *data;
};

bool ParseArguments(int argc, char *argv[], const std::vector<Argument> &argument);

typedef struct {
    int argc;
    char **argv;
} arguments_t;

void SplitArgs(const char *str, arguments_t *args);
void FreeArgs(arguments_t *args);

#endif // __ARGUMENTS__H__
