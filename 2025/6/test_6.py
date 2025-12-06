from functools import reduce
from pathlib import Path


def read(file: str) -> list[list]:
    path = Path(__file__).parent / file
    cols: list[list] = []
    with path.open(encoding="utf-8") as f:
        for line in f:
            nums = line.strip().split()
            for i, n in enumerate(nums):
                if len(cols) < i + 1:
                    cols.append([])

                if n.isdigit():
                    cols[i].append(int(n))
                else:
                    cols[i].append(n)

    return cols


def math(nums: list) -> int:
    match nums.pop():
        case "*":
            op = lambda a, b: a * b
        case "+":
            op = lambda a, b: a + b

    return reduce(op, nums)


def solve_6_1(lists) -> int:
    return sum(map(math, lists))


def test_day_6_1():
    # print(solve_6_1(read("6.sample.txt")))
    # print(solve_6_1(read("6.txt")))
    assert solve_6_1(read("6.sample.txt")) == 4277556
    assert solve_6_1(read("6.txt")) == 5667835681547


# test_day_6_1()

###############################################################################


def read_2(file: str) -> list[str]:
    path = Path(__file__).parent / file
    return path.read_text().split("\n")


def rearrange(lines: list[str]) -> list[list[str]]:
    cols: list[list[str]] = [[]]
    for c in range(len(lines[0])):
        cols[-1].append("")
        for line in lines:
            cols[-1][-1] += line[c]
        cols[-1][-1] = cols[-1][-1].strip()
        if cols[-1][-1] == "":
            cols[-1] = cols[-1][:-1]
            cols.append([])
    return cols


def math_2(nums: list[str]) -> int:
    print(nums)
    _op = nums[0][-1]
    nums[0] = nums[0][:-1]

    match _op:
        case "*":
            op = lambda a, b: a * b
        case "+":
            op = lambda a, b: a + b

    return reduce(op, map(int, nums))


def solve_6_2(lines: list[str]) -> int:
    return sum(map(math_2, rearrange(lines)))


def test_day_6_2():
    # print(solve_6_2(read_2("6.sample.txt")))
    # print(solve_6_2(read_2("6.txt")))
    assert solve_6_2(read_2("6.sample.txt")) == 3263827
    assert solve_6_2(read_2("6.txt")) == 9434900032651


test_day_6_2()
