import importlib
import sys


def run_day(day: int, is_part_two: bool = False) -> str:
    input_file = f'inputs/day{day:02d}.txt'

    try:
        day_import = importlib.import_module(f'day{day:02d}', package='python')
        function = day_import.part1

        if is_part_two:
            function = day_import.part2

        return function(input_file)

    except ImportError:
        sys.exit(f'Invalid day: {day}')
