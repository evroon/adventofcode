from typing import Tuple


def part1(input: str) -> int:
    triangles = input.split('\n')
    result = 0

    for triangle in triangles[:-1]:
        side1 = int(triangle[:5].strip())
        side2 = int(triangle[5:10].strip())
        side3 = int(triangle[10:].strip())
        sides = [side1, side2, side3]
        success = True

        for i in range(3):
            j = (i + 1) % 3
            k = (i + 2) % 3
            print(i, j, k)

            if sides[j] + sides[k] <= sides[i]:
                success = False
                break

        if success:
            result += 1

    return result


def part2(input: str) -> int:
    pass