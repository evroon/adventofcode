from typing import List, Tuple


def get_part_in_string(src: str, start: str, end: str) -> Tuple[List[str], List[str]]:
    rest = src
    inside, outside = [], []

    while start in rest:
        split_start = rest.split(start)
        inside.append(
            split_start[1].split(end)[0]
        )
        outside.append(split_start[0])
        rest = rest.split(end, maxsplit=1)[1]

    outside.append(rest)
    return inside, outside


def get_text_in_between(src: str, left: str, right: str) -> str:
    return src.split(right)[0].split(left)[1]


def get_text_in_between_reverse(src: str, left: str, right: str) -> str:
    return src.split(left)[1].split(right)[0]
