#include "cute/image_acquisition/image.h"
#include "cynthia-perception/core.h"
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <imgui/imgui.h>
#include <cute/utility.h>


int fs ( std::string& s ,
         std::string& cd ,
         const char* popup )
{
	static std::string current_dir = ".";
	if ( !ImGui::BeginPopup( popup ) )
		return -1;
	
	int                        sindex = -1;
	std::vector< std::string > dlist  = cute::directory_list( current_dir.c_str() , cute::FILES_AND_DIRECTORIES );
	ImGui::Text( "Files" );
	static ImGuiTextFilter filter;
	filter.Draw( "" );
	
	for ( int i = 0 ; i < dlist.size() ; i++ )
	{
		if ( filter.PassFilter( dlist[ i ].c_str() ) )
		{
			if ( ImGui::Selectable( dlist[ i ].c_str() ) )
			{
				if ( cute::is_directory( ( current_dir + "/" + dlist[ i ] ).c_str() ) )
				{
					current_dir += "/" + dlist[ i ];
					filter.Clear();
				} else
				{
					sindex = i;
					s      = dlist[ i ];
					filter.Clear();
				}
				cd = current_dir;
				break;
			}
		}
	}
	ImGui::EndPopup();
	if ( sindex == -1 )
		ImGui::OpenPopup( popup );
	
	return sindex;
}


//pops up the file list
std::string image_select ( int s )
{
	static std::vector< std::string > selected = { "" ,
	                                               "" };
	ImGui::SameLine();
	ImGui::Text( selected[ s ] == "" ? "<None>" : selected[ s ].c_str() );
	
	std::string current_dir;
	int         sindex;
	if ( s == 0 )
		sindex = fs( selected[ s ] , current_dir , "select 0" );
	else if ( s == 1 )
		sindex = fs( selected[ s ] , current_dir , "select 1" );
	
	if ( sindex == -1 )
		return "";
	else
		return current_dir + "/" + selected[ s ];
}

// std::string image_select() {
//     // Create a file dialog.
//     std::string filename;
//     ImGui::FileOpenDialog("Image Select", filename, "All Files (*.*);;Image
//     Files (*.png, *.jpg, *.jpeg)", ImGuiFileDialogFlags_NoChangeDir);
//
//     // If the user selected a file, return the filename.
//     if (ImGui::FileOpenDialog::IsOpened("Image Select")) {
//         return filename;
//     }
//
//     // If the user did not select a file, return an empty string.
//     return "";
// }

// std::string open_dialog() {
//     std::string filePath;
//
//     GLFWwindow* window = glfwGetCurrentContext();
//     if (window) {
//         // Open the file dialog
//         const char* selectedPath = glfwOpenWindowFile(window, "Open File",
//         nullptr, nullptr, nullptr);
//
//         if (selectedPath) {
//             // File selected
//             filePath = selectedPath;
//         }
//     } else {
//         // Unable to get the current GLFW context
//     }
//
//     return filePath;
// }

ImVec2 resize_ui ( int width ,
                   int height ,
                   int mul )
{
	return ImVec2( width * mul , height * mul );
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
	
	cy::Image img;
	ImVec2    dim( img.width , img.height );
	ImVec4    clear_color = ImColor( 144 , 144 , 154 );
	int       x           = 0;
	while ( !glfwWindowShouldClose( window ) )
	{
		glfwPollEvents();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		
		//		ImGui::Begin( "Slider Window" );
		//		if ( img.texture_loaded )
		//			ImGui::Image( ( void* ) img.texture , ImVec2( img.width , img.height ) );
		//		std::string tmp = "";
		//		if ( ImGui::Button( "Select Image" ) )
		//		{
		//			ImGui::OpenPopup( "select-0" );
		//			tmp = "/users/samer.ali/images/lena.jpg";
		//		}
		//
		//
		//
		//		if ( tmp != "" )
		//		{
		//			im_load( &img , tmp.c_str() , 4 );
		//			//			im_release( &img );
		//		}
		//		ImGui::End();
		//		ImGui::Begin( "Slider Window 2" );
		//		if ( img.texture_loaded )
		//			ImGui::Image( ( void* ) img.texture , ImVec2( img.width , img.height ) );
		//		std::string tmp2 = "";
		//		if ( ImGui::Button( "Select Image" ) )
		//		{
		//			ImGui::OpenPopup( "select-0" );
		//			tmp2 = "/users/samer.ali/images/lena.jpg";
		//		}
		//
		//
		//
		//		if ( tmp2 != "" )
		//		{
		//			im_load( &img , tmp2.c_str() , 4 );
		//			//			im_release( &img );
		//		}
		//		ImGui::End();
		
		
		int display_w , display_h;
		glfwGetFramebufferSize( window , &display_w , &display_h );
		glViewport( 0 , 0 , display_w , display_h );
		glClearColor( clear_color.x , clear_color.y , clear_color.z , clear_color.w );
		glClear( GL_COLOR_BUFFER_BIT );
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData( ImGui::GetDrawData() );
		glfwSwapBuffers( window );
	}
	
	//    while(!glfwWindowShouldClose(window))
	//    {
	//        glfwPollEvents();
	//        ImGui_ImplOpenGL3_NewFrame();
	//        ImGui_ImplGlfw_NewFrame();
	//        ImGui::NewFrame();
	//
	//        ImGui::Begin("counter");
	//        if (ImGui::Button("CLICK ME"))
	//            x++;
	//        ImGui::Text("X: %d", x);
	//        ImGui::End();
	//
	//        int display_w, display_h;
	//        glfwGetFramebufferSize(window, &display_w, &display_h);
	//
	//        glViewport(0, 0, display_w, display_h);
	//        glClearColor(clear_color.x, clear_color.y, clear_color.z,
	//        clear_color.w); glClear(GL_COLOR_BUFFER_BIT);
	//
	//        ImGui::Render();
	//        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	//        glfwSwapBuffers(window);
	//    }
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}
