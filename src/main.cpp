#include <iostream>
#include <string>

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
const float MAX_DEPTH = 1000.0f;

struct pixel
{
    unsigned char r, g, b;
};

float sdf_scene(vec3 ray)
{
    return sdf::sphere(ray, 1);
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
    float z = size.y * 2 * (1/tan(radians(fov)));
    return normalize({xy.x, xy.y, z});
}

int main(int argc, char** argv)
{
    const unsigned int width = 64;//atoi(argv[1]);
    const unsigned int height = 64;//atoi(argv[2]);

    pixel* pixels = (pixel*)malloc(sizeof(pixel)*width*height);
    vec3 eye = {0, 0, -1.1};
    int index = 0;
    for (int frame = 0; frame < 1; frame++)
    {
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                vec3 dir = ray_direction(65.0f, {(float)width, (float)height}, {(float)x, (float)y});

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
        index = 0;
        std::string filename = "out";
        filename.append(std::to_string(frame));
        filename.append(".bmp");

        stbi_write_bmp(filename.c_str(), width, height, 3, pixels);

        eye.x -= 0.1;
    }

    

    free(pixels);

    printf("complete.");
    
    return 0;
}