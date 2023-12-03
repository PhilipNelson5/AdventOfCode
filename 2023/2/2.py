import re
from functools import reduce
from typing import DefaultDict, List, Tuple
from collections import defaultdict


def get_input():
    return map(lambda s: s.strip(), open("input.txt", "r", encoding="utf-8"))


def parse_game(game: str) -> DefaultDict[str, int]:
    d = defaultdict(int)
    for round in game.split(": ")[1].split("; "):
        matches = re.findall(r"(\d+) ([a-z]+)", round)
        for m in matches:
            num = int(m[0])
            color = m[1]
            if d[color] < num:
                d[color] = num
    return d


def get_power(game: Tuple[int, DefaultDict[str, int]]) -> int:
    n, d = game
    return reduce(lambda acc, val: acc * val, d.values(), 1)


print(sum(map(get_power, enumerate(map(parse_game, get_input()), 1))))

# 56322
