def get_elves(input_file: str, include_elves_count: int) -> int:
    current = 0
    elves = []

    with open(input_file, 'r') as f:
        for line in f.readlines():
            if line == '\n':
                elves.append(current)

                current = 0
            else:
                current += int(line)

    return sum(sorted(elves, reverse=True)[:include_elves_count])


def part1(input_file: str) -> int:
    return get_elves(input_file, 1)


def part2(input_file: str) -> int:
    return get_elves(input_file, 3)
