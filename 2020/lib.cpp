#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <map>

#include "manager.h"
#include "utils.h"

#include "day01.cpp"
#include "day02.cpp"
#include "day03.cpp"
#include "day04.cpp"
#include "day05.cpp"
#include "day06.cpp"
#include "day07.cpp"
#include "day08.cpp"
#include "day09.cpp"
#include "day10.cpp"
#include "day11.cpp"
#include "day12.cpp"
#include "day13.cpp"
#include "day14.cpp"
#include "day15.cpp"
#include "day16.cpp"
#include "day17.cpp"
#include "day18.cpp"
#include "day19.cpp"
#include "day20.cpp"
#include "day21.cpp"
#include "day22.cpp"
#include "day23.cpp"
#include "day24.cpp"
#include "day25.cpp"
#include "day26.cpp"
#include "day27.cpp"
#include "day28.cpp"
#include "day29.cpp"
#include "day30.cpp"
#include "day31.cpp"

R run_day(uint day)
{
    std::ifstream input;
    R (*function)(std::ifstream &input) = nullptr;
    R result = -1;
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
    std::cout << "Duration: " << duration << "µs" << std::endl;

    return result;
}