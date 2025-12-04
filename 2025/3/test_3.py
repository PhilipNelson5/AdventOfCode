from collections.abc import Iterable
from pathlib import Path


def read(file: str) -> Iterable[str]:
    path = Path(__file__).parent / file
    with path.open(encoding="utf-8") as f:
        for line in f:
            yield line.strip()


def max_joltage_2(bank: str) -> int:
    i, max_a = max(enumerate(bank[:-1]), key=lambda x: x[1])
    max_b = max(bank[i + 1 :])
    return int(f"{max_a}{max_b}")


def solve_3_1(banks: list[str]) -> int:
    return sum(map(max_joltage_2, banks))


def test_day_3_1():
    assert solve_3_1(read("3.sample.txt")) == 357
    assert solve_3_1(read("3.txt")) == 17244


# test_day_3_1()

###############################################################################


def _max_joltage_n(bank: str, n: int) -> str:
    if n == 1:
        return max(bank)
    i, max_a = max(enumerate(bank[: -(n - 1)]), key=lambda x: x[1])
    max_n = max_a + _max_joltage_n(bank[i + 1 :], n - 1)
    # print(f"{n:02d}", bank, max_n)
    return max_n


def max_joltage_n(bank: str, n: int = 12) -> int:
    return int(_max_joltage_n(bank, n))


def solve_3_2(banks: list[str]) -> int:
    return sum(map(max_joltage_n, banks))


def test_day_3_2():
    assert solve_3_2(read("3.sample.txt")) == 3121910778619
    assert solve_3_2(read("3.txt")) == 171435596092638


# test_day_3_2()
