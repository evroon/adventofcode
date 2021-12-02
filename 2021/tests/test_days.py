import pytest
import itertools
from aoc2021.run import run_day


outcomes = {
    1: [1688, 1728],
    2: [2150351, 1842742223],
}


@pytest.mark.parametrize(
    'day,is_part_two',
    itertools.product(
        outcomes.keys(),
        [False, True]
    )
)
def test_day(day: int, is_part_two: bool) -> None:
    expected = outcomes[day][1 if is_part_two else 0]
    assert expected == run_day(day, is_part_two)
