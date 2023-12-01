#include <catch2/catch_message.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "Day02.hpp"
#include "Utils.hpp"

TEST_CASE("Day02-1")
{
  const auto result{aoc::day02_1(aoc::readLines("Day02.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == 10816);
}

TEST_CASE("Day02-2")
{
  const auto result{aoc::day02_2(aoc::readLines("Day02.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == 11657);
}