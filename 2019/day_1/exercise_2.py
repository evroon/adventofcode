import numpy as np

input = np.genfromtxt('input.txt')
result = np.zeros(len(input))

for i, x in enumerate(input):
    while True:
        x /= 3
        x = np.floor(x)
        x -= 2

        if x > 0:
            result[i] += x
        else:
            break


result = np.sum(result)

print("sum of fuel requirements is: {:.0f}".format(result))