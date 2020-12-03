#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <map>

#include "manager.h"

#include "day01.cpp"
#include "day02.cpp"
#include "day03.cpp"

int run_day(uint day)
{
    std::ifstream input;
    int (*function)(std::ifstream &input) = nullptr;
    int result = -1;
    auto days = SolutionManager::get_singleton()->days;

    if (days.count(day) > 0) {
        function = days[day];
    } else {
        std::cout << "Invalid day: " << day << std::endl;
        return -1;
    }

    char path[96];
    sprintf(path, "../inputs/day%02d.txt", day);
    input = std::ifstream(path);

    auto start = std::chrono::high_resolution_clock::now();
    result = function(input);
    auto stop = std::chrono::high_resolution_clock::now();

    int duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    std::cout << "Duration: " << duration << std::endl;

    return result;
}