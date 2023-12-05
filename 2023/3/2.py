from typing import List, Tuple


def get_input() -> List[List[str]]:
    return list(map(lambda s: s.strip(), open("input.txt", "r", encoding="utf-8")))
    # return list(map(lambda s: s.strip(), open("example.txt", "r", encoding="utf-8")))


schematic = get_input()


def get_number(i: int, j: int) -> int:
    while schematic[i][j].isdigit():
        j -= 1
    number = ""
    j += 1
    try:
        while schematic[i][j].isdigit():
            number += schematic[i][j]
            j += 1
    except:
        pass
    return int(number)


def de_dup(l: List[Tuple[int, int]]) -> List[Tuple[int, int]]:
    new = [l[0]]
    for x in range(len(l) - 1):
        a = l[x]
        b = l[x + 1]
        if a[0] == b[0] and abs(a[1] - b[1]) == 1:
            continue
        new.append(b)
    return new


def get_ratio(i: int, j: int) -> int:
    digits_locations = []
    for ii in [-1, 0, 1]:
        for jj in [-1, 0, 1]:
            try:
                other = schematic[i + ii][j + jj]
                if other.isdigit():
                    digits_locations.append((i + ii, j + jj))
            except:
                pass
    digits_locations = de_dup(digits_locations)
    if len(digits_locations) < 2:
        return 0
    s = set([get_number(n[0], n[1]) for n in digits_locations])
    if len(s) == 2:
        return s.pop() * s.pop()
    else:
        return s.pop() ** 2


sum = 0
for i, line in enumerate(schematic):
    for j, c in enumerate(line):
        if c == "*":
            sum += get_ratio(i, j)

print(sum)

# 75847567
