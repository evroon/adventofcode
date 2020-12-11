#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

#include "manager.h"

R day1_part2(std::ifstream& input)
{
    std::string line;
    std::vector<int> history;
    R result = 0;

    while (std::getline(input, line))
    {
        int value = atoi(line.c_str());
        for (int c = 0; c < history.size(); c++) {
            for (int d = 0; d < history.size(); d++) {
                if (history[c] + history[d] + value == 2020) {
                    result = history[c] * history[d] * value;
                    break;
                }
            }
        }
        history.push_back(value);
    }

    return result;
}

ADD_SOLUTION(1)
