#include <catch2/catch_message.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "Day09.hpp"
#include "Utils.hpp"

TEST_CASE("Day09-1")
{
  const auto result{aoc::day09_1(aoc::readLines("Day09.txt"))};
  std::cout << result << std::endl;
  // REQUIRE(result == 1827);
}

TEST_CASE("Day09-2")
{
  // const auto result{aoc::day09_2(aoc::readLines("Day09.txt"))};
  // std::cout << result << std::endl;
  // REQUIRE(result == 335580);
}