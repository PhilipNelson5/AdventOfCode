import itertools
from typing import List, Tuple


def get_input() -> Tuple[List[int], List[int]]:
    return enumerate(
        map(
            lambda line: [[int(a) for a in x.split()] for x in line.split("|")],
            map(
                lambda line: line.split(":")[1],
                map(lambda s: s.strip(), open("input.txt", "r", encoding="utf-8")),
            ),
        ),
    )


inpt = list(get_input())
cards = [1] * len(inpt)
for i, game in inpt:
    win, guess = game
    matches = len(set(win).intersection(set(guess)))
    for x in range(i + 1, i + 1 + matches):
        cards[x] += cards[i]

print(sum(cards))

# 8467762
