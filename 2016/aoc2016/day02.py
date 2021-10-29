from typing import Tuple


def get_direction(dir: str) -> Tuple[int, int]:
    return {
        'U': (0, -1),
        'L': (-1, 0),
        'D': (0, 1),
        'R': (1, 0),
    }[dir]


def distance(loc: Tuple[int, int]) -> int:
    return abs(loc[0]) + abs(loc[1])


def part1(input: str) -> str:
    dir = 0
    lines = input.split('\n')
    location = (1, 1)
    result = []

    for line in lines[:-1]:
        for step in line:
            diff = get_direction(step)
            magnitude = 1

            location = (
                max(0, min(2, location[0] + diff[0] * magnitude)),
                max(0, min(2, location[1] + diff[1] * magnitude))
            )

        c = location[0] + 1 + 3 * location[1]
        result.append(str(c))

    return ''.join(result)


def part2(input: str) -> str:
    dir = 0
    lines = input.split('\n')
    location = (0, 2)
    result = []

    keypad = \
'''  1
 234
56789
 ABC
  D'''

    for line in lines[:-1]:
        for step in line:
            diff = get_direction(step)
            magnitude = 1

            new_location = (
                location[0] + diff[0] * magnitude,
                location[1] + diff[1] * magnitude
            )

            new_location_offset = (
                new_location[0] - 2,
                new_location[1] - 2,
            )

            if distance(new_location_offset) <= 2:
                location = new_location

        c = keypad.split('\n')[location[1]][location[0]]
        result.append(str(c))

    return ''.join(result)
