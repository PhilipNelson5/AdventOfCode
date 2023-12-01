#pragma once

#include "Utils.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

namespace aoc
{
  inline auto convert(char c)
  {
    if (c >= 'a')
      return c - 'a' + 1;
    return c - 'A' + 27;
  }
  inline auto findItem(const std::string_view sack)
  {
    const auto* mid
      = sack.begin() + std::distance(sack.begin(), sack.end()) / 2;
    const auto* pos = std::find_if(sack.begin(), mid, [&](const char c) {
      return std::find(mid, sack.end(), c) != sack.end();
    });
    return convert(*pos);
  }
  inline auto day03_1(const std::vector<std::string>& input)
  {
    std::vector<int> items;
    std::transform(
      input.begin(), input.end(), std::back_inserter(items), findItem);

    return std::accumulate(items.begin(), items.end(), 0);
  }

  inline auto group(const std::vector<std::string>& input)
  {
    constexpr int n{3};
    std::vector<std::vector<std::string_view>> output(input.size() / n);
    for (auto i{0u}; i < input.size() / n; ++i)
    {
      output[i].push_back(std::string_view{input[i * 3]});
      output[i].push_back(std::string_view{input[i * 3 + 1]});
      output[i].push_back(std::string_view{input[i * 3 + 2]});
    }
    return output;
  }
  inline auto findMatch(const std::vector<std::string_view>& group)
  {
    const auto* pos = std::find_if(
      group[0].begin(), group[0].end(), [&](const char c) {
        return std::find(group[1].begin(), group[1].end(), c) != group[1].end()
               && std::find(group[2].begin(), group[2].end(), c)
                    != group[2].end();
      });
    return convert(*pos);
  }
  inline auto day03_2(const std::vector<std::string>& input)
  {
    const auto groups = group(input);
    std::vector<int> items;
    std::transform(
      groups.begin(), groups.end(), std::back_inserter(items), findMatch);

    return std::accumulate(items.begin(), items.end(), 0);
  }
} // namespace aoc
