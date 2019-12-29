#include <gtest/gtest.h>
#include "include/polish_calc.hpp"

TEST(PolishCalcTest, plusTest)
{
    std::string input{"5.0 2.0 +"};
    const auto & result = polish_calc::process(input);
    EXPECT_EQ("7", result);
}

TEST(PolishCalcTest, minusTest)
{
    std::string input{"5.0 2.0 -"};
    const auto & result = polish_calc::process(input);
    EXPECT_EQ("3", result);
}

TEST(PolishCalcTest, multTest)
{
    std::string input{"5.0 2.0 *"};
    const auto & result = polish_calc::process(input);
    EXPECT_EQ("10", result);
}

TEST(PolishCalcTest, divTest)
{
    std::string input{"5.0 2.0 /"};
    const auto & result = polish_calc::process(input);
    EXPECT_EQ("2.5", result);
}

TEST(PolishCalcTest, complexTest)
{
    std::string input{"15 7 1 1 + - / 3 * 2 1 1 + + -"};
    const auto & result = polish_calc::process(input);
    EXPECT_EQ("5", result);
}
//15 7 1 1 + − / 3 × 2 1 1 + + −


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
