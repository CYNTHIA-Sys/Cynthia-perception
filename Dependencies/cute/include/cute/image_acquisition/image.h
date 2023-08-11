/** @brief Retrieving and decoding images from the disk
 * @author Samer Ali
 * @data August 7, 2023
 **/

/*
	The MIT License (MIT)
	
	Copyright (c) 2014-2018 Omar Cornut
	
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:
	
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
 */

#define STB_IMAGE_IMPLEMENTATION
//#define STB_IMAGE_WRITE_IMPLEMENTATION


//#include "stb_image.h"
//#include "stb_image_write.h"
#include <cstdio>
#include <cstdlib>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <malloc/malloc.h>
#include <cute/utility.h>
#include <dirent.h>
#include <vector>
#include <cassert>
#include "filesystem"
#include "stb_image.h"


struct Image
{
	//	GLenum texture_internal_fmt;
	//	GLenum original_pixel_fmt;
	//	GLenum texture_data_t;
	//	GLenum original_data_t;
	GLuint texture;
	uint8_t* pixels { NULL };
	
	int texture_loaded { };
	
	int width;
	int height;
	int num_color_ch;
	//	int  num_mipmap_lvls;
	//
	//	bool flip_vertically;
	//	int  error_code;
	//	const char* error_msg;
};
void load_image ( Image* img ,
                  const char* path );
void free_image ( Image* img );
void reset_image ( Image* img );
void texture_image ( Image* img );
void reset_texture_image ( Image* img );


void load_image ( Image* img ,
                  const char* path )
{
	using namespace cute;
	if ( !cute::is_path( path ) )
		//		ERROR_EXIT( "Path does not exist. Unable to load image." );
		
		reset_image( img );
	img->pixels = stbi_load( path , &img->width , &img->height , &img->num_color_ch , RGBA );
	texture_image( img );
}


void free_image ( Image* img )
{
	if ( !img || !img->pixels )
		return;
	stbi_image_free( img->pixels );
	img->pixels = NULL;
}


void reset_image ( Image* img )
{
	free_image( img );
	reset_texture_image( img );
	img->width        = 0;
	img->height       = 0;
	img->num_color_ch = 0;
	//	img->texture_internal_fmt = GL_RGBA;
	//	img->texture_data_t       = GL_UNSIGNED_BYTE;
	//	img->num_mipmap_lvls      = 0;
	//	img->original_pixel_fmt   = GL_RGBA;
	//	img->original_data_t      = GL_UNSIGNED_BYTE;
	//	img->flip_vertically      = false;
	//	img->error_code           = 0;
	//	img->error_msg            = nullptr;
}


void texture_image ( Image* img )
{
	if ( img->pixels == NULL )
		assert( false && "Image data is NULL" );
	glGenTextures( 1 , &img->texture );
	glBindTexture( GL_TEXTURE_2D , img->texture );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR );
	
	glTexImage2D( GL_TEXTURE_2D , 0 , GL_RGBA , img->width , img->height , 0 , GL_RGBA , GL_UNSIGNED_BYTE ,
	              img->pixels );
	
	glGenerateMipmap( GL_TEXTURE_2D );
	img->texture_loaded = true;
}


void reset_texture_image ( Image* img )
{
	if ( img->texture_loaded )
		glDeleteTextures( 1 , &img->texture );
	img->texture_loaded = false;
}


