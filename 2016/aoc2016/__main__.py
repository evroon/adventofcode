import argparse
from .run import run_day


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument('day', type=int)
    parser.add_argument('-2', '--part2', action='store_true')

    args = parser.parse_args()
    result = run_day(args.day, args.part2)
    print(result)


if __name__ == '__main__':
    main()
