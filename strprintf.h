#ifndef __STRPRINTF__H__
#define __STRPRINTF__H__

#include <string>
#include <cstdarg>
#include "pack.h"

std::string strprintf(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
std::string vstrprintf(const char *fmt, va_list va);

#include "unpack.h"

#endif // __STRPRINTF__H__
