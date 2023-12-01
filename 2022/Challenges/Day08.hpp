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
  inline auto process(const std::vector<std::string>& input)
  {
    std::vector<std::vector<int>> output{};
    for (const auto& line : input)
    {
      output.emplace_back();
      for (const auto& chr : line)
      {
        output.back().push_back(std::stoi(std::string{chr}));
      }
    }
    return output;
  }
  inline void updateRow(const std::vector<std::vector<int>>& grid,
                        std::vector<std::vector<bool>>& visible,
                        const uint i)
  {
    auto size{static_cast<int>(grid[i].size())};
    auto max{-1};
    for (auto j{0}; j < size; ++j)
    {
      visible[i][j] = visible[i][j] || (grid[i][j] > max);
      max = std::max(max, grid[i][j]);
    }

    max = -1;
    for (auto j{size - 1}; j >= 0; --j)
    {
      visible[i][j] = visible[i][j] || (grid[i][j] > max);
      max = std::max(max, grid[i][j]);
    }
  }
  inline void updateCol(const std::vector<std::vector<int>>& grid,
                        std::vector<std::vector<bool>>& visible,
                        const uint j)
  {
    auto size{static_cast<int>(grid.size())};
    auto max{-1};
    for (auto i{0}; i < size; ++i)
    {
      visible[i][j] = visible[i][j] || (grid[i][j] > max);
      max = std::max(max, grid[i][j]);
    }

    max = -1;
    for (auto i{size - 1}; i >= 0; --i)
    {
      visible[i][j] = visible[i][j] || (grid[i][j] > max);
      max = std::max(max, grid[i][j]);
    }
  }
  inline auto day08_1(const std::vector<std::string>& input)
  {
    const auto grid{process(input)};
    std::vector<std::vector<bool>> visible{grid.size()};
    std::generate(visible.begin(), visible.end(), [n = grid[0].size()]() {
      return std::vector<bool>(n);
    });

    for (auto i{0u}; i < grid.size(); ++i)
    {
      updateRow(grid, visible, i);
    }
    for (auto j{0u}; j < grid[0].size(); ++j)
    {
      updateCol(grid, visible, j);
    }
    return std::accumulate(
      visible.begin(), visible.end(), 0, [](const auto acc1, const auto row) {
        return acc1
               + std::accumulate(
                 row.begin(), row.end(), 0, [](const auto acc2, const auto x) {
                   return acc2 + (x ? 1 : 0);
                 });
      });
  }

  inline auto day08_2(const std::vector<std::string>& input)
  {
    const auto grid{process(input)};
    auto width{static_cast<int>(grid[0].size())};
    auto height{static_cast<int>(grid.size())};
    auto max{-1};
    for (auto i{0}; i < height; ++i)
    {
      for (auto j{0}; j < width; ++j)
      {
        int L{0};
        if (j != 0)
        {
          for (auto x{j - 1}; x >= 0; --x)
          {
            ++L;
            if (grid[i][x] >= grid[i][j])
            {
              break;
            }
          }
        }
        int R{0};
        if (j != width - 1)
        {
          for (auto x{j + 1}; x < width; ++x)
          {
            ++R;
            if (grid[i][x] >= grid[i][j])
            {
              break;
            }
          }
        }
        int U{0};
        if (i != 0)
        {
          for (auto x{i - 1}; x >= 0; --x)
          {
            ++U;
            if (grid[x][j] >= grid[i][j])
            {
              break;
            }
          }
        }
        int D{0};
        if (i != height - 1)
        {
          for (auto x{i + 1}; x < height; ++x)
          {
            ++D;
            if (grid[x][j] >= grid[i][j])
            {
              break;
            }
          }
        }
        max = std::max(max, L * R * U * D);
      }
    }
    return max;
  }
} // namespace aoc
