from typing import Tuple


def get_direction(dir: int) -> Tuple[int, int]:
    return {
        0: (0, 1),
        1: (1, 0),
        2: (0, -1),
        3: (-1, 0),
    }[dir]


def distance(loc: Tuple[int, int]) -> int:
    return abs(loc[0]) + abs(loc[1])


def hash_location(loc: Tuple[int, int]) -> str:
    return f'{loc[0]},{loc[1]}'


def part1(input: str) -> int:
    dir = 0
    steps = input.split(', ')
    location = (0, 0)

    for step in steps:
        dir += 1 if step[0] == 'R' else -1
        dir %= 4
        diff = get_direction(dir)
        magnitude = int(step[1:])

        location = (
            location[0] + diff[0] * magnitude,
            location[1] + diff[1] * magnitude
        )

    return distance(location)


def part2(input: str) -> int:
    dir = 0
    steps = input.split(', ')
    location = (0, 0)
    locations = {
        hash_location(location): True
    }

    for step in steps:
        dir += 1 if step[0] == 'R' else -1
        dir %= 4
        diff = get_direction(dir)
        magnitude = int(step[1:])

        for i in range(magnitude):
            location = (
                location[0] + diff[0],
                location[1] + diff[1]
            )

            hash = hash_location(location)

            if hash in locations:
                return distance(location)

            locations[hash] = True
