from pathlib import Path


def read(file: str) -> tuple[list[tuple[int, int]], list[int]]:
    path = Path(__file__).parent / file
    good = []
    with path.open(encoding="utf-8") as f:
        for line in f:
            if line.strip() == "":
                break
            a, b = line.strip().split("-")
            good.append((int(a), int(b)))

        ing = [int(x) for x in f]

    return good, ing

def in_range(range: tuple[int, int], x: int) -> bool:
    return x >= range[0] and x <= range[1]

def solve_5_1(input: tuple[list[tuple[int, int]], list[int]]) -> int:
    ranges, ingredients = input
    count = 0
    for i in ingredients:
        for range in ranges:
            if in_range(range, i):
                count += 1
                break
    return count


def test_day_5_1():
    # print(solve_5_1(read("5.sample.txt")))
    # print(solve_5_1(read("5.txt")))
    assert solve_5_1(read("5.sample.txt")) == 3
    assert solve_5_1(read("5.txt")) == 681

# test_day_5_1()

###############################################################################


def solve_5_2(ranges: list[tuple[int, int]]) -> int:
    ranges.sort(key=lambda x: x[0])
    _ranges = [ranges[0]]
    for i in range(1, len(ranges)):
        a1, b1 = _ranges[-1]
        a2, b2 = ranges[i]
        if a2 <= b1:
            _ranges[-1] = (a1, max(b2, b1))
        else:
            _ranges.append(ranges[i])

    # print(ranges, len(ranges))
    # print(_ranges, len(_ranges))
    count = 0
    for a, b in _ranges:
        count += b - a + 1
    return count


def test_day_5_2():
    # print(solve_5_2(read("5.sample.txt")[0]))
    # print(solve_5_2(read("5.txt")[0]))
    assert solve_5_2(read("5.sample.txt")[0]) == 14
    assert solve_5_2(read("5.txt")[0]) == 348820208020395

# test_day_5_2()