#include "string.h"
#include "stdint.h"

#include "stb_image.h"

int main(int argc, char** argv)
{
    const unsigned int width = atoi(argv[1]);
    const unsigned int height = atoi(argv[2]);

    char* pixels = (char*)malloc(sizeof(char)*width*height);

    free(pixels);
    
    return 0;
}