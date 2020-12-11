#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string_view>

#include "manager.h"

R day5_part1(std::ifstream& input)
{
    std::string line;
    std::vector<int> ids;

    while (std::getline(input, line)) {
        std::string row_part = line.substr(0, 7);
        std::string col_part = line.substr(7, 3);

        replace_all(row_part, "B", "1");
        replace_all(row_part, "F", "0");
        replace_all(col_part, "R", "1");
        replace_all(col_part, "L", "0");

        int row = std::stoi(row_part, 0, 2);
        int col = std::stoi(col_part, 0, 2);

        ids.push_back(row * 8 + col);
    }

    return min_and_max(ids).second;
}

R day5_part2(std::ifstream& input)
{
    std::string line;
    std::vector<int> ids;
    int result = 0;

    while (std::getline(input, line)) {
        std::string row_part = line.substr(0, 7);
        std::string col_part = line.substr(7, 3);

        replace_all(row_part, "B", "1");
        replace_all(row_part, "F", "0");
        replace_all(col_part, "R", "1");
        replace_all(col_part, "L", "0");

        int row = std::stoi(row_part, 0, 2);
        int col = std::stoi(col_part, 0, 2);

        ids.push_back(row * 8 + col);
    }

    for (int c = 0; c < 8 * 127 + 7; c++) {
        if (!contains(ids, c) && contains(ids, c+1) && contains(ids, c-1))
            result = c;
    }

    return result;
}

ADD_SOLUTION(5)
