#pragma once

#include "Utils.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <tuple>
#include <vector>

struct Dir
{
  std::string_view name;
  std::vector<Dir> children;
  std::vector<int> files;
  Dir* pParent;
  int size{0};
};

namespace aoc
{
  inline auto getDirStr(std::string_view line)
  {
    using namespace std::string_literals;
    return (std::views::split(line, " "s) | std::views::transform([](auto s) {
              return std::string_view{s.begin(), s.end()};
            })
            | to<std::vector<std::string_view>>())[2];
  }
  inline auto getFileSizeStr(std::string_view line)
  {
    using namespace std::string_literals;
    return (std::views::split(line, " "s) | std::views::transform([](auto s) {
              return std::string_view{s.begin(), s.end()};
            })
            | to<std::vector<std::string_view>>())[0];
  }
  inline void parse(const std::vector<std::string>& in, uint& i, Dir& rCurr)
  {
    if (i == in.size())
    {
      return;
    }

    if (in[i].starts_with("$ cd"))
    {
      const auto dirName{getDirStr(in[i])};
      if (dirName == "..")
      {
        // All children are parsed, calculate size
        rCurr.size = std::accumulate(rCurr.files.begin(), rCurr.files.end(), 0)
                     + std::accumulate(
                       rCurr.children.begin(),
                       rCurr.children.end(),
                       0,
                       [](int acc, Dir& child) { return acc + child.size; });
        return parse(in, ++i, *rCurr.pParent);
      }
      Dir child(dirName, {}, {}, &rCurr);
      rCurr.children.push_back(child);
      return parse(in, ++i, rCurr.children.back());
    }
    if (!in[i].starts_with("$ ls") && !in[i].starts_with("dir"))
    {
      const auto sizeStr{getFileSizeStr(in[i])};
      const int size{std::stoi(std::string{sizeStr.begin(), sizeStr.end()})};
      rCurr.files.push_back(size);
    }
    return parse(in, ++i, rCurr);
  }
  inline auto parse(const std::vector<std::string>& in)
  {
    Dir root{"/", {}, {}, nullptr};
    uint i{1u};
    parse(in, i, root);
    return root;
  }
  inline auto sumLTE100000(Dir& root) -> int
  {
    return (root.size <= 100000 ? root.size : 0)
           + std::accumulate(
             root.children.begin(),
             root.children.end(),
             0,
             [](int acc, Dir& child) { return acc + sumLTE100000(child); });
  }
  inline auto day07_1(const std::vector<std::string>& input)
  {
    auto root{parse(input)};
    return sumLTE100000(root);
  }

  inline auto findSmallestDirGreaterThanX(
    Dir& root, int x, int least = std::numeric_limits<int>::max()) -> int
  {
    if (root.size < x)
    {
      return least;
    }
    return std::min(
      least,
      std::min(root.size,
               std::accumulate(root.children.begin(),
                               root.children.end(),
                               std::numeric_limits<int>::max(),
                               [x](int acc, Dir& child) {
                                 return std::min(
                                   acc, findSmallestDirGreaterThanX(child, x));
                               })));
  }
  inline auto day07_2(const std::vector<std::string>& input)
  {
    constexpr int DISK_SIZE{70000000};
    constexpr int NEEDED_SPACE{30000000};

    auto root{parse(input)};
    const auto freeSpace{DISK_SIZE - root.size};
    const auto requiredSpace{NEEDED_SPACE - freeSpace};

    return findSmallestDirGreaterThanX(root, requiredSpace);
  }
} // namespace aoc
