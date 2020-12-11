#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string_view>
#include <algorithm>

#include "manager.h"

typedef long long L;
typedef std::vector<std::vector<char>> LIST;

int count_neighbours(char a, int x, int y, LIST& list)
{
    int result = 0;
    int x2, y2;

    for (int y1 = -1; y1 <= 1; y1++) {
        for (int x1 = -1; x1 <= 1; x1++) {
            if (x1 == 0 && y1 == 0)
                continue;

            int c = 1;

            while (true) {
                x2 = c * x1 + x;
                y2 = c * y1 + y;

                if (y2 < 0 || y2 >= list.size())
                    break;

                if (x2 < 0 || x2 >= list[0].size())
                    break;

                if (list[y2][x2] != '.') {
                    result += list[y2][x2] == a;
                    break;
                }
                c++;
            }
        }
    }
    return result;
}

int iterate(LIST& input, LIST& output) {
    int changes = 0;
    for (int y = 0; y < input.size(); y++) {
        for (int x = 0; x < input[y].size(); x++) {
            if (input[y][x] == 'L' && count_neighbours('#', x, y, input) == 0) {
                output[y][x] = '#';
                changes++;
            }
            else if (input[y][x] == '#' && count_neighbours('#', x, y, input) >= 5) {
                output[y][x] = 'L';
                changes++;
            }
        }
    }
    return changes;
}

int count_occupied(LIST& list) {
    int result = 0;
    for (int y = 0; y < list.size(); y++) {
        for (int x = 0; x < list[y].size(); x++) {
            if (list[y][x] == '#')
                result++;
        }
    }
    return result;
}

int day11_part2(std::ifstream& input)
{
    std::string line;
    LIST list;
    int iterations = 0;

    while (std::getline(input, line)) {
        std::vector<char> row;
        for (int c = 0; c < line.size(); c++)
            row.push_back(line[c]);

        list.push_back(row);
    }
    LIST output = list;

    while (iterate(list, output) > 0) {
        iterations++;
        list = output;
    }

    return count_occupied(list);
}

ADD_SOLUTION(11)
