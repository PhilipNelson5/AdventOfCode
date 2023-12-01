#pragma once

#include "Utils.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <tuple>
#include <vector>

namespace aoc
{
  inline auto parse(const std::string_view input)
  {
    namespace views = std::views;
    using namespace std::string_literals;

    /* clang-format off */
    return input | views::split("\n"s)
    | views::transform([](auto line){
        return line | views::split(","s) | views::transform([](auto range){
          return range | views::split("-"s) | views::transform([](auto val){
            return std::stoi(std::string{val.begin(), val.end()});
          }) | to<std::vector<int>>();
        }) | to<std::vector<std::vector<int>>>();
      }) | to<std::vector<std::vector<std::vector<int>>>>();
    /* clang-format on */
  }

  inline auto rangeContained(const std::vector<int>& a,
                             const std::vector<int>& b)
  {
    return a[0] <= b[0] && a[1] >= b[1];
  }
  inline auto rangeContained(const std::vector<std::vector<int>>& ranges)
  {
    const auto& a = ranges[0];
    const auto& b = ranges[1];
    return rangeContained(a, b) || rangeContained(b, a);
  }
  inline auto day04_1(const std::string_view input)
  {
    const auto parsed{parse(input)};
    return std::count_if(parsed.begin(),
                         parsed.end(),
                         [](const std::vector<std::vector<int>>& ranges) {
                           return rangeContained(ranges);
                         });
  }

  inline auto rangeOverlap(const std::vector<int>& a, const std::vector<int>& b)
  {
    return a[0] <= b[0] && a[1] >= b[0];
  }
  inline auto rangeOverlap(const std::vector<std::vector<int>>& ranges)
  {
    const auto& a = ranges[0];
    const auto& b = ranges[1];
    return rangeOverlap(a, b) || rangeOverlap(b, a);
  }
  inline auto day04_2(const std::string_view input)
  {
    const auto parsed{parse(input)};
    return std::count_if(parsed.begin(),
                         parsed.end(),
                         [](const std::vector<std::vector<int>>& ranges) {
                           return rangeOverlap(ranges);
                         });
  }
} // namespace aoc
