import importlib
import sys


def run_day(day: int, is_part_two: bool = False) -> str:
    input_file = f'2016/inputs/day{day:02d}.txt'

    try:
        day = importlib.import_module(f'.day{day:02d}', __package__)
        function = day.part1

        if is_part_two:
            function = day.part2

        with open(input_file, 'r') as f:
            return function(f.read())

    except ImportError:
        sys.exit(f'Invalid day: {day}')