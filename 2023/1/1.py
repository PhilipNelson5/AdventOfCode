import re
from typing import List


def get_num(s: str) -> int:
    nums = re.findall("[0-9]", s)
    return int(nums[0] + nums[-1])


print(sum(map(get_num, open("input.txt", "r", encoding="utf-8"))))

# 54450
