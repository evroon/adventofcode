#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string_view>
#include <algorithm>
#include <math.h>

#include "manager.h"

#define PI 3.14159265359


R day12_part1(std::ifstream& input)
{
    std::string line;
    std::vector<std::pair<char, int>> list;
    std::pair<int, int> position;
    std::pair<int, int> diff;
    int orientation = 0;

    while (std::getline(input, line))
        list.push_back({line[0], atoi(line.substr(1).c_str())});

    for (int c = 0; c < list.size(); c++) {
        diff = {};
        const int& value = list[c].second;

        if (list[c].first == 'N')
            diff = {0, 1};
        else if (list[c].first == 'E')
            diff = {1, 0};
        else if (list[c].first == 'S')
            diff = {0, -1};
        else if (list[c].first == 'W')
            diff = {-1, 0};
        else if (list[c].first == 'L')
            orientation += list[c].second;
        else if (list[c].first == 'R')
            orientation -= list[c].second;
        else if (list[c].first == 'F') {
            diff = {round(cos(orientation * PI / 180)), round(sin(orientation * PI / 180))};
        }

        position.first += diff.first * value;
        position.second += diff.second * value;

        orientation %= 360;
        std::cout << orientation << std::endl;
    }

    return abs(position.first) + abs(position.second);
}

std::pair<R, R> rotate(std::pair<R, R> a, int value) {
    switch (value)
    {
    case 90:
        return {a.second, -a.first};
    case 180:
        return {-a.first, -a.second};
    case 270:
        return {-a.second, a.first};
    }
    return {a.first, a.second};
}

R day12_part2(std::ifstream& input)
{
    std::string line;
    std::vector<std::pair<char, int>> list;
    std::pair<R, R> position;
    std::pair<R, R> waypoint = {10, 1};
    std::pair<int, int> diff;

    while (std::getline(input, line))
        list.push_back({line[0], atoi(line.substr(1).c_str())});

    for (int c = 0; c < list.size(); c++) {
        diff = {};
        const int& value = list[c].second;

        if (list[c].first == 'N')
            diff = {0, 1};
        else if (list[c].first == 'E')
            diff = {1, 0};
        else if (list[c].first == 'S')
            diff = {0, -1};
        else if (list[c].first == 'W')
            diff = {-1, 0};
        else if (list[c].first == 'L') {
            double angle = value * PI / 180.0 + atan2(waypoint.second, waypoint.first);
            double distance = sqrt(pow(waypoint.second, 2) + pow(waypoint.first, 2));
            waypoint.first = round(distance * cos(angle));
            waypoint.second = round(distance * sin(angle));
        }
        else if (list[c].first == 'R') {
            double angle = -value * PI / 180.0 + atan2(waypoint.second, waypoint.first);
            double distance = sqrt(pow(waypoint.second, 2) + pow(waypoint.first, 2));
            waypoint.first = round(distance * cos(angle));
            waypoint.second = round(distance * sin(angle));
        }
        else if (list[c].first == 'F') {
            position.first += value * waypoint.first;
            position.second += value * waypoint.second;
        }

        waypoint.first += diff.first * value;
        waypoint.second += diff.second * value;
    }

    return abs(position.first) + abs(position.second);
}

ADD_SOLUTION(12)
