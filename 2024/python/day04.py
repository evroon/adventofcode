def count_xmas(val: str) -> int:
    return val.count("XMAS") + val.count("SAMX")


def part1(input_file: str) -> int:
    result = 0
    with open(input_file, "r") as f:
        lines = [x.strip() for x in f.readlines()]

    mirrored = ["".join([line[col] for line in lines]) for col in range(len(lines))]

    for obj in (lines, mirrored):
        for col in obj:
            result += count_xmas(col)

    width = len(obj[0])

    # Count diagonals once
    result += count_xmas("".join([lines[k][k] for k in range(width)]))
    result += count_xmas("".join([lines[::-1][k][k] for k in range(width)]))

    # Count offset diagonals without centered diagonals
    for col in range(1, width):
        result += count_xmas("".join([lines[k][col + k] for k in range(width - col)]))
        result += count_xmas(
            "".join([lines[::-1][k][col + k] for k in range(width - col)])
        )
        result += count_xmas(
            "".join([lines[::-1][k][::-1][col + k] for k in range(width - col)])
        )
        result += count_xmas(
            "".join([lines[k][::-1][col + k] for k in range(width - col)])
        )

    return result


def part2(input_file: str) -> int:
    result = 0
    with open(input_file, "r") as f:
        lines = [x.strip() for x in f.readlines()]

    rows, cols = len(lines), len(lines[0])
    assert rows == cols

    lines2 = [line[::-1] for line in lines]
    mirrored1 = ["".join([line[col] for line in lines]) for col in range(cols)]
    mirrored2 = ["".join([line[col] for line in lines[::-1]]) for col in range(cols)]

    for obj in (lines, lines2, mirrored1, mirrored2):
        for row in range(rows - 2):
            for col in range(cols - 2):
                if (
                    obj[row][col] == "M"
                    and obj[row + 2][col] == "M"
                    and obj[row][col + 2] == "S"
                    and obj[row + 2][col + 2] == "S"
                    and obj[row + 1][col + 1] == "A"
                ):
                    result += 1

    return result
