#pragma once

#include "Utils.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

namespace aoc
{
  inline auto next(const int i, const int range) { return (i + 1) % range; }

  inline auto prev(const int i, const int range)
  {
    return (i + range - 1) % range;
  }

  inline auto getScore(const std::vector<int>& pair)
  {
    constexpr int WIN{6};
    constexpr int DRAW{3};
    constexpr int LOSE{0};
    if (pair[1] == pair[0])
    {
      return DRAW;
    }
    if (next(pair[0], 3) == pair[1])
    {
      return WIN;
    }
    return LOSE;
  }
  inline auto day02_1(const std::vector<std::string>& input)
  {
    std::vector<std::vector<std::string_view>> parsed;
    std::transform(std::begin(input),
                   std::end(input),
                   std::back_inserter(parsed),
                   [](const std::string& s) { return split(s, ' '); });
    std::vector<std::vector<int>> diff;
    std::transform(
      std::begin(parsed),
      std::end(parsed),
      std::back_inserter(diff),
      [](std::vector<std::string_view> pair) {
        return std::vector<int>{pair[0][0] - 'A', pair[1][0] - 'X'};
      });
    std::vector<int> score;
    std::transform(
      std::begin(diff),
      std::end(diff),
      std::back_inserter(score),
      [](std::vector<int> pair) { return pair[1] + 1 + getScore(pair); });
    return std::accumulate(std::begin(score), std::end(score), 0);
  }

  inline auto getResponse(const std::vector<int>& pair)
  {
    constexpr int LOSE{0};
    constexpr int DRAW{1};
    if (pair[1] == DRAW)
    {
      return pair[0];
    }
    if (pair[1] == LOSE)
    {
      return prev(pair[0], 3);
    }
    return next(pair[0], 3);
  }
  inline auto day02_2(const std::vector<std::string>& input)
  {
    std::vector<std::vector<std::string_view>> parsed;
    std::transform(std::begin(input),
                   std::end(input),
                   std::back_inserter(parsed),
                   [](const std::string& s) { return split(s, ' '); });
    std::vector<std::vector<int>> diff;
    std::transform(
      std::begin(parsed),
      std::end(parsed),
      std::back_inserter(diff),
      [](std::vector<std::string_view> pair) {
        return std::vector<int>{pair[0][0] - 'A', pair[1][0] - 'X'};
      });
    std::vector<int> score;
    std::transform(std::begin(diff),
                   std::end(diff),
                   std::back_inserter(score),
                   [](std::vector<int> pair) {
                     return pair[1] * 3 + getResponse(pair) + 1;
                   });
    return std::accumulate(std::begin(score), std::end(score), 0);
  }
} // namespace aoc
