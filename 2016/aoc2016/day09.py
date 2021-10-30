def handle_sequence(rest: str, recursive: bool) -> int:
    result = 0

    if '(' not in rest:
        return len(rest)

    while '(' in rest:
        start = rest.find('(')
        end = rest.find(')')
        block = rest[start + 1:end]
        block_split = block.split('x')
        count = int(block_split[0])
        repeat = int(block_split[1])
        length = start + count * repeat
        final = end + 1 + count

        if recursive:
            length = start + handle_sequence(rest[end + 1:final], True) * repeat

        rest = rest[final:]
        result += length

    return result


def part1(input: str) -> int:
    return handle_sequence(input, False)


def part2(input: str) -> int:
    return handle_sequence(input, True)
