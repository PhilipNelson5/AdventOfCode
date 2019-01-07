#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>

std::pair<int, int> count2or3(std::string s)
{
  std::map<char, int> count;
  int two = 0, three = 0;
  std::for_each(std::begin(s), std::end(s), [&](char c) {
    auto loc = count.find(c);
    if (loc != std::end(count))
    {
      ++(*loc).second;
    }
    else
    {
      count.emplace(c, 1);
    }
  });

  std::for_each(std::begin(count), std::end(count), [&](auto p) {
    if (p.second == 2) ++two;
    if (p.second == 3) ++three;
  });
  return {two > 0, three > 0};
}

int main()
{
  std::string input;
  int twos = 0, threes = 0;

  std::ifstream fin("input.txt");
  if (!fin)
  {
    std::cout << "bad file" << std::endl;
    exit(EXIT_FAILURE);
  }

  while (fin >> input)
  {
    auto [two, three] = count2or3(input);
    std::cout << two << " " << three << "\n";
    twos += two;
    threes += three;
  }
  std::cout << twos * threes << std::endl;
}
