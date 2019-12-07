import numpy as np

input = np.genfromtxt('input.txt', delimiter=',', dtype=int)
input[1] = 12
input[2] = 2

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

print("result is: {}".format(input[0]))