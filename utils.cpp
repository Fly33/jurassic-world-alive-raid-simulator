#include "utils.h"
#include <random>
#include <limits>
#include <cstdint>
#include "pack.h"

using namespace std;

static random_device rd;
static mt19937_64 gen;

void Srand()
{
    gen.seed(rd());
}

int Rand(int n)
{
    return (int)(gen() % n);
}

__int128 Rand128(__int128 n)
{
    return (__int128)(gen() % n);
}

std::string ToString(__int128 x)
{
    std::string result;
    const int mod = 1'000'000'000;
    while (x >= mod) {
        result = strprintf("%09d", (int)(x % mod)) + result;
        x /= mod;
    }
    result += strprintf("%d", (int)x) + result;
    return result;
}

__int128 Mlt(__int128 a, __int128 z, __int128 m)
{
    if (a < numeric_limits<int64_t>::max() && z < numeric_limits<int64_t>::max())
        return a * z % m;
    // Schrage's method
    __int128 q = m / a;
    __int128 r = m % a;
    a *= (z % q);
    if (r <= q)
        r *= (z / q);
    else
        r = Mlt(r, z / q, m);
    if (a >= r)
        return a - r;
    return (m - r) + a;
}

