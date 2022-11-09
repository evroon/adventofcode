def part1(input: str) -> int:
    frequency = 0
    for i in input.split('\n')[:-1]:
        frequency += int(i)

    return frequency


def part2(input: str) -> int:
    frequency = 0
    history = []

    changes = input.split('\n')[:-1]
    c = 0

    while True:
        frequency += int(changes[c])

        if frequency in history:
            return frequency

        history.append(frequency)
        c += 1
        c %= len(changes)
