from typing import List, Tuple


def get_input() -> Tuple[List[int], List[int]]:
    return map(
        lambda line: [[int(a) for a in x.split()] for x in line.split("|")],
        map(
            lambda line: line.split(":")[1],
            map(lambda s: s.strip(), open("input.txt", "r", encoding="utf-8")),
        ),
    )


def get_points(game: List[List[int]]) -> int:
    win, guess = game
    l = len(set(win).intersection(set(guess)))
    return 0 if l == 0 else 2 ** (l - 1)


print(sum(map(get_points, get_input())))

# 26346
