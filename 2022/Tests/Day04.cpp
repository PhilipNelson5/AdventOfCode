#include <catch2/catch_message.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "Day04.hpp"
#include "Utils.hpp"

TEST_CASE("Day04-1")
{
  const auto result{aoc::day04_1(aoc::readInput("Day04.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == 569);
}

TEST_CASE("Day04-2")
{
  const auto result{aoc::day04_2(aoc::readInput("Day04.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == 936);
}