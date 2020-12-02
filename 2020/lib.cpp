#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "day01.cpp"
#include "day02.cpp"

int run_day(int day)
{
    std::ifstream input;
    int result = -1;

    switch (day)
    {
    case 1:
        input = std::ifstream("inputs/day01.txt");
        result = day1_part2(input);
        break;

    case 2:
        input = std::ifstream("inputs/day02.txt");
        result = day2_part2(input);
        break;

    default:
        break;
    }

    return result;
}