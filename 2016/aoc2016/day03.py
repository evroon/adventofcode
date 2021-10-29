from typing import List


def check_triangle(triangle: List[int]) -> bool:
    for i in range(3):
        j = (i + 1) % 3
        k = (i + 2) % 3

        if triangle[j] + triangle[k] <= triangle[i]:
            return False

    return True


def part1(input: str) -> int:
    triangles = input.split('\n')
    result = 0

    for triangle in triangles[:-1]:
        sides = []
        for i, j in enumerate(range(0, 3)):
            sides.append(int(triangle[j*5:(j+1)*5].strip()))

        if check_triangle(sides):
            result += 1

    return result


def part2(input: str) -> int:
    triangles = input.split('\n')
    result = 0

    for r in range(len(triangles) // 3):
        rows: List[str] = [
            triangles[r*3],
            triangles[r*3+1],
            triangles[r*3+2],
        ]

        triangle_set = [
            [0, 0, 0],
            [0, 0, 0],
            [0, 0, 0],
        ]

        for t in range(3):
            for j in range(3):
                triangle_set[t][j] = int(rows[j][t*5:(t+1)*5].strip())

        for t in triangle_set:
            if check_triangle(t):
                result += 1

    return result