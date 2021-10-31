from .utils import get_text_in_between_reverse


def get_value(src: str, registers: dict) -> int:
    if src.isnumeric():
        return int(src)

    return registers[src]


def run_program(input: str, registers: dict) -> int:
    instructions = input.split('\n')[:-1]
    i = 0

    while i < len(instructions):
        instr = instructions[i]

        if instr.startswith('cpy '):
            src = get_text_in_between_reverse(instr, 'cpy ', ' ')
            dst = instr.split(' ')[-1]
            registers[dst] = get_value(src, registers)
        elif instr.startswith('inc '):
            dst = instr.split(' ')[-1]
            registers[dst] += 1
        elif instr.startswith('dec '):
            dst = instr.split(' ')[-1]
            registers[dst] -= 1
        elif instr.startswith('jnz '):
            x = get_text_in_between_reverse(instr, 'jnz ', ' ')
            x = get_value(x, registers)
            shift = int(instr.split(' ')[-1])
            if x != 0:
                i += shift
                continue

        i += 1

    return registers['a']


def part1(input: str) -> int:
    registers = {
        'a': 0,
        'b': 0,
        'c': 0,
        'd': 0,
    }
    return run_program(input, registers)


def part2(input: str) -> int:
    registers = {
        'a': 0,
        'b': 0,
        'c': 1,
        'd': 0,
    }
    return run_program(input, registers)
