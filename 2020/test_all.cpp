#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "lib.cpp"

std::vector<uint> days;
std::map<uint, uint> expected_outputs = {
    {1, 23869440},
    {2, 354},
    {3, 1666768320},
    {4, 186}
};

class CombinationsTest :
    public ::testing::TestWithParam<uint> {};

TEST_P(CombinationsTest, Basic) {
    uint day_index = GetParam();
    auto function = SolutionManager::get_singleton()->days[day_index];

    ASSERT_EQ(expected_outputs[day_index], run_day(day_index));
}

INSTANTIATE_TEST_CASE_P(AllCombinations,
                        CombinationsTest,
                        ::testing::ValuesIn(days));

int main(int argc, char **argv)
{
    for (auto day : SolutionManager::get_singleton()->days) {
        days.push_back(day.first);
    }

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
