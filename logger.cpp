#include "logger.h"
#include "strprintf.h"
#include <utility>
#include <cstdio>
#include <cstdarg>

int Logger::level = LOG_LEVEL_DEBUG;
bool Logger::buffered = false;
std::string Logger::buf;

int Logger::Log(const char fmt[], ...)
{
    va_list va;
    va_start(va, fmt);
    int r = 0;
    if (buffered) {
        buf += vstrprintf(fmt, va);
        buf += '\n';
    } else {
        r = vprintf(fmt, va);
        putchar('\n');
    }
    va_end(va);
    return r;
}

void Logger::SetBuf()
{
    buffered = true;
    buf.clear();
}

std::string Logger::TakeBuf()
{
    buffered = false;
    return std::move(buf);
}
