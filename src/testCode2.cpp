#include <cynthia-perception/core.h>


int test ( int i )
{
	return i;
}


template < typename T >
static T invert2 ( T t )
{
	size_t size = sizeof( T );
	T      inverted;
}


int main ( int ,
           char** )
{
	glfwSetErrorCallback( cute::error_callback );
	if ( !glfwInit() )
	{
		return 1;
	}
	
	//! OpenGL version 3
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR , 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR , 3 );
	glfwWindowHint( GLFW_OPENGL_PROFILE , GLFW_OPENGL_CORE_PROFILE );
	//! For Mac Users
	glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT , GLFW_TRUE );
	
	//! Create Window and init glad
	GLFWwindow* window = glfwCreateWindow( 800 , 600 , "Increment" , NULL , NULL );
	glfwMakeContextCurrent( window );
	gladLoadGLLoader( ( GLADloadproc ) glfwGetProcAddress );
	
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	//    ImGuiIO &io = ImGui::GetIO();
	
	//! Setup ImGui binding
	ImGui_ImplGlfw_InitForOpenGL( window , true );
	ImGui_ImplOpenGL3_Init( "#version 400" );
	ImGui::StyleColorsDark();
	std::unique_ptr< cy::Image > img = cy::im_load< cy::Vec< cy_uchar >>( "/users/samer.ali/images/lena.jpg" , RGBA ,
	                                                                      cy::INVERT );
	//cy::im_show( img );
	return 0;
}