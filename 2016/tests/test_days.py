import pytest
import itertools
from aoc2016.run import run_day


outcomes = {
    1: [242, 150],
    2: ['84452', 'D65C3'],
    3: [869, None]
}


@pytest.mark.parametrize(
    'day,is_part_two',
    itertools.product(
        range(1, 32),
        [False, True]
    )
)
def test_day(day: int, is_part_two: bool) -> None:
    if day not in outcomes:
        return

    expected = outcomes[day][1 if is_part_two else 0]
    assert expected == run_day(day, is_part_two)
