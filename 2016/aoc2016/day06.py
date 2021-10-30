from collections import Counter


def error_correct(input: str, sort_sign: int) -> str:
    messages = input.split('\n')
    columns = [''] * 8
    result = ''

    for message in messages[:-1]:
        for i in range(8):
            columns[i] += message[i]

    for column in columns:
        counter = Counter(column)
        letters_sorted = sorted(counter.items(), key=lambda item: sort_sign * item[1])
        result += letters_sorted[0][0]

    return result


def part1(input: str) -> str:
    return error_correct(input, -1)


def part2(input: str) -> str:
    return error_correct(input, 1)
