import numpy as np


def part1(input: str) -> int:
    screen = np.zeros((6, 50))
    instructions = input.split('\n')

    for instruction in instructions[:-1]:
        if instruction.startswith('rect '):
            args = instruction.split(' ')[1]
            width = int(args.split('x')[0])
            height = int(args.split('x')[1])
            screen[:height, :width] = 1
        elif instruction.startswith('rotate row '):
            args = instruction.split('=')[1]
            row = int(args.split(' by ')[0])
            shift = int(args.split(' by ')[1])
            screen[row, :] = np.roll(screen[row, :], shift)
        elif instruction.startswith('rotate column '):
            args = instruction.split('=')[1]
            column = int(args.split(' by ')[0])
            shift = int(args.split(' by ')[1])
            screen[:, column] = np.roll(screen[:, column], shift)

    for y in range(screen.shape[0]):
        for x in range(screen.shape[1]):
            if x % 5 == 0:
                print('\t', end='')
            print('★' if screen[y, x] else ' ', end='')
        print()

    return int(np.sum(screen))
