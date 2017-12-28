#ifndef MINIGOLF_UTIL_H
#define MINIGOLF_UTIL_H

#define PI 3.14159265
#include <math.h>

inline long double toRadians(float degrees)
{
    long double radians = degrees * (PI/180);
    return radians;
}

inline long double toDegrees(float radians)
{
    long double degrees = radians * (180/PI);
    return degrees;
}

#endif //MINIGOLF_UTIL_H
