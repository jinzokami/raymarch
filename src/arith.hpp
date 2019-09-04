#include "math.h"

struct vec2
{
    float x, y, z;
};

struct vec3
{
    float x, y, z;
};

vec3 operator-(vec3 lhs, vec3 rhs)
{
    return {lhs.x-rhs.x, lhs.y-rhs.y, lhs.z-rhs.z};
}

float norm(vec3 v)
{
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

vec3 max(vec3 v, float s)
{
    return {fmax(v.x, s), fmax(v.y, s), fmax(v.z, s)};
}

vec3 max(float s, vec3 v)
{
    return {fmax(v.x, s), fmax(v.y, s), fmax(v.z, s)};
}

vec3 min(vec3 v, float s)
{
    return {fmin(v.x, s), fmin(v.y, s), fmin(v.z, s)};
}

vec3 min(float s, vec3 v)
{
    return {fmin(v.x, s), fmin(v.y, s), fmin(v.z, s)};
}

vec3 abs(vec3 v)
{
    return {abs(v.x), abs(v.y), abs(v.z)};
}