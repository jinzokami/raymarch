#include "string.h"
#include "stdint.h"
#include "stdlib.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

struct pixel
{
    unsigned char r, g, b;
};

int main(int argc, char** argv)
{
    const unsigned int width = 1024;//atoi(argv[1]);
    const unsigned int height = 1024;//atoi(argv[2]);

    pixel* pixels = (pixel*)malloc(sizeof(pixel)*width*height);

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            pixels[(y * width + (x % width))] = {x, 0, 255-x};
        }
    }

    stbi_write_bmp("out.bmp", width, height, 3, pixels);

    free(pixels);

    printf("complete.");
    
    return 0;
}