from collections import Counter


def part1(input_file: str) -> int:
    result = 0
    with open(input_file, "r") as f:
        for line in f.readlines():
            i = 0
            while i < len(line):
                start = line[i:].find("mul(") + i
                end = line[start:].find(")") + start

                if start < i:
                    break

                split = line[start + 4 : end].split(",")
                if len(split) != 2:
                    i = start + 4
                    continue
                else:
                    l, r = split
                    if any(not t.isdigit() for t in l) or any(
                        not t.isdigit() for t in r
                    ):
                        i = start + 4
                        continue
                l, r = int(l), int(r)
                i = start + 4
                result += l * r

    return result


def part2(input_file: str) -> int:
    result = 0
    enabled = True
    with open(input_file, "r") as f:
        for line in f.readlines():
            i = 0
            while i < len(line):
                start_do = line[i:].find("do()") + i
                start_dont = line[i:].find("don't()") + i

                start = line[i:].find("mul(") + i
                end = line[start:].find(")") + start

                if start_do - i == -1:
                    start_do = 1e9

                if start_dont - i == -1:
                    start_dont = 1e9

                if min(start_do, start_dont, start) == start_dont:
                    i = start_dont + 4
                    enabled = False
                    continue

                if min(start_do, start_dont, start) == start_do:
                    i = start_do + 4
                    enabled = True
                    continue

                if not enabled:
                    i = start + 4
                    continue

                if start - i == -1:
                    break

                split = line[start + 4 : end].split(",")
                if len(split) != 2:
                    i = start + 4
                    continue
                else:
                    l, r = split
                    if any(not t.isdigit() for t in l) or any(
                        not t.isdigit() for t in r
                    ):
                        i = start + 4
                        continue

                l, r = int(l), int(r)
                i = start + 4
                result += l * r

    return result
