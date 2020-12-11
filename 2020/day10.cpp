#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string_view>
#include <algorithm>

#include "manager.h"

typedef long long L;

int day10_part1(std::ifstream& input)
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

int traverse(std::vector<L>& list, int index, int& count) {
    int result = 0;

    return result;
}

int day10_part2(std::ifstream& input)
{
    std::string line;
    std::vector<L> list;
    std::vector<std::vector<int>> diff;
    std::map<int, int> map;

    while (std::getline(input, line))
        list.push_back(atoi(line.c_str()));

    std::sort(list.begin(), list.end());
    int r = 1;

    for (int x = 1; x < list.size(); x++) {
        std::vector<int> result;

        int diff1 = list[x] - list[x-1];
        if (diff1 <= 3)
            result.push_back(diff1);

        if (x > 1) {
            int diff2 = list[x] - list[x-2];
            if (diff2 <= 3)
                result.push_back(diff1);
        }

        if (x > 2) {
            int diff3 = list[x] - list[x-3];
            if (diff3 <= 3)
                result.push_back(diff1);
        }

        r *= (result.size() - 1 < 2 ? 1 : result.size() - 1);
        diff.push_back(result);
    }

    map[list[0]]++;
    return r;
}

ADD_SOLUTION(10)
