#ifndef POLISH_CALC_POLISH_CALC_EXCEPTIONS_HPP
#define POLISH_CALC_POLISH_CALC_EXCEPTIONS_HPP
#include <exception>

namespace polish_calc {

struct InvalidOperandsException : public std::exception
{
    const char * what () const throw () {
        return "Invalid operands number";
    }
};

struct InvalidOpertionException : public std::exception
{
    const char * what () const throw () {
        return "Invalid operation";
    }
};

}   // polish_calc_lib

#endif //POLISH_CALC_POLISH_CALC_EXCEPTIONS_HPP
