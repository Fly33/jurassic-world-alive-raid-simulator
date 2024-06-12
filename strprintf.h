#ifndef __STRPRINTF__H__
#define __STRPRINTF__H__

#include <string>
#include <cstdarg>

std::string strprintf(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
std::string vstrprintf(const char *fmt, va_list va);

#endif // __STRPRINTF__H__
