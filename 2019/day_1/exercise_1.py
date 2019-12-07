import numpy as np

input = np.genfromtxt('input.txt')

input /= 3
input = np.floor(input)
input -= 2

result = np.sum(input)

print("sum of fuel requirements is: {:.0f}".format(result))