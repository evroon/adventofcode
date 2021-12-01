import numpy as np


def part1(input: str) -> int:
    inc_count = 0
    prev = int(1e9)
    measurements = input.split('\n')[:-1]

    for j in measurements:
        if prev < int(j):
            inc_count += 1
        prev = int(j)

    return inc_count


def part2(input: str) -> int:
    inc_count = 0
    lines = [int(x) for x in input.split('\n')[:-1]]
    measurements = np.array(lines)

    for i, j in enumerate(measurements):
        sum = np.sum(measurements[i:i + 3])
        sum_shift = np.sum(measurements[i + 1:i + 4])
        if sum < sum_shift:
            inc_count += 1

    return inc_count
