#include <catch2/catch_message.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "Day08.hpp"
#include "Utils.hpp"

TEST_CASE("Day08-1")
{
  const auto result{aoc::day08_1(aoc::readLines("Day08.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == 1827);
}

TEST_CASE("Day08-2")
{
  const auto result{aoc::day08_2(aoc::readLines("Day08.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == 335580);
}