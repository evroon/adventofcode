import argparse
from .run import run_day


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument('day', type=str)
    parser.add_argument('-2', '--part2', action='store_true')

    args = parser.parse_args()
    day = args.day

    # Extract day from file name.
    if 'day' in day:
        day = int(day[3:5])
    else:
        day = int(day)

    result = run_day(day, args.part2)
    print(result)


if __name__ == '__main__':
    main()
