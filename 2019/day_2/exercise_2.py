import numpy as np

data = np.genfromtxt('input.txt', delimiter=',', dtype=int)

def run_program(noun, verb):
    input = np.copy(data)
    input[1] = noun
    input[2] = verb

    i = 0

    while i < len(input):
        op = input[i]

        if op == 99:
            break

        a = input[i + 1]
        b = input[i + 2]
        c = input[i + 3]

        if op == 1:
            input[c] = input[a] + input[b]
        elif op == 2:
            input[c] = input[a] * input[b]

        i += 4
    
    return input[0]

for n in range(100):
    for v in range(100):
        if run_program(n, v) == 19690720:
            print(100 * n + v)
