from collections.abc import Iterable
from pathlib import Path


def read(file: str) -> Iterable[int]:
    path = Path(__file__).parent / file
    with path.open(encoding="utf-8") as f:
        return map(lambda x: int(x[1:]) * (-1 if x[0] == "L" else 1), f.readlines())


def solve_1_1(lines: list[int]) -> int:
    cur = 50
    zeros = 0
    for x in lines:
        # tmp = cur
        cur += x % 100
        if cur < 0:
            cur += 100
        if cur > 99:
            cur -= 100
        if cur == 0:
            zeros += 1
        # print("%2d %3d -> %2d" % (tmp, x, cur))
    return zeros


def test_day_1_1():
    assert solve_1_1(read("1.sample.txt")) == 3
    assert solve_1_1(read("1.txt")) == 1026


# test_day_1_1()

###############################################################################


def sign(x) -> int:
    return 1 if x >= 0 else -1


def solve_1_2(lines: list[int]) -> int:
    cur = 50
    zeros = 0
    for x in lines:
        tmp = cur
        cur += x % (100 * sign(x))
        zeros += abs(x) // 100
        if cur < 0:
            cur += 100
            if tmp != 0:
                zeros += 1
        elif cur > 99:
            cur -= 100
            if tmp != 0:
                zeros += 1
        elif cur == 0:
            zeros += 1
        # print("%2d %4d -> %2d : %d" % (tmp, x, cur, zeros))

    return zeros


def test_day_1_2():
    assert solve_1_2([50]) == 1
    assert solve_1_2([-50]) == 1
    assert solve_1_2([150]) == 2
    assert solve_1_2([-150]) == 2

    assert solve_1_2(read("1.sample.txt")) == 6
    assert solve_1_2(read("1.txt")) == 5923


# test_day_1_2()
