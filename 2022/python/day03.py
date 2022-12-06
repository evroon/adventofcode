def get_common_item_score(comp1: str, comp2: str) -> int:
    [common_item] = set(comp1) & set(comp2)
    return (
        ord(common_item) + 27 - ord("A")
        if ord("A") <= ord(common_item) <= ord("Z")
        else ord(common_item) - ord("a") + 1
    )


def part1(input_file: str) -> int:
    score = 0

    with open(input_file, "r") as f:
        for line in f.readlines():
            line = line.strip()
            halfway = len(line) // 2
            score += get_common_item_score(line[:halfway], line[halfway:])

    return score


def get_common_item_score_part2(comp1: str, comp2: str, comp3: str) -> int:
    [common_item] = set(comp1) & set(comp2) & set(comp3)
    return (
        ord(common_item) + 27 - ord("A")
        if ord("A") <= ord(common_item) <= ord("Z")
        else ord(common_item) - ord("a") + 1
    )


def part2(input_file: str) -> int:
    score = 0

    with open(input_file, "r") as f:
        lines = f.readlines()

        for i in range(len(lines) // 3):
            group = [line.strip() for line in lines[i * 3 : i * 3 + 3]]
            score += get_common_item_score_part2(group[0], group[1], group[2])

    return score
