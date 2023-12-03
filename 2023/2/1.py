import re
from typing import DefaultDict, List, Tuple
from collections import defaultdict


def get_input():
    return map(lambda s: s.strip(), open("input.txt", "r", encoding="utf-8"))


rules = {"red": 12, "green": 13, "blue": 14}


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


def filter_games(game: Tuple[int, DefaultDict[str, int]]) -> int:
    n, d = game
    for color, num in d.items():
        if num > rules[color]:
            return 0
    return n


print(sum(map(filter_games, enumerate(map(parse_game, get_input()), 1))))

# 2447
