#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

struct Point
{
  Point(int x, int y) : x(x), y(y) {}
  int x;
  int y;
};

int main()
{
  std::string input;

  std::ifstream fin("input.txt");
  if (!fin)
  {
    std::cout << "bad file" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::regex r("^.+@\\s+(\\d+),(\\d+):\\s+(\\d+)x(\\d+)$");
  std::vector<std::pair<Point, Point>> claims;

  while (std::getline(fin, input))
  {
    std::smatch m;
    std::regex_search(input, m, r);

    claims.push_back(
      std::make_pair(Point(std::stoi(m[1]) + 1, std::stoi(m[2]) + 1),
                     Point(std::stoi(m[1]) + std::stoi(m[3]),
                           std::stoi(m[2]) + std::stoi(m[4]))));
  }

  auto maxX = *std::max_element(
    std::begin(claims), std::end(claims), [](auto const& p1, auto const& p2) {
      return p1.second.x < p2.second.x;
    });

  auto maxY = *std::max_element(
    std::begin(claims), std::end(claims), [](auto const& p1, auto const& p2) {
      return p1.second.y < p2.second.y;
    });

  int cols = maxX.second.x + 1, rows = maxY.second.y + 1;

  std::vector<std::vector<int>> fabric(rows);
  std::for_each(std::begin(fabric), std::end(fabric), [&](auto& row) {
    row.resize(cols, 0);
  });

  std::for_each(std::begin(claims), std::end(claims), [&](auto const& c) {
    for (auto i = c.first.y; i <= c.second.y; ++i)
      for (auto j = c.first.x; j <= c.second.x; ++j)
      {
        ++fabric[i][j];
      }
  });

  auto ct = 0u;
  for (auto&& row : fabric)
    for (auto&& e : row)
      if (e > 1) ++ct;

  for (auto c = 0u; c < claims.size(); ++c)
  {
    bool good = true;
    for (auto i = claims[c].first.y; good && i <= claims[c].second.y; ++i)
    {
      for (auto j = claims[c].first.x; j <= claims[c].second.x; ++j)
      {
        if (fabric[i][j] > 1)
        {
          good = false;
          break;
        }
      }
    }
    if (good)
    {
      std::cout << c + 1 << std::endl;
      break;
    }
  }
}
