from collections import Counter


def get_violations(ints):
    diffs = [v - ints[i - 1] if i > 0 else 0 for i, v in enumerate(ints)][1:]
    ups = sum(1 for d in diffs if d > 0)
    downs = sum(1 for d in diffs if d < 0)
    equals = sum(1 for d in diffs if d == 0)
    out_of_range = sum(1 for d in diffs if d < -3 or d > 3)
    return min(ups, downs) + equals + out_of_range


def part1(input_file: str) -> int:
    result = 0
    with open(input_file, "r") as f:
        for line in f.readlines():
            ints = [int(v) for v in line.split(" ")]
            if get_violations(ints) == 0:
                result += 1
    return result


def part2(input_file: str) -> int:
    result = 0
    with open(input_file, "r") as f:
        for line in f.readlines():
            ints_orig = [int(v) for v in line.split(" ")]
            min_violations = get_violations(ints_orig)

            for u in range(len(ints_orig)):
                ints = [v for i, v in enumerate(ints_orig) if i != u]
                min_violations = min(min_violations, get_violations(ints))

            if min_violations < 1:
                result += 1
    return result
