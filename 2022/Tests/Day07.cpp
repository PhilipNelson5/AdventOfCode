#include <catch2/catch_message.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "Day07.hpp"
#include "Utils.hpp"

TEST_CASE("Day07-1")
{
  const auto result{aoc::day07_1(aoc::readLines("Day07.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == 1084134);
}

TEST_CASE("Day07-2")
{
  const auto result{aoc::day07_2(aoc::readLines("Day07.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == 6183184);
}