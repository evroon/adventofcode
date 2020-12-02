#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "lib.cpp"

TEST(Day1Test, InputTest) {
    ASSERT_EQ(23869440, run_day(1));
}

TEST(Day2Test, InputTest) {
    ASSERT_EQ(354, run_day(2));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
