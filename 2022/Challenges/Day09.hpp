#pragma once

#include "Utils.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <tuple>
#include <unordered_set>
#include <vector>

namespace aoc
{
  struct Point
  {
    int x;
    int y;
  };
  inline auto operator==(const Point a, const Point b)
  {
    return a.x == b.x && a.y == b.y;
  }
  template <class T>
  inline void hash_combine(std::size_t& seed, const T& v)
  {
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2); // NOLINT
  }
  struct PointHash
  {
    inline auto operator()(const Point& p) const
    {
      std::size_t seed = 0;
      hash_combine(seed, p.x);
      hash_combine(seed, p.y);
      return seed;
    }
  };
  inline auto operator<<(std::ostream& os, Point p) -> std::ostream&
  {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
  }
  inline auto touching(const Point a, const Point b)
  {
    return (std::abs(a.x - b.x) <= 1) && (std::abs(a.y - b.y) <= 1);
  }
  inline auto day09_1(const std::vector<std::string>& input)
  {
    Point H{0, 0};
    Point T{0, 0};

    std::unordered_set<Point, PointHash> locations;
    for (const auto& line : input)
    {
      const char dir{line[0]};
      const int move{std::stoi(std::string{line.begin() + 2, line.end()})};
      std::cout << dir << " " << move << std::endl;

      for (auto i{0}; i < move; ++i)
      {
        switch (dir)
        {
        case 'L':
          H.x -= 1;
          break;
        case 'U':
          H.y += 1;
          break;
        case 'R':
          H.x += 1;
          break;
        case 'D':
          H.y -= 1;
          break;
        default:
          break;
        }
        std::cout << H << " " << T;
        if (!touching(H, T))
        {
          if (H.x != T.x)
          {
            T.x += H.x - T.x - 1;
          }
          if (H.y != T.y)
          {
            T.y += H.y - T.y - 1;
          }
          // else
          // {
          //   T.y += H.y - T.y;
          //   T.x += H.x - T.x;
          // }
        }
        else
        {
          std::cout << "*";
        }
        std::cout << " -> " << T;
        std::cout << std::endl;
        locations.insert(T);
      }
    }
    return locations.size();
  }

  inline auto day09_2(const std::vector<std::string>& input)
  {
    return input.size();
  }
} // namespace aoc
