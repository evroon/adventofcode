from typing import List

from .utils import get_part_in_string


def check_abba(sequence: str) -> bool:
    for i in range(len(sequence) - 3):
        first = sequence[i:i+2]
        second = sequence[i+2:i+4]
        if first == second[::-1] and first != second:
            return True

    return False


def check_ssl(insides, outsides) -> bool:
    abas: List[str] = []

    for i in insides:
        for j in range(len(i) - 2):
            aba = i[j:j+3]
            if aba not in abas and aba[1] != aba[0] and aba[0] == aba[2]:
                abas.append(aba)

    for o in outsides:
        for a in abas:
            bab = a[1] + a[0] + a[1]
            if bab in o:
                return True

    return False


def part1(input: str) -> int:
    ips = input.split('\n')
    result = 0

    for ip in ips[:-1]:
        inside_parts, outside_parts = get_part_in_string(ip, '[', ']')
        found_negative = False
        found_positive = False

        for part in inside_parts:
            if check_abba(part):
                found_negative = True

        for part in outside_parts:
            if check_abba(part):
                found_positive = True

        if found_positive and not found_negative:
            result += 1

    return result


def part2(input: str) -> int:
    ips = input.split('\n')
    result = 0

    for ip in ips[:-1]:
        inside_parts, outside_parts = get_part_in_string(ip, '[', ']')
        if check_ssl(inside_parts, outside_parts):
            result += 1

    return result
