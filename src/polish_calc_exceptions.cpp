#include "include/polish_calc_exceptions.hpp"

#include <utility>

namespace polish_calc {

// InvalidOperandsNumberException
const char * InvalidOperandsNumberException::what() const noexcept {
    return "Invalid operands number";
}

// InvalidOperandException
InvalidOperandException::InvalidOperandException(std::string operand)
: operand_(std::move(operand))
{
}

const char * InvalidOperandException::what () const noexcept
{
    const std::string result = "Invalid operation: " + operand_;
    return result.c_str();
}

}   // polish_calc
