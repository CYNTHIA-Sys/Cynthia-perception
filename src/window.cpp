#include "graphics/window.h"


char cy::mat::create_window ()
{
	
	glfwInit();
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR ,
	                3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR ,
	                3 );
	
	/** setting the GLFW_OPENGL_PROFILE to core tells glfw that we want to have access
	 * to a smaller subset of opengl features without backwards compatible features that are no
	 * longer needed.
	*/
	
	glfwWindowHint( GLFW_OPENGL_PROFILE ,
	                GLFW_OPENGL_CORE_PROFILE );
	
	// this is a must for apple products in order to set core profile
	if ( IS_APPLE_SILICON )
		glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT ,
		                GL_TRUE );
	
	_window = glfwCreateWindow( width ,
	                            height ,
	                            window_title ,
	                            NULL ,
	                            NULL );
	if ( _window == NULL )
	{
		std::cout << t_red << "Failed to create GLFW window" << t_normal << std::endl;
		glfwTerminate();
		return 0;
	}
	glfwMakeContextCurrent( _window );
	if ( !gladLoadGLLoader( ( GLADloadproc ) glfwGetProcAddress ) )
	{
		std::cout << t_red << "Failed to initialize GLAD" << t_normal << std::endl;
		return 0;
	}
	glViewport( 0 ,
	            0 ,
	            800 ,
	            600 );
	glfwSetFramebufferSizeCallback( _window ,
	                                framebuffer_size_callback );
	return 1;
}


int cy::mat::show_im ()
{
	while ( !glfwWindowShouldClose( _window ) )
	{
		cy::mat::call_configs( cy::mat::get_num_configs() );
		glfwSwapBuffers( _window );
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

//void cy::mat::window_configure(void (*funcptr)(), cute::Option option)
//{
//
//}