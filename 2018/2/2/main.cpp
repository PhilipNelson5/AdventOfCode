#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

int partialSubstring(std::string::iterator b1,
                     std::string::iterator e1,
                     std::string::iterator b2)
{
  auto start = b1;
  for (; b1 != e1 && *b1 == *b2; ++b1, ++b2)
  {
  }
  return b1 - start;
}

bool isEqual(std::string::iterator b1,
             std::string::iterator e1,
             std::string::iterator b2)
{
  for (; b1 != e1 && *b1 == *b2; ++b1, ++b2)
  {
  }
  return b1 == e1;
}

int main()
{
  std::string input;
  std::vector<std::string> labels;

  std::ifstream fin("input.txt");
  if (!fin)
  {
    std::cout << "bad file" << std::endl;
    exit(EXIT_FAILURE);
  }

  while (fin >> input)
  {
    labels.push_back(input);
  }

  for (auto i = 0u; i < labels.size() - 1; ++i)
  {
    for (auto j = i + 1; j < labels.size(); ++j)
    {
      auto ps = partialSubstring(
        std::begin(labels[i]), std::end(labels[i]), std::begin(labels[j]));

      if (ps > 0)
      {
        auto equal = isEqual(std::begin(labels[i]) + ps + 1,
                             std::end(labels[i]),
                             std::begin(labels[j]) + ps + 1);
        if (equal)
        {
          std::cout << std::string(
                         std::begin(labels[i]), std::begin(labels[i]) + ps)
                    << std::string(
                         std::begin(labels[i]) + ps + 1, std::end(labels[i]))
                    << std::endl;
          exit(EXIT_SUCCESS);
        }
      }
    }
  }
}
