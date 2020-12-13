#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string_view>
#include <algorithm>
#include <math.h>

#include "manager.h"

R day27_part2(std::ifstream& input)
{
    std::string line;
    std::vector<int> list;
    int result = 0;

    while (std::getline(input, line))
        list.push_back(atoi(line.c_str()));

    return result;
}

ADD_SOLUTION(27)
