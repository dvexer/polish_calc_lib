#ifndef POLISH_CALC_POLISH_CALC_HPP
#define POLISH_CALC_POLISH_CALC_HPP

#include <string>

namespace polish_calc {
    /**
     * Calculates the result of Reverse Polish notation
     * @param input string written in Reverse Polish notation
     * @return result of applying operations to operands
     * @throws InvalidOperationException and InvalidOperandException
     */
    std::string process(const std::string &input);
}   // polish_calc_lib

#endif //POLISH_CALC_POLISH_CALC_HPP
