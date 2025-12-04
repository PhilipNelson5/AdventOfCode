from pathlib import Path


def read(file: str) -> list[list[bool]]:
    path = Path(__file__).parent / file
    with path.open(encoding="utf-8") as f:
        return [[True if char == "@" else False for char in line.strip()] for line in f]


def count_adjacent_rolls(grid: list[list[bool]], x: int, y: int) -> int:
    count = -1
    for _x in range(max(0, x - 1), min(len(grid[0]) - 1, x + 1) + 1):
        for _y in range(max(0, y - 1), min(len(grid) - 1, y + 1) + 1):
            if grid[_y][_x]:
                count += 1
    return count


def solve_4_1(grid: list[list[bool]]) -> int:
    count = 0
    for y, row in enumerate(grid):
        for x, roll in enumerate(row):
            if roll and count_adjacent_rolls(grid, x, y) < 4:
                count += 1
                # print(x, y)
    return count


def test_day_4_1():
    # print(solve_4_1(read("4.sample.txt")))
    # print(solve_4_1(read("4.txt")))
    assert solve_4_1(read("4.sample.txt")) == 13
    assert solve_4_1(read("4.txt")) == 1349


###############################################################################


def remove(grid: list[list[bool]]) -> int:
    count = 0
    for y, row in enumerate(grid):
        for x, roll in enumerate(row):
            if roll and count_adjacent_rolls(grid, x, y) < 4:
                grid[y][x] = False
                count += 1
                # print(x, y)
    return count


def solve_4_2(grid: list[list[bool]]) -> int:
    total = 0
    while count := remove(grid):
        total += count
    return total


def test_day_4_2():
    # print(solve_4_2(read("4.sample.txt")))
    # print(solve_4_2(read("4.txt")))
    assert solve_4_2(read("4.sample.txt")) == 43
    assert solve_4_2(read("4.txt")) == 8277

