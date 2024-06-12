#include "arguments.h"
#include <getopt.h>
#include <vector>
#include <memory.h>
#include "pack.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>


using namespace std;

bool ParseArguments(int argc, char *argv[], const vector<Argument> &argument)
{
    vector<option> options;
    string control;
    int index[256];
    memset(index, -1, sizeof(index));
    for (int i = 0; i < (int)argument.size(); ++i) {
        if (argument[i].letter != '\0') {
            control += argument[i].letter;
            if (argument[i].has_value != no_argument)
                control += ':';
            if (argument[i].has_value == optional_argument)
                control += ':';
            index[(unsigned char)argument[i].letter] = i;
        }
        options.push_back({argument[i].word, argument[i].has_value, nullptr, 0});
    }
    options.push_back({nullptr, 0, nullptr, 0});

    while (true) {
        int i;
        int res = getopt_long(argc, argv, control.c_str(), options.data(), &i);
        if (res == -1)
            break;
        if (res != 0) {
            if ((res == '?' || res == ':') && index[res] == -1)
                return false;
            i = index[res];
        }
        if (argument[i].has_value == optional_argument && optarg == nullptr && argv[optind] != nullptr && argv[optind][0] != '-')
            optarg = argv[optind++];
        if (!argument[i].checker(argc, argv, optarg, argument[i].data))
            return false;
    }
    return true;
}

void SplitArgs(const char *str, arguments_t *args)
{
    if (args == NULL)
        return;

    int length = strlen(str);
    char *buffer = (char *)malloc(length + 1);
    char *current = buffer;
    args->argc = 0;
    int inQuotes = 0;
    const char *p = str;

    while (*p) {
        if (*p == '\"') {
            inQuotes = !inQuotes;
            p++;
        } else if (*p == '\\' && *(p + 1)) {
            *current++ = *(++p);
            p++;
        } else if (!inQuotes && isspace((unsigned char)*p)) {
            if (current != buffer && *(current - 1) != '\0') {
                *current++ = '\0';
                args->argc++;
            }
            p++;
        } else {
            *current++ = *p++;
        }
    }
    if (current != buffer && *(current - 1) != '\0') {
        args->argc++;
    }
    *current = '\0'; // Null-terminate the last argument

    // Выделение памяти для argv
    args->argv = (char **)malloc(args->argc * sizeof(char *));
    current = buffer;
    for (int i = 0; i < args->argc; ++i) {
        args->argv[i] = current;
        current += strlen(current) + 1;
    }

    --args->argc;
}

void FreeArgs(arguments_t *args)
{
    if (args == NULL)
        return;

    free(args->argv[0]); // Освобождаем блок памяти, выделенный под строки
    free(args->argv);    // Освобождаем блок памяти, выделенный под указатели
    args->argv = NULL;
    args->argc = 0;
}
