#ifndef GRAPHICS_WINDOW_H
#define GRAPHICS_WINDOW_H
#include <iostream>
#include <glad/glad.h> //*** must include before GLFW header files
// GLAD will provide use with the necessary specifications to a driver that
// the graphics card supports
#include <GLFW/glfw3.h>
#include <useful_guards/compatibility.h>
#include <useful_guards/text/color.h>
#include <unistd.h>
#include <utility>
#include <cute/utility.h>
#include <vector>

namespace cy {
    class mat {
    public:
        mat(const char* _window_title, int _width, int _height) :
        window_title(_window_title), width(_width), height(_height) {}

        void window_configure(cute::State state, cute::Option option);

        template<size_t... Idx>
        inline void call_configs(std::index_sequence<Idx...>)
        {
            (std::get<Idx>(configs)(),...);
        }
        int run();


        char create_window();
        constexpr auto get_num_configs(){return std::make_index_sequence<numConfigs>();}
        std::vector<std::function<void()>> get_configs(){return configs;}
    private:
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height) { glViewport(0, 0, width, height); }

        void process_input(GLFWwindow *window) {
            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(window, true);
        }
        void addConfig(void (*config)() )
        {
            configs.emplace_back(config);
        }
    private:

        using ConfigFunc = void (*)();
        const char* window_title;
        int width;
        int height;
        std::vector<std::function<void()>> configs;
        static constexpr int numConfigs {0};
        GLFWwindow* _window;
    };
}
#endif // End GRAPHICS_WINDOW_H