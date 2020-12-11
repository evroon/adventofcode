#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

#include "manager.h"

int traverse_slope(const std::vector<std::string>& map, uint offset_x, uint offset_y)
{
    uint result = 0;
    uint width = map[0].size();
    uint x = 0;

    for (int y = 0; y < map.size(); y += offset_y) {
        if (map[y][x % width] == '#')
            result++;

        x += offset_x;
    }
    return result;
}

R day3_part2(std::ifstream& input)
{
    std::string line;
    std::vector<std::string> map;

    while (std::getline(input, line))
        map.push_back(line);

    return traverse_slope(map, 1, 1) * traverse_slope(map, 3, 1) * traverse_slope(map, 5, 1) *
        traverse_slope(map, 7, 1) * traverse_slope(map, 1, 2);
}

ADD_SOLUTION(3)
