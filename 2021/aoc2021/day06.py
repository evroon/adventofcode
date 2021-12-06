from collections import Counter


def run(days: int, input_file: str) -> int:
    with open(input_file) as f:
        fish = Counter(map(int, f.read().split(',')))

    for _ in range(days):
        new_fish = {timer - 1: count for timer, count in fish.items()}
        new_fish.pop(-1, 0)
        if 0 in fish:
            new_fish[8] = fish[0]
            new_fish[6] = fish[0] + new_fish.get(6, 0)

        fish = new_fish

    return sum(fish.values())


def part1(input_file: str) -> int:
    return run(80, input_file)


def part2(input_file: str) -> int:
    return run(256, input_file)
