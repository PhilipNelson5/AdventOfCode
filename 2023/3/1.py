from typing import List


def get_input() -> List[List[str]]:
    return list(map(lambda s: s.strip(), open("input.txt", "r", encoding="utf-8")))


schematic = get_input()


def is_marked(i, j):
    for ii in [-1, 0, 1]:
        for jj in [-1, 0, 1]:
            try:
                other = schematic[i + ii][j + jj]
                if not other.isdigit() and other != ".":
                    return True
            except:
                pass
    return False


sum = 0
for i, line in enumerate(schematic):
    number = ""
    marked = False
    for j, c in enumerate(line):
        if c.isdigit():
            number += c
            marked = marked or is_marked(i, j)
        elif number.isdigit():
            if marked:
                sum += int(number)
            number = ""
            marked = False
    if number.isdigit() and marked:  # edge of the schematic
        sum += int(number)

print(sum)

# 539433
