import re
from functools import reduce
from typing import List

digits = {
    "one": "1",
    "two": "2",
    "three": "3",
    "four": "4",
    "five": "5",
    "six": "6",
    "seven": "7",
    "eight": "8",
    "nine": "9",
}
names = re.compile("(?=(one|two|three|four|five|six|seven|eight|nine|[0-9]))")


def get_input():
    return map(lambda s: s.strip(), open("input.txt", "r", encoding="utf-8"))


def get_numbers(s: str) -> List[str]:
    return list(re.findall(names, s))


def get_num(l: List[str]) -> int:
    a = digits[l[0]] if l[0] in digits else l[0]
    b = digits[l[-1]] if l[-1] in digits else l[-1]
    return int(a + b)


print(
    sum(
        map(
            get_num,
            map(get_numbers, get_input()),
        )
    )
)

# 54265
