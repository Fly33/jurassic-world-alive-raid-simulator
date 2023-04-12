#include "strprintf.h"
#include <cstdio>
#include <errno.h>
#include <vector>
#include <string>
#include "pack.h"

using namespace std;

string vstrprintf(const char *fmt, va_list va)
{
    string result;

    va_list copy;
    va_copy(copy, va);
    int r = vsnprintf(nullptr, 0, fmt, copy);
    va_end(copy);

    if (r < 0)
        return "";

    result.resize(r);

    r = vsnprintf(result.data(), result.size() + 1, fmt, va);
    if (r < 0)
        return "";
    return result;

}

string strprintf(const char *fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    auto r = vstrprintf(fmt, va);
    va_end(va);
    return r;
}
