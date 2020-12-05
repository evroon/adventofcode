#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

#include "manager.h"

bool is_valid(const std::pair<std::string, std::string>& pair) {
    if (pair.first == "byr") {
        int a = std::atoi(pair.second.c_str());
        return is_int(pair.second) && a >= 1920 && a <= 2002;
    } else if (pair.first == "iyr") {
        int a = std::atoi(pair.second.c_str());
        return is_int(pair.second) && a >= 2010 && a <= 2020;
    } else if (pair.first == "eyr") {
        int a = std::atoi(pair.second.c_str());
        return is_int(pair.second) && a >= 2020 && a <= 2030;
    } else if (pair.first == "hgt") {
        std::string suffix = pair.second.substr(pair.second.size() - 2);
        if (suffix != "cm" && suffix != "in")
            return false;

        bool is_cm = pair.second.substr(pair.second.size() - 2) == "cm";
        std::string height_str = pair.second.substr(0, pair.second.size() - 2);

        if (!is_int(height_str))
            return false;

        int height = std::atoi(height_str.c_str());
        if (is_cm)
            return height >= 150 && height <= 193;

        return height >= 59 && height <= 76;
    } else if (pair.first == "hcl") {
        std::string hex_str = pair.second.substr(1);
        return pair.second.size() == 7 && pair.second[0] == '#' && is_hex(hex_str);
    } else if (pair.first == "ecl") {
        return pair.second.size() == 3 && find("amb blu brn gry grn hzl oth", pair.second).size() > 0;
    } else if (pair.first == "pid") {
        int a = std::atoi(pair.second.c_str());
        return is_int(pair.second) && pair.second.size() == 9;
    }

    return false;
}

int day4_part2(std::ifstream& input)
{
    std::string line;
    int valid_passports = 0;
    std::string str((std::istreambuf_iterator<char>(input)),
                    std::istreambuf_iterator<char>());

    auto pass_strings = split_string(str, "\n\n");

    for (std::string& pass: pass_strings) {
        replace_all(pass, "\n", " ");
        std::vector<std::string> elements = split_string(pass, ' ');
        int req = 0;

        for (std::string& element : elements) {
            auto pair_array = split_string(element, ':');
            std::pair<std::string, std::string> pair = {pair_array[0], pair_array[1]};

            if (pair.first != "cid" && is_valid(pair))
                req++;
        }

        if (req >= 7)
            valid_passports++;
    }

    return valid_passports;
}

ADD_SOLUTION(4)
