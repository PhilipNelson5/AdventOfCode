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
  inline auto allUnique(const std::string_view s, const uint start, const int n)
  {
    for (auto j{start}; j < start + n; ++j)
    {
      for (auto k{j + 1}; k < start + n; ++k)
      {
        if (s[j] == s[k])
        {
          return false;
        }
      }
    }
    return true;
  }

  inline auto day06_1(const std::string_view input)
  {
    constexpr int n{4};
    for (auto i{0u}; i < input.size() - 1 - n; ++i)
    {
      if (allUnique(input, i, n))
      {
        return i + n;
      }
    }
    return 1u;
  }

  inline auto day06_2(const std::string_view input)
  {
    constexpr int n{14};
    for (auto i{0u}; i < input.size() - 1 - n; ++i)
    {
      if (allUnique(input, i, n))
      {
        return i + n;
      }
    }
    return 1u;
  }
} // namespace aoc
