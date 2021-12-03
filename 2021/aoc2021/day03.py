def get_rates(commands):
    assert len(commands) > 0
    bit_len = len(commands[0])

    gamma_rate, epsilon_rate = [0] * bit_len, [0] * bit_len
    bit_count = [0] * bit_len
    commands_len = len(commands)

    for command in commands:
        for i in range(bit_len):
            bit_count[i] += int(command[i])

    for i in range(bit_len):
        gamma_rate[i] = 0 if bit_count[i] < commands_len / 2 else 1
        epsilon_rate[i] = 1 - gamma_rate[i]

    return gamma_rate, epsilon_rate


def part1(input: str) -> int:
    commands = input.split('\n')[:-1]
    gamma_rate, epsilon_rate = get_rates(commands)
    gamma_rate_dec = int(''.join([str(x) for x in gamma_rate]), 2)
    epsilon_rate_dec = int(''.join([str(x) for x in epsilon_rate]), 2)
    return gamma_rate_dec * epsilon_rate_dec


def part2(input: str) -> int:
    commands = input.split('\n')[:-1]
    bit_len = len(commands[0])
    oxygen_result, co2_result = commands.copy(), commands.copy()
    o2_out = None
    co2_out = None

    for bit in range(bit_len):
        if len(oxygen_result) > 0:
            gamma_rate, epsilon_rate = get_rates(oxygen_result)
            if len(oxygen_result) == 2:
                gamma_rate[-1] = 0

            i = 0
            while i < len(oxygen_result):
                command = oxygen_result[i]
                if int(command[bit]) != gamma_rate[bit]:
                    o2_out = command
                    oxygen_result.remove(command)
                    i -= 1

                i += 1

        if len(co2_result) > 0:
            _, epsilon_rate = get_rates(co2_result)

            i = 0
            while i < len(co2_result):
                command = co2_result[i]
                if int(command[bit]) != epsilon_rate[bit]:
                    co2_out = command
                    co2_result.remove(command)
                    i -= 1

                i += 1

    a = int(o2_out, 2)
    b = int(co2_out, 2)
    return a * b
