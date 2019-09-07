#include "string.h"
#include "stdint.h"
#include "stdlib.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "arith.hpp"
#include "SDF.hpp"

const float EPSILON = 0.0001f;
const float MIN_DEPTH = 0.0f;
const float MAX_DEPTH = 100.0f;

struct pixel
{
    unsigned char r, g, b;
};

float sdf_scene(vec3 ray)
{
    return sdf::sphere(ray, 10.9);
}

float shortest_distance(vec3 eye, vec3 viewRayDirection, float start, float end)
{
    float depth = start;
    for (int i = 0; i < 255; i++)
    {
        float dist = sdf_scene(eye + depth * viewRayDirection);
        if (dist < EPSILON)
        {
            return depth;
        }

        depth += dist;

        if (depth >= end)
        {
            return end;
        }
    }
    return end;
}

vec3 ray_direction(float fov, vec2 size, vec2 coord)
{
    vec2 xy = coord - (size * 0.5);
    float z = size.y * 0.5 * (1/tan(radians(fov)));
    return normalize({xy.x, xy.y, -z});
}

int main(int argc, char** argv)
{
    const unsigned int width = 256;//atoi(argv[1]);
    const unsigned int height = 256;//atoi(argv[2]);

    pixel* pixels = (pixel*)malloc(sizeof(pixel)*width*height);

    int index = 0;
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            vec3 eye = {0, 0, -11};
            vec3 dir = ray_direction(45.0f, {width, height}, {x, y});

            float depth = shortest_distance(eye, dir, MIN_DEPTH, MAX_DEPTH);
            if(depth > MAX_DEPTH - EPSILON)
            {
                pixels[index] = {0, 0, 0};
            }
            else
            {
                pixels[index] = {255, 0, 0};
            }
            index++;
        }
    }

    stbi_write_bmp("out.bmp", width, height, 3, pixels);

    free(pixels);

    printf("complete.");
    
    return 0;
}