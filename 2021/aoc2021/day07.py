import numpy as np


def part1(input_file: str) -> int:
    positions = np.genfromtxt(input_file, delimiter=',', dtype=int)
    min = 0
    max = np.max(positions)
    fuels = np.zeros(max, dtype=int)

    for p in np.arange(min, max):
        fuels[p] = np.sum(np.abs(positions - p))

    return np.min(fuels)


def part2(input_file: str) -> int:
    positions = np.genfromtxt(input_file, delimiter=',', dtype=int)
    min = 0
    max = np.max(positions)
    fuels = np.zeros(max, dtype=int)
    fuel_lookup = np.cumsum(np.arange(min, max*2))

    for p in np.arange(min, max):
        for i in range(len(positions)):
            fuels[p] += fuel_lookup[np.abs(positions[i] - p)]

    return np.min(fuels)
