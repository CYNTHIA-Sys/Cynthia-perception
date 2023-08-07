#ifndef CUTE_DEBUG_HPP
#define CUTE_DEBUG_HPP
#include <iostream>
// debug functionality to output variable to console
namespace cute {
    #define DEBUG(my_var) std::cout << #my_var ": " << (my_var) << std::endl;
}
#endif CUTE_DEBUG_HPP