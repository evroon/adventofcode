#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string_view>

#include "manager.h"

int day9_part1(std::ifstream& input)
{
    std::string line;
    int pointer = 0;
    int preamble = 25;

    std::vector<int> list;

    while (std::getline(input, line)) {
        list.push_back(atoi(line.c_str()));
    }

    for (int c = preamble; c < list.size(); c++) {
        bool found = false;
        for (int x = c - preamble; x < c; x++) {
            for (int y = c - preamble; y < c; y++) {
                if (list[x] + list[y] == list[c])
                    found = true;
            }
        }
        if (!found)
            return list[c];
    }
    return -1;
}

int day9_part2(std::ifstream& input)
{
    std::string line;
    int pointer = 0;
    int preamble = 25;

    std::vector<int> list;

    while (std::getline(input, line)) {
        list.push_back(atoi(line.c_str()));
    }

    for (int x = 0; x < list.size(); x++) {
        for (int y = x; y < list.size(); y++) {
            int result = 0;

            for (int c = x; c <= y; c++) {
                result += list[c];
            }

            if (result == 1124361034) {
                std::vector<int> array;
                for (int c = x; c <= y; c++)
                    array.push_back(list[c]);

                auto min_max = min_and_max(array);
                return min_max.first + min_max.second;
            }
        }
    }
    return -1;
}

ADD_SOLUTION(9)
