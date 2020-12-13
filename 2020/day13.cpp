#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string_view>
#include <algorithm>
#include <math.h>

#include "manager.h"

R day13_part1(std::ifstream& input)
{
    std::string line;
    int id = -1, min = INT16_MAX;

    std::getline(input, line);
    int start = atoi(line.c_str());

    std::getline(input, line);
    auto buses = split_string(line, ",");

    for (const std::string& bus_str: buses) {
        if (bus_str == "x")
            continue;

        int bus = atoi(bus_str.c_str());
        int a = bus - start % bus;
        if (start % bus == 0)
            a = 0;

        if (a < min) {
            min = a;
            id = bus;
        }
    }
    return id * min;
}

R day13_part2(std::ifstream& input)
{
    std::string line;
    R period = 1;
    R t = 0;
    int x = 0;

    std::getline(input, line);
    std::getline(input, line);

    for (const std::string& bus_str: split_string(line, ",")) {
        if (bus_str != "x") {
            const int bus = atoi(bus_str.c_str());

            while ((t + x) % bus != 0)
                t += period;

            period = lcm(period, bus);
        }
        x++;
    }

    return t;
}

ADD_SOLUTION(13)
