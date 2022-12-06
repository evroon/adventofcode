def get_first_marker_pos(input_file: str, marker_size: int) -> int:
    with open(input_file, "r") as f:
        packet = f.readline()
        for c, _ in enumerate(packet):
            if len(set(packet[c : c + marker_size])) == marker_size:
                return c + marker_size

    return -1



def part1(input_file: str) -> int:
    return get_first_marker_pos(input_file, 4)


def part2(input_file: str) -> int:
    return get_first_marker_pos(input_file, 14)
