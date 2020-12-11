#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string_view>
#include <algorithm>

#include "manager.h"

R day10_part1(std::ifstream& input)
{
    std::string line;
    std::vector<int> list;
    std::map<int, int> map;

    while (std::getline(input, line))
        list.push_back(atoi(line.c_str()));

    std::sort(list.begin(), list.end());

    for (int x = 1; x < list.size(); x++) {
        int diff = list[x] - list[x-1];
        map[diff]++;
    }

    map[list[0]]++;
    return map[1] * (map[3] + 1);
}

R day10_part2(std::ifstream& input)
{
    std::string line;
    std::vector<int> list;
    std::vector<R> methods;

    while (std::getline(input, line))
        list.push_back(atoi(line.c_str()));

    list.push_back(0);
    std::sort(list.begin(), list.end());
    
    methods.resize(list.size());
    methods[0] = 1;

    for (int x = 0; x < list.size(); x++) {
        for (int y = x + 1; y < list.size(); y++) {
            if (list[y] - list[x] > 3)
                break;

            methods[y] += methods[x];
        }
    }

    return methods[methods.size() - 1];
}

ADD_SOLUTION(10)
