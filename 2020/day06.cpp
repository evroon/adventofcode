#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string_view>

#include "manager.h"

R day6_part1(std::ifstream& input)
{
    std::string line;
    int result = 0;
    std::string str((std::istreambuf_iterator<char>(input)),
                    std::istreambuf_iterator<char>());

    auto pass_strings = split_string(str, "\n\n");

    for (std::string& pass: pass_strings) {
        replace_all(pass, "\n", " ");

        for (char c = 'a'; c <= 'z'; c++) {
            if (find(pass, std::string(1, c)).size() > 0) {
                result++;
            }
        }
    }

    return result;
}

R day6_part2(std::ifstream& input)
{
    std::string line;
    int result = 0;
    std::string str((std::istreambuf_iterator<char>(input)),
                    std::istreambuf_iterator<char>());

    auto pass_strings = split_string(str, "\n\n");

    for (std::string& pass: pass_strings) {
        replace_all(pass, "\n", " ");
        std::vector<std::string> elements = split_string(pass, ' ');

        for (char c = 'a'; c <= 'z'; c++) {
            bool found = true;
            for (std::string& element : elements) {
                if (find(element, std::string(1, c)).size() < 1) {
                    found = false;
                    break;
                }
            }
            if (found)
                result++;
        }
    }

    return result;
}

ADD_SOLUTION(6)
