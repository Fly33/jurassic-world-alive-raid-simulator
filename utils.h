#ifndef __UTILS__H__
#define __UTILS__H__

#include <cmath>

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

#endif // __UTILS__H__
