/** @brief Retrieving images from the disk
 * @author Samer Ali
 * @data August 7, 2023
**/

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <malloc/malloc.h>

#define RGBA 4

struct Image
{
    uint8_t* pixels { NULL };
    GLuint texture;
    int texture_loaded {};
    int width;
    int height;
    int num_color_ch;
};


void free_image(Image* img) {

    // Validate input
    if(!img || !img->pixels) return;

    // Free pixel data
    stbi_image_free(img->pixels);

    // Clear pointer
    img->pixels = NULL;

    // Reset other fields
    img->width = 0;
    img->height = 0;
    img->num_color_ch = 0;

}

void reset_image(Image* img) {

    // Free existing pixel data if present
    if(img->pixels) {
        stbi_image_free(img->pixels);
        img->pixels = NULL;
    }

    // Delete texture if present
    if(img->texture_loaded) {
        glDeleteTextures(1, &img->texture);
        img->texture_loaded = false;
    }

    // Reset other fields
    img->width = 0;
    img->height = 0;
    img->num_color_ch = 0;

}

void texture_image(Image* img) {

    // Generate texture handle
    glGenTextures(1, &img->texture);

    // Bind the texture
    glBindTexture(GL_TEXTURE_2D, img->texture);

    // Set filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload pixel data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->width, img->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, img->pixels);

    // Set flag indicating texture is available
    img->texture_loaded = true;

}