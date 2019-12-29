#ifndef POLISH_CALC_POLISH_CALC_EXCEPTIONS_HPP
#define POLISH_CALC_POLISH_CALC_EXCEPTIONS_HPP

#include <exception>
#include <string>

namespace polish_calc {

class InvalidOperandsNumberException : public std::exception
{
    const char * what () const noexcept override;
};

class InvalidOperandException : public std::exception
{
public:
    explicit InvalidOperandException(std::string  operand);
    const char * what () const noexcept override;

private:
    const std::string operand_;
};

}   // polish_calc_lib

#endif //POLISH_CALC_POLISH_CALC_EXCEPTIONS_HPP
