def part1(input: str) -> int:
    position = (0, 0)
    commands = input.split('\n')[:-1]

    for command in commands:
        command_arg = int(command.split(' ')[1])
        if command.startswith('forward'):
            position = (position[0] + command_arg, position[1])
        elif command.startswith('down'):
            position = (position[0], position[1] + command_arg)
        elif command.startswith('up'):
            position = (position[0], position[1] - command_arg)

    return position[0] * position[1]


def part2(input: str) -> int:
    position = (0, 0)
    aim = 0
    commands = input.split('\n')[:-1]

    for command in commands:
        command_arg = int(command.split(' ')[1])
        if command.startswith('forward'):
            position = (position[0] + command_arg, position[1] + aim * command_arg)
        elif command.startswith('down'):
            aim += command_arg
        elif command.startswith('up'):
            aim -= command_arg

    return position[0] * position[1]
