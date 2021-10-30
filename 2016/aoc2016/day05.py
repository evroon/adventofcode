import hashlib


def part1(input: str) -> str:
    password = []
    i = 0

    while len(password) < 8:
        to_hash = input + str(i)
        hash = hashlib.md5(to_hash.encode()).hexdigest()

        if hash[:5] == '00000':
            password.append(hash[5])

        i += 1

    return ''.join(password)


def part2(input: str) -> str:
    password = [''] * 8
    i = 0
    c = 0

    while c < 8:
        to_hash = input + str(i)
        hash = hashlib.md5(to_hash.encode()).hexdigest()

        if hash[:5] == '00000' and hash[5].isnumeric() and int(hash[5]) < 8 and password[int(hash[5])] == '':
            password[int(hash[5])] = hash[6]
            c += 1

        i += 1

    return ''.join(password)
