#include <catch2/catch_message.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "Day03.hpp"
#include "Utils.hpp"

TEST_CASE("Day03-1")
{
  const auto result{aoc::day03_1(aoc::readLines("Day03.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == 7811);
}

TEST_CASE("Day03-2")
{
  const auto result{aoc::day03_2(aoc::readLines("Day03.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == 2639);
}