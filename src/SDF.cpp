#include "arith.hpp"

namespace sdf
{
    float sphere(vec3 p, float s)
    {
        return norm(p) - s;
    }

    float box(vec3 p, vec3 b)
    {
        vec3 d = abs(p) - b;
        return norm(max(d, 0.0)) + fmin(fmax(d.x, fmax(d.y, d.z)), 0.0);
    }

    float rounded_box(vec3 p, vec3 b, float r)
    {
        vec3 d = abs(p) - b;
        return norm(max(d, 0.0)) - r + fmin(fmax(d.x, fmax(d.y, d.z)), 0.0);
    }

    float torus(vec3 p, vec2 t)
    {
        
    }
};