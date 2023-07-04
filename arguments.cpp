#include "arguments.h"
#include <vector>
#include <memory.h>
#include "pack.h"

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
