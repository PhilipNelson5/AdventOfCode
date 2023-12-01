#ifndef AOC_UTILS
#define AOC_UTILS

#include <algorithm>
#include <fstream>
#include <ranges>
#include <string>
#include <vector>

namespace aoc
{
  template <typename T, typename F>
  inline auto toString(std::ranges::filter_view<T, F> view)
  {
    return std::string{view.begin(), view.end()};
  }
  inline auto readInput(const std::string& filename)
  {
    std::ifstream file(filename);
    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    std::string input(size, ' ');
    file.seekg(0);
    file.read(&input[0], size);
    return input;
  }
  inline auto readLines(const std::string& filename)
  {
    std::vector<std::string> input;
    std::ifstream file(filename);
    if (file.is_open())
    {
      std::string line;
      while (std::getline(file, line))
      {
        input.push_back(line);
      }
      file.close();
    }
    return input;
  }

  template <typename C>
  struct to_helper
  {
  };
  template <typename Container, std::ranges::range R>
  requires std::convertible_to<std::ranges::range_value_t<R>,
                               typename Container::value_type>
    Container operator|(R&& r, to_helper<Container>)
  {
    return Container{r.begin(), r.end()};
  }
  template <std::ranges::range Container>
  requires(!std::ranges::view<Container>) [[nodiscard]] auto to()
  {
    return to_helper<Container>{};
  }

  [[nodiscard]] inline auto split(const std::string_view string,
                                  const char delim)
  {
    std::vector<std::string_view> output;
    const auto* first = std::begin(string);

    while (first != std::end(string))
    {
      const auto* const second = std::find(first, std::cend(string), delim);

      const auto a{std::distance(std::begin(string), first)};
      const auto b{std::distance(first, second)};
      // conversion from signed to unsigned might change sign but we are
      // iterating forwards in the string so a and b will not be negative
      output.emplace_back(
        string.substr(static_cast<uint64_t>(a), static_cast<uint64_t>(b)));

      if (second == std::end(string))
      {
        return output;
      }

      first = std::next(second);
    }

    if (string.back() == delim)
    {
      output.emplace_back("");
    }

    return output;
  }

  template <typename T>
  auto operator<<(std::ostream& os, std::vector<T> v) -> std::ostream&
  {
    if (v.size() == 0)
    {
      os << "[ ]";
      return os;
    }
    if (v.size() == 1)
    {
      os << "[ " << v[0] << " ]";
      return os;
    }
    os << "[ ";
    std::for_each(std::begin(v), std::begin(v) + v.size() - 1u, [&os](T t) {
      os << t << ", ";
    });
    os << v.back() << " ]";
    return os;
  }
} // namespace aoc
#endif // AOC_UTILS
