#include <catch2/catch_message.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "Day05.hpp"
#include "Utils.hpp"

TEST_CASE("Day05-1")
{
  const auto result{aoc::day05_1(aoc::readLines("Day05.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == "TLNGFGMFN");
}

TEST_CASE("Day05-2")
{
  const auto result{aoc::day05_2(aoc::readLines("Day05.txt"))};
  std::cout << result << std::endl;
  REQUIRE(result == "FGLQJCMBD");
}