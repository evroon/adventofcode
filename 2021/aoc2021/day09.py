import numpy as np


def find_basins(map: np.ndarray, width: int, height: int) -> np.ndarray:
    mask = np.zeros_like(map)
    for x in range(width):
        for y in range(height):
            value = map[x, y]
            neighbors = [
                map[x - 1, y] if x > 0 else None,
                map[x + 1, y] if x < width - 1 else None,
                map[x, y - 1] if y > 0 else None,
                map[x, y + 1] if y < height - 1 else None,
            ]
            neighbors = [x for x in neighbors if x is not None]

            if all(neighbors > value):
                mask[x, y] = value + 1

    return mask


def part1(input_file: str) -> int:
    width, height = 100, 100
    map = np.zeros((width, height), dtype=int)
    with open(input_file, 'r') as f:
        for i in range(height):
            map[..., i] = [int(x) for x in list(f.readline())[:-1]]

    mask = find_basins(map, width, height)
    return int(np.sum(mask))


def part2(input_file: str) -> int:
    width, height = 100, 100
    map = np.zeros((width, height), dtype=int)
    with open(input_file, 'r') as f:
        for i in range(height):
            map[..., i] = [int(x) for x in list(f.readline())[:-1]]

    mask = find_basins(map, width, height)
    

    return int(np.sum(mask))
