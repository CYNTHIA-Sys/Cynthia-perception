#include <iostream>
#include <glad/glad.h> //*** must include before GLFW header files
// GLAD will provide use with the necessary specifications to a driver that
// the graphics card supports
#include <GLFW/glfw3.h>
#include <useful_guards//compatibility.h>
#include <useful_guards/text/color.h>
#include <unistd.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow *window);

int main(int, char**)
{


    static const char t_red[] = { 0x1b, '[', '0', ';', '3', '1', ';', '5', '9', 'm', 0 };

    std::cout << t_red <<  "this is red text" << std::endl;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    /* setting the GLFW_OPENGL_PROFILE to core tells glfw that we want to have access
     * to a smaller subset of opengl features without backwards compatible features that are no
     * longer needed.
    */
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // this is a must for apple products in order to set core profile
    if(IS_APPLE_SILICON)
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello, world!", NULL, NULL);
    if(window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    while(!glfwWindowShouldClose(window))
    {
//        process_input(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    { glViewport(0, 0, width, height); }

void process_input(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}