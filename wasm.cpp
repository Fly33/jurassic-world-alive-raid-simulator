#include <cstdio>
#include <cstdlib>
#include "arguments.h"

extern int main(int argc, char *argv[]);

extern "C" {

__attribute__((used)) int wasm_main(const char *str)
{
    arguments_t args;
    SplitArgs(str, &args);
    int ret = main(args.argc, args.argv);
    FreeArgs(&args);
    return ret;
}

} // extern "C"
