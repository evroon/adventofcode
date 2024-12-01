from collections import Counter


def part1(input_file: str) -> int:
    left, right = [], []
    with open(input_file, "r") as f:
        for line in f.readlines():
            l, r = line.split("   ")
            left.append(int(l))
            right.append(int(r))

    left.sort()
    right.sort()
    return sum(abs(l - r) for l, r in zip(left, right))


def part2(input_file: str) -> int:
    left, right = [], []
    with open(input_file, "r") as f:
        for line in f.readlines():
            l, r = line.split("   ")
            left.append(int(l))
            right.append(int(r))

    left.sort()
    right_count = Counter(right)
    return sum(l * right_count[l] for l in left)
