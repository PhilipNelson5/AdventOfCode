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
  inline auto move(std::vector<std::vector<char>>& rShip,
                   const int from,
                   const int to)
  {
    rShip[to].push_back(rShip[from].back());
    rShip[from].pop_back();
  }
  inline auto day05_1(const std::vector<std::string>& input)
  {
    std::vector<std::vector<char>> ship{
      {'R', 'P', 'C', 'D', 'B', 'G'},
      {'H', 'V', 'G'},
      {'N', 'S', 'Q', 'D', 'J', 'P', 'M'},
      {'P', 'S', 'L', 'G', 'D', 'C', 'N', 'M'},
      {'J', 'B', 'N', 'C', 'P', 'F', 'L', 'S'},
      {'Q', 'B', 'D', 'Z', 'V', 'G', 'T', 'S'},
      {'B', 'Z', 'M', 'H', 'F', 'T', 'Q'},
      {'C', 'M', 'D', 'B', 'F'},
      {'F', 'C', 'Q', 'G'}};
    std::for_each(
      input.begin() + 10, input.end(), [&](const std::string& line) {
        const auto next{toString(
          line | std::views::filter([](const unsigned char c) noexcept {
            return isdigit(c) > 0 || isspace(c) > 0;
          }))};

        std::size_t pos1{};
        std::size_t pos2{};
        const int n{std::stoi(next.data(), &pos1)};
        const int from{std::stoi(next.data() + pos1, &pos2) - 1};
        const int to{std::stoi(next.data() + pos1 + pos2) - 1};
        for (auto i{0}; i < n; ++i)
        {
          aoc::move(ship, from, to);
        }
      });
    return std::accumulate(ship.begin(),
                           ship.end(),
                           std::string{},
                           [](const std::string& s, std::vector<char> row) {
                             return s + row.back();
                           });
  }

  inline auto move(std::vector<std::vector<char>>& rShip,
                   const int n,
                   const int from,
                   const int to)
  {
    const auto first{rShip[from].size() - n};
    std::copy(rShip[from].begin() + first,
              rShip[from].end(),
              std::back_inserter(rShip[to]));
    rShip[from].erase(rShip[from].begin() + first, rShip[from].end());
  }
  inline auto day05_2(const std::vector<std::string>& input)
  {
    std::vector<std::vector<char>> ship{
      {'R', 'P', 'C', 'D', 'B', 'G'},
      {'H', 'V', 'G'},
      {'N', 'S', 'Q', 'D', 'J', 'P', 'M'},
      {'P', 'S', 'L', 'G', 'D', 'C', 'N', 'M'},
      {'J', 'B', 'N', 'C', 'P', 'F', 'L', 'S'},
      {'Q', 'B', 'D', 'Z', 'V', 'G', 'T', 'S'},
      {'B', 'Z', 'M', 'H', 'F', 'T', 'Q'},
      {'C', 'M', 'D', 'B', 'F'},
      {'F', 'C', 'Q', 'G'}};
    std::for_each(
      input.begin() + 10, input.end(), [&](const std::string& line) {
        const auto next{toString(
          line | std::views::filter([](const unsigned char c) noexcept {
            return isdigit(c) > 0 || isspace(c) > 0;
          }))};

        std::size_t pos1{};
        std::size_t pos2{};
        const int n{std::stoi(next.data(), &pos1)};
        const int from{std::stoi(next.data() + pos1, &pos2) - 1};
        const int to{std::stoi(next.data() + pos1 + pos2) - 1};
        aoc::move(ship, n, from, to);
      });
    return std::accumulate(ship.begin(),
                           ship.end(),
                           std::string{},
                           [](const std::string& s, std::vector<char> row) {
                             return s + row.back();
                           });
  }
} // namespace aoc
