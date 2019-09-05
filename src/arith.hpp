#include "math.h"

struct vec2
{
    float x, y;
};

struct vec3
{
    float x, y, z;
};

vec2 operator-(vec2 lhs, vec2 rhs)
{
    return {lhs.x-rhs.x, lhs.y-rhs.y};
}

vec2 operator+(vec2 lhs, vec2 rhs)
{
    return {lhs.x+rhs.x, lhs.y+rhs.y};
}

vec2 operator*(vec2 lhs, float rhs)
{
    return {lhs.x*rhs, lhs.y*rhs};
}

vec2 operator*(float lhs, vec2 rhs)
{
    return {rhs.x*lhs, rhs.y*lhs};
}

vec3 operator-(vec3 lhs, vec3 rhs)
{
    return {lhs.x-rhs.x, lhs.y-rhs.y, lhs.z-rhs.z};
}

vec3 operator+(vec3 lhs, vec3 rhs)
{
    return {lhs.x+rhs.x, lhs.y+rhs.y, lhs.z+rhs.z};
}

vec3 operator*(vec3 lhs, float rhs)
{
    return {lhs.x*rhs, lhs.y*rhs, lhs.z*rhs};
}

vec3 operator*(float lhs, vec3 rhs)
{
    return {rhs.x*lhs, rhs.y*lhs, rhs.z*lhs};
}

float norm(vec2 v)
{
    return sqrt(v.x*v.x + v.y*v.y);
}

float norm(vec3 v)
{
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

float dot(vec3 v, vec3 u)
{
    return v.x*u.x + v.y*u.y + v.z*u.z;
}

float dot(vec2 v, vec2 u)
{
    return v.x*u.x + v.y*u.y;
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

