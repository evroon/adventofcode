import numpy as np

def simulate(route):
    pos = 0 + 0j
    headings = {
        "U":  0 + 1j,
        "D":  0 - 1j,
        "L": -1 + 0j,
        "R":  1 + 0j,
    }
    history = np.zeros(len(route) * 999, dtype=complex)
    c = 0

    for i, instruction in enumerate(route):
        for j in range(int(instruction[1:])):
            pos += headings[instruction[0]]
            history[c] = pos
            c += 1

    history.resize(c)
    return history

input = np.genfromtxt('input.txt', delimiter=',', dtype="|U16")

path1 = simulate(input[0, :])
path2 = simulate(input[1, :])

C = np.intersect1d(path1, path2)
indices1 = np.asarray([np.where(path1 == C[x])[0][0] for x in range(len(C))])
indices2 = np.asarray([np.where(path2 == C[x])[0][0] for x in range(len(C))])

print((indices1 + indices2).min() + 2)