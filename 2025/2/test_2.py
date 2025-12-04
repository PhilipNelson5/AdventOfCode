from collections.abc import Iterable
from pathlib import Path


def read(file: str) -> Iterable[tuple[int, int]]:
    path = Path(__file__).parent / file
    with path.open(encoding="utf-8") as f:
        line = f.readline()

        def fn(range: str) -> tuple[int, int]:
            a, b = range.split("-")
            return int(a), int(b)

        return map(fn, line.split(","))


def validate_1(x: str) -> bool:
    if len(x) % 2 != 0:
        return True
    n = len(x) // 2
    return x[:n] != x[n:]


def solve_2_1(ranges: list[tuple[int, int]]) -> int:
    sum = 0
    for a, b in ranges:
        for i in range(a, b + 1):
            if not validate_1(str(i)):
                sum += i
    return sum


def test_day_2_1():
    # print(solve_2_1(read("2.sample.txt")))
    # print(solve_2_1(read("2.txt")))
    assert solve_2_1(read("2.sample.txt")) == 1227775554
    assert solve_2_1(read("2.txt")) == 18700015741


# test_day_2_1()

###############################################################################


def batched(lst, n):
    for i in range(0, len(lst), n):
        yield lst[i : i + n]


def equal(lst: Iterable) -> bool:
    it = iter(lst)
    try:
        x = next(it)
        y = next(it)
        while True:
            if x != y:
                return False
            x = y
            y = next(it)
    except StopIteration:
        return True


def validate_2(x: str) -> bool:
    n = len(x)
    for i in range(n // 2, 0, -1):
        if n % i != 0:
            continue
        chunks = batched(x, i)
        if equal(chunks):
            return False
    return True


def solve_2_2(ranges: list[tuple[int, int]]) -> int:
    sum = 0
    for a, b in ranges:
        for i in range(a, b + 1):
            if not validate_2(str(i)):
                print(i)
                sum += i
    return sum


def test_day_2_2():
    assert equal([1, 1, 1])
    assert equal([1, 1])
    assert not equal([1, 0])
    assert not equal([1, 1, 0])
    # print(solve_2_2(read("2.sample.txt")))
    # print(solve_2_2(read("2.txt")))
    assert solve_2_2(read("2.sample.txt")) == 4174379265
    assert solve_2_2(read("2.txt")) == 20077272987


# test_day_2_2()
