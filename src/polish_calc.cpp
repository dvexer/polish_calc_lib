#include "include/polish_calc.hpp"
#include "include/polish_calc_exceptions.hpp"
#include <set>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>

namespace polish_calc {

static const std::string plus = "+";
static const std::string minus = "-";
static const std::string multiply = "*";
static const std::string divide = "/";

std::vector<std::string> parceInput(const std::string &input) {
    std::istringstream iss(input);
    std::vector<std::string> all_args(std::istream_iterator<std::string>{iss},
                                      std::istream_iterator<std::string>());
    return all_args;
}

bool isOperator(const std::string &arg)
{
    const std::set<std::string> operators{plus, minus, multiply, divide};
    return operators.find(arg) != operators.end();
}

void applyOperation(const std::string &operation, std::vector<double> &operands) {
    constexpr unsigned min_operands_size = 2;
    if (operands.size() >= min_operands_size) {
        double result = 0;
        const double second_operand = operands.back();
        operands.pop_back();
        const double first_operand = operands.back();
        operands.pop_back();
        if (operation == plus) {
            result = first_operand + second_operand;
        } else if (operation == minus) {
            result = first_operand - second_operand;
        } else if (operation == multiply) {
            result = first_operand * second_operand;
        } else if (operation == divide) {
            result = first_operand / second_operand;
        } else {
            throw InvalidOpertionException();
        }
        operands.push_back(result);
    } else {
        throw InvalidOperandsException();
    }
}

std::vector<double> processArguments(const std::vector<std::string> &args)
{
    std::vector<double> operands;
    for (const auto & arg : args) {
        if (isOperator(arg)) {
            applyOperation(arg, operands);
        } else {
            operands.push_back(std::stod(arg));
        }
    }
    return operands;
}

std::string toString(const std::vector<double> & input)
{
    std::string result;
    for (const double & item : input) {
        std::string str = std::to_string (item);
        str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
        str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
        result += str;
        result += ' ';
    }
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}

std::string process(const std::string &input)
{
    const std::vector<std::string> & args = parceInput(input);
    try {
        const std::vector<double> intermediateResult = processArguments(args);
        return toString(intermediateResult);
    } catch (const std::invalid_argument & e) {
        throw InvalidOpertionException();
    }
}

}   // polish_calc_lib
