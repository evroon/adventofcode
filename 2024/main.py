import argparse
import importlib
import sys


def run_day(day: int, is_part_two: bool = False) -> str:
    input_file = f"inputs/day{day:02d}.txt"

    try:
        day_import = importlib.import_module(f"python.day{day:02d}", package="python")
        function = day_import.part1

        if is_part_two:
            function = day_import.part2

        return function(input_file)

    except ImportError:
        sys.exit(f"Invalid day: {day}")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("day", type=int)
    parser.add_argument("-2", "--part2", action="store_true")

    args = parser.parse_args()
    result = run_day(args.day, args.part2)
    print(result)


if __name__ == "__main__":
    main()
