#ifndef __UTILS__H__
#define __UTILS__H__

#include <cmath>
#include <utility>
#include <chrono>
#include "strprintf.h"
#include "pack.h"

inline int Round(double x)
{
    return (int)floor(x + 0.500001);
}

inline double Norm(double x)
{
	if (x < 0)
		return 0;
	return x;
}

template<class T>
T GCD(T x, T y)
{
    while (true) {
        x %= y;
        if (x == 0)
            return y;
        std::swap<T>(x, y);
    }
}

__int128 Mlt(__int128 x, __int128 y, __int128 mod);

void Srand();
int Rand(int n);
__int128 Rand128(__int128 n);

std::string ToString(__int128 x);

template<typename Duration>
std::string ToString(const Duration &d)
{
    std::string result;
    auto hours = std::chrono::duration_cast<std::chrono::hours>(d);
    if (hours.count() != 0)
        result += strprintf("%dh", (int)hours.count());
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(d);
    if (result.size() > 0) {
        result += strprintf("%02dm", (int)minutes.count() % 60);
        return result;
    } else if (minutes.count() != 0)
        result += strprintf("%dm", (int)minutes.count());
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(d);
    if (result.size() > 0) {
        result += strprintf("%02ds", (int)seconds.count() % 60);
        return result;
    } else if (seconds.count() != 0)
        result += strprintf("%ds", (int)seconds.count());
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(d);
    if (result.size() > 0) {
        result += strprintf("%03dms", (int)milliseconds.count() % 1000);
        return result;
    } else if (milliseconds.count() != 0)
        result += strprintf("%dms", (int)milliseconds.count());
//    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(d);
//    if (result.size() > 0) {
//        result += strprintf("%03dmcs", (int)microseconds.count() % 1000);
//        return result;
//    } else if (microseconds.count() != 0)
//        result += strprintf("%dmcs", (int)microseconds.count());
//    auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(d);
//    if (result.size() > 0) {
//        result += strprintf("%03dns", (int)nanoseconds.count() % 1000);
//        return result;
//    } else if (nanoseconds.count() != 0)
//        result += strprintf("%dns", (int)nanoseconds.count());
    return result;
}


#include "unpack.h"

#endif // __UTILS__H__
