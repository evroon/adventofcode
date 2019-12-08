import numpy as np

def simulate(route):
    pos = np.zeros(2, dtype=int)
    headings = {
        "U": np.asarray([0, +1], dtype=int),
        "D": np.asarray([0, -1], dtype=int),
        "L": np.asarray([-1, 0], dtype=int),
        "R": np.asarray([+1, 0], dtype=int),
    }
    history = np.zeros((len(route) * 999, 2), dtype=int)
    c = 0

    for i, instruction in enumerate(route):
        for j in range(int(instruction[1:])):
            pos += headings[instruction[0]]
            history[c] = pos
            c += 1

    history.resize((c, 2))

    return history

input = np.genfromtxt('input.txt', delimiter=',', dtype="|U16")

path1 = simulate(input[0, :])
path2 = simulate(input[1, :])

nrows, ncols = path1.shape
dtype1={'names':['f{}'.format(i) for i in range(ncols)],
       'formats':ncols * [path1.dtype]}

nrows, ncols = path2.shape
dtype2={'names':['f{}'.format(i) for i in range(ncols)],
       'formats':ncols * [path2.dtype]}

C = np.intersect1d(path1.view(dtype1), path2.view(dtype2))
C = C.view(path1.dtype).reshape(-1, ncols)

print(np.sum(np.abs(C), axis=1).min())