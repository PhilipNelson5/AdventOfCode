#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

struct Timestamp
{
  int year;
  int month;
  int day;
  int hour;
  int minute;
};

bool operator<(Timestamp const& t1, Timestamp const& t2)
{
  if (t1.year < t2.year) return true;
  if (t1.year > t2.year) return false;
  if (t1.month < t2.month) return true;
  if (t1.month > t2.month) return false;
  if (t1.day < t2.day) return true;
  if (t1.day > t2.day) return false;
  if (t1.hour < t2.hour) return true;
  if (t1.hour > t2.hour) return false;
  if (t1.minute < t2.minute) return true;
  if (t1.minute > t2.minute) return false;
  return false;
}

bool operator>(Timestamp const& t1, Timestamp const& t2)
{
  return !(t1 < t2);
}

std::ostream& operator<<(std::ostream& o, Timestamp const& t)
{
  o << '[' << t.year << '-' << t.month << '-' << t.day << ' ' << t.hour << ':'
    << t.minute << ']';
  return o;
}

enum Type
{
  NEW,
  SLEEP,
  WAKE
};

struct Event
{
  Timestamp t;
  Type type;
  int guard;
};

std::ostream& operator<<(std::ostream& o, Event const& e)
{
  o << e.t << ' ';

  if (e.type == Type::NEW) o << e.guard << " starts";
  if (e.type == Type::SLEEP) o << "sleep";
  if (e.type == Type::WAKE) o << "wake";

  return o;
}

Event make_event(std::string const& line)
{
  Timestamp t;

  t.year = std::stoi(line.substr(1, 4));
  t.month = std::stoi(line.substr(6, 2));
  t.day = std::stoi(line.substr(9, 2));
  t.hour = std::stoi(line.substr(12, 2));
  t.minute = std::stoi(line.substr(15, 2));

  Event e;
  e.t = t;

  if (line[19] == 'w') e.type = Type::WAKE;
  if (line[19] == 'f') e.type = Type::SLEEP;
  if (line[19] == 'G')
  {
    e.type = Type::NEW;
    // 012345678901234567890123456789
    // [1518-06-12 23:59] Guard #1021 begins shift
    e.guard = std::stoi(
      std::string(std::begin(line) + 26,
                  std::find(std::begin(line) + 25, std::end(line), ' ')));
  }

  return e;
}

int main()
{
  std::ifstream fin("input.txt");
  if (!fin)
  {
    std::cout << "no file" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::vector<Event> events;

  std::string line;
  while (std::getline(fin, line))
  {
    events.push_back(make_event(line));
  }

  std::sort(std::begin(events),
            std::end(events),
            [](auto const& e1, auto const& e2) { return e1.t < e2.t; });

  int guard = -1;
  std::map<int, std::vector<int>> minutesAsleep;
  std::map<int, int> totalMinutesAsleep;
  for (auto it = std::begin(events); it != std::end(events); ++it)
  {
    if ((*it).type == Type::NEW)
    {
      guard = (*it).guard;
      
    }
  }

  for (auto i = 0u; i < events.size(); ++i)
  {
    std::cout << events[i] << std::endl;
  }
}
