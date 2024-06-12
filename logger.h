#ifndef __LOGGER__H__
#define __LOGGER__H__

#include <string>

enum {
    LOG_LEVEL_NONE = 0,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_INFO,
    LOG_LEVEL_DEBUG,
};

class Logger
{
    static std::string buf;
    static bool buffered;
public:
    static int level;
    static int Log(const char fmt[], ...) __attribute__((format(printf, 1, 2)));
    static void SetBuf();
    static std::string TakeBuf();
};

#pragma GCC diagnostic ignored "-Wformat-zero-length"

#define LOG(...) (Logger::Log(__VA_ARGS__))
#define ERROR(...) (Logger::level >= LOG_LEVEL_ERROR ? Logger::Log(__VA_ARGS__) : 0)
#define WARNING(...) (Logger::level >= LOG_LEVEL_WARNING ? Logger::Log(__VA_ARGS__) : 0)
#define INFO(...) (Logger::level >= LOG_LEVEL_INFO ? Logger::Log(__VA_ARGS__) : 0)
#define DEBUG(...) (Logger::level >= LOG_LEVEL_DEBUG ? Logger::Log(__VA_ARGS__) : 0)

#endif // __LOGGER__H__
