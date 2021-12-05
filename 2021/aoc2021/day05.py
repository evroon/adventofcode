from typing import Tuple, List

import numpy as np


def check_order(start: List[int], end: List[int]) -> Tuple[List[int], List[int]]:
    for x in range(2):
        if start[x] > end[x]:
            tmp = end[x]
            end[x] = start[x]
            start[x] = tmp

    return start, end


def create_map(input_file: str, use_diagonals: bool):
    with open(input_file, 'r') as f:
        lines = f.read().split('\n')[:-1]

    vents_map = np.zeros((1000, 1000), dtype=int)
    for line in lines:
        line_split = line.split(' -> ')
        start = [int(x) for x in line_split[0].split(',')]
        end = [int(x) for x in line_split[1].split(',')]

        if start[0] == end[0]:
            start, end = check_order(start, end)
            vents_map[start[0], start[1]:end[1] + 1] += 1
        elif start[1] == end[1]:
            start, end = check_order(start, end)
            vents_map[start[0]:end[0] + 1, start[1]] += 1
        elif use_diagonals:
            pipe_length = abs(end[0] - start[0])
            pipe_dir = ((np.array(end) - np.array(start)) / pipe_length).astype(int)

            for i in range(pipe_length + 1):
                vents_map[start[0] + pipe_dir[0] * i, start[1] + pipe_dir[1] * i] += 1

    return int(np.sum(vents_map >= 2))


def part1(input_file: str) -> int:
    return create_map(input_file, False)


def part2(input_file: str) -> int:
    return create_map(input_file, True)
