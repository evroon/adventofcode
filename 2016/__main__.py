import argparse
import importlib
import sys


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument('day', type=int)
    parser.add_argument('-2', '--part2', action='store_true')

    args = parser.parse_args()
    input_file = f'2016/inputs/day{args.day:02d}.txt'

    try:
        day = importlib.import_module(f'.day{args.day:02d}', __package__)

        if args.part2:
            function = day.part2
        else:
            function = day.part1

        with open(input_file, 'r') as f:
            print(function(f.read()))

    except ImportError:
        sys.exit(f'Invalid day: {args.day}')


main()
