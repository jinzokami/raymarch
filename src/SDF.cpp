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
        vec2 pxz = {p.x, p.z};
        vec2 q = {norm(pxz) - t.x, p.y};
        return norm(q) - t.y;
    }

    float capped_torus(vec3 p, vec2 sc, float ra, float rb)
    {
        vec2 pxy = {p.x, p.y};
        p.x = abs(p.x);
        float k = (sc.y*p.x>sc.x*p.y) ? dot(pxy, sc) : norm(pxy);
        return sqrt(dot(p, p) + ra*ra - 2.0*ra*k) - rb;
    }
};