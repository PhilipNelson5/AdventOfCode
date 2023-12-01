#pragma once

#include "Utils.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

namespace aoc
{
  inline auto day01_1(const std::string_view input)
  {
    namespace views = std::views;
    using namespace std::string_literals;

    /* clang-format off */
    auto calories =
      input
        | views::split("\n\n"s)
        | views::transform([=](auto elf) {
          return elf
            | views::split("\n"s)
            | views::transform([](auto val)  -> int{
              return std::stoi(std::string{val.begin(), val.end()});
            });
        }) | views::transform([](auto elf) {
          return std::accumulate(elf.begin(), elf.end(), 0);
        });
    /* clang-format on */
    return *std::max_element(calories.begin(), calories.end());
  }

  inline auto day01_2(const std::string_view input)
  {
    namespace views = std::views;
    using namespace std::string_literals;

    /* clang-format off */
    auto calories =
      input
        | views::split("\n\n"s)
        | views::transform([=](auto elf) {
          return elf
            | views::split("\n"s)
            | views::transform([](auto val)  -> int{
              return std::stoi(std::string{val.begin(), val.end()});
            });
        }) | views::transform([](auto elf) {
          return std::accumulate(elf.begin(), elf.end(), 0);
        }) | to<std::vector<int>>();
    /* clang-format on */
    std::partial_sort(
      calories.begin(), calories.begin() + 3, calories.end(), std::greater<>());
    return std::accumulate(calories.begin(), calories.begin() + 3, 0);
  }
} // namespace aoc
