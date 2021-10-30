from collections import defaultdict

from .utils import get_text_in_between


def handle_chip(bot_id: int, instr: str, is_high: bool, bots, outputs) -> int:
    type = instr.split(' ')[0]
    out = int(instr.split(' ')[1])
    chips = bots[bot_id]
    selected_chip = max(chips) if is_high else min(chips)

    # Bot gives away its chip.
    if type == 'output':
        outputs[out].append(selected_chip)
    elif type == 'bot':
        bots[out].append(selected_chip)

    # Bot loses its chip.
    for i, c in enumerate(chips):
        if c == selected_chip:
            del chips[i]

    return selected_chip


def get_invalid_bot(bots) -> int:
    for i, b in bots.items():
        if len(b) > 1:
            return i

    return -1


def run(input: str, is_part1: bool) -> int:
    instruction_lines = {}
    bots = defaultdict(list)
    outputs = defaultdict(list)
    inits = input.split('\n')

    for i, instr in enumerate(inits[:-1]):
        if instr.startswith('value '):
            val = int(get_text_in_between(instr, 'value ', ' goes to bot '))
            dest = int(instr.split(' goes to bot ')[1])
            bots[dest].append(val)
        else:
            bot_id = int(get_text_in_between(instr, 'bot ', ' gives'))
            instruction_lines[bot_id] = i

    current_bot = get_invalid_bot(bots)

    while current_bot >= 0:
        instr_line = instruction_lines[current_bot]
        instr = inits[instr_line]

        if instr.startswith('bot '):
            bot_id = int(get_text_in_between(instr, 'bot ', ' gives'))
            low_to = get_text_in_between(instr, 'low to ', ' and ')
            high_to = instr.split('high to ')[1]

            bot1 = handle_chip(bot_id, low_to, False, bots, outputs)
            bot2 = handle_chip(bot_id, high_to, True, bots, outputs)

            if is_part1 and 61 in [bot1, bot2] and 17 in [bot1, bot2]:
                return current_bot

            current_bot = get_invalid_bot(bots)

    return outputs[0][0] * outputs[1][0] * outputs[2][0]


def part1(input: str) -> int:
    return run(input, True)


def part2(input: str) -> int:
    return run(input, False)
