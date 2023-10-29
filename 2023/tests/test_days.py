import pytest
import itertools
from python.run import run_day


outcomes = {
    1: [0, 0],
}


@pytest.mark.parametrize(
    "day,is_part_two", itertools.product(outcomes.keys(), [False, True])
)
def test_day(day: int, is_part_two: bool) -> None:
    expected = outcomes[day][1 if is_part_two else 0]
    if expected is None:
        pytest.skip("Not a suitable test case.")

    assert expected == run_day(day, is_part_two)
