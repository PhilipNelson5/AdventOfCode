#include <catch2/catch_message.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "Day06.hpp"
#include "Utils.hpp"

TEST_CASE("Day06-1")
{
  const auto result{aoc::day06_1(aoc::readInput("Day06.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == 1034);
}

TEST_CASE("Day06-2")
{
  const auto result{aoc::day06_2(aoc::readInput("Day06.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == 2472);
}