from typing import List


def get_input():
    with open("input.txt", "r", encoding="utf-8") as f:
        # with open("ex.txt", "r", encoding="utf-8") as f:
        seeds = [int(x) for x in f.readline().split()[1:]]
        lines = f.readlines()
        maps = []
        i = 1
        while i < len(lines):
            i += 1
            m = []
            while i < len(lines) and (line := lines[i].strip()) != "":
                m.append([int(x) for x in line.split()])
                i += 1
            maps.append(m)
            i += 1
    return seeds, maps


seeds, maps = get_input()


def lookup(seed, m: List[List[int]]) -> int:
    for r in m:
        dest, src, n = r
        if seed >= src and seed <= src + n:
            next = dest + seed - src
            return next
    return seed


def translate(seed, maps):
    next = seed
    for m in maps:
        next = lookup(next, m)
    return next


print(min(translate(seed, maps) for seed in seeds))

# 174137457
