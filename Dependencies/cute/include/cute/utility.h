/*
 * @author: Samer Ali
 * @desc: utility toolkit extension library for C++ std utility lib
 */
#ifndef CUTE_CORE_HPP
#define CUTE_CORE_HPP
#include <cstdint>
#include <utility>
#include <type_traits>
#include <algorithm>
namespace cute {

    enum class Option : int {
        CUTE_KEY_ESCAPE = 256
    };
    enum class State : int
    {
        CUTE_CONFIG_KEY_INPUT = 0
    };
    //empty struct. used for template types that are not necessary
    struct empty {};


    namespace details {
        template<typename T>
        using has_assign_op =
                decltype(std::declval<T &>() = std::declval<T const &>());
    }

    template<typename T>
    struct has_assign_operator : std::integral_constant<bool,
            !std::is_void<details::has_assign_op<T>>::value> {};

//    int64_t ceil(long long n)
//    {
//        uint8_t sign {n > 0};
//        int64_t whole_n {n};
//        return sign ?
//               (n > whole_n ? whole_n + 1 : whole_n) :
//               (n < whole_n ? whole_n - 1 : whole_n);
//    }

    inline int64_t floor(long long n)
        {return static_cast<int64_t>(n); }


    template<typename T>
    inline std::enable_if_t<!has_assign_operator<T>::value, T&>
    genericAssign(T& to, T&& rhs)
        {return  to = std::move(rhs);}

//    template<typename T>
//    auto genericAssign(T& to, T&& rhs) -> std::enable_if_t<!has_assign_operator<T>::value, T&>
//    {
//        auto old = std::exchange(to, std::forward<T>(rhs));
//        if(&old != &rhs)
//            std::exchange(to, old);
//        return to;
//    }
}
#endif // CUTE_CORE_HPP