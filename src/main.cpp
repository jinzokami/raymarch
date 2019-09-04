#include "string.h"
#include "stdint.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int argc, char** argv)
{
    const unsigned int width = atoi(argv[1]);
    const unsigned int height = atoi(argv[2]);

    char* pixels = (char*)malloc(sizeof(char)*3*width*height);

    for (int i = 0; i < 3*width*height; i+=3)
    {
        pixels[i] = 255;
        pixels[i+1] = 255;
        pixels[i+2] = 255;
    }

    stbi_write_bmp("out.bmp", width, height, 3, pixels);

    free(pixels);
    
    return 0;
}