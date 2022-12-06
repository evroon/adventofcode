def get_score(you, me) -> int:
    shape_score = {
        "X": 1,
        "Y": 2,
        "Z": 3,
    }[me]

    won = {
        "Z": "B",
        "Y": "A",
        "X": "C",
    }[me] == you

    draw = ord(me) - ord("X") + ord("A") == ord(you)

    outcome = 0
    if won:
        outcome = 6
    elif draw:
        outcome = 3

    return shape_score + outcome


def part1(input_file: str) -> int:
    score = 0
    with open(input_file, "r") as f:
        for line in f.readlines():
            score += get_score(*line.strip().split(" "))

    return score


def get_score_part2(you, end) -> int:
    result = 0

    if end == "Y":
        # Draw
        me = chr(ord(you) + ord("X") - ord("A"))
        result += 3
    elif end == "X":
        # Loss
        me = {
            "A": "Z",
            "B": "X",
            "C": "Y",
        }[you]
    else:
        # Win
        me = {
            "A": "Y",
            "B": "Z",
            "C": "X",
        }[you]
        result += 6

    shape_score = {
        "X": 1,
        "Y": 2,
        "Z": 3,
    }[me]
    return shape_score + result


def part2(input_file: str) -> int:
    score = 0
    with open(input_file, "r") as f:
        for line in f.readlines():
            score += get_score_part2(*line.strip().split(" "))

    return score
