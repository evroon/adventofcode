from typing import List

import numpy as np


def check_bingo(marked: np.ndarray, wins: np.ndarray) -> List[int]:
    result = []
    for b in range(marked.shape[0]):
        if not wins[b]:
            horiz_counts = np.sum(marked[b, ...], axis=0)
            vert_counts = np.sum(marked[b, ...], axis=1)

            if np.any(horiz_counts == 5) or np.any(vert_counts == 5):
                result.append(b)

    return result


def play(input_file: str, to_the_end: bool) -> int:
    draw = np.genfromtxt(input_file, max_rows=1, delimiter=',', dtype=int)
    board = np.genfromtxt(input_file, skip_header=1, dtype=int)
    board = board.reshape((board.shape[0] // 5, 5, 5))
    marked = np.zeros_like(board, dtype=bool)
    wins = np.zeros(marked.shape[0])
    last_won_score = 0

    for picked in draw:
        marked[board == picked] = True

        res = check_bingo(marked, wins)
        if len(res) > 0:
            for r in res:
                last_won_score = np.sum(board[r, ~marked[r, ...]]) * picked
                wins[r] = True
                if not to_the_end:
                    return last_won_score

    return last_won_score


def part1(input_file: str) -> int:
    return play(input_file, False)


def part2(input_file: str) -> int:
    return play(input_file, True)
