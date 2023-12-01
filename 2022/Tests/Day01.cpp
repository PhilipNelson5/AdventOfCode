#include <catch2/catch_message.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "Day01.hpp"
#include "Utils.hpp"

TEST_CASE("Day01-1")
{
  const auto result{aoc::day01_1(aoc::readInput("Day01.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == 72718);
}

TEST_CASE("Day01-2")
{
  const auto result{aoc::day01_2(aoc::readInput("Day01.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == 213089);
}