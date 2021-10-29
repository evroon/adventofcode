from collections import Counter


def part1(input: str) -> int:
    rooms = input.split('\n')
    result = 0

    for room in rooms[:-1]:
        input_split = room.split('[')
        name = input_split[0]
        room_id = int(name.split('-')[-1])
        checksum = input_split[1][:-1]

        counter = Counter(name)
        letters = {k: v for (k, v) in counter.items() if 'a' <= k <= 'z'}
        letters_sorted = sorted(letters.items(), key=lambda item: -item[1] * 100 + ord(item[0]))
        top_occurrences = ''.join([x[0] for x in letters_sorted[:5]])

        if top_occurrences == checksum:
            result += room_id

    return result


def decrypt(name: str, room_id: int) -> str:
    name = list(name.replace('-', ' '))

    for i, x in enumerate(name):
        if x == ' ':
            continue
        name[i] = chr(ord('a') + ((ord(x) + room_id - ord('a')) % 26))

    return ''.join(name)


def part2(input: str) -> int:
    rooms = input.split('\n')
    result = 0

    for room in rooms[:-1]:
        input_split = room.split('[')
        room_id = int(input_split[0].split('-')[-1])
        name = decrypt(input_split[0], room_id)
        checksum = input_split[1][:-1]

        if 'north' in name:
            return room_id

    return -1
