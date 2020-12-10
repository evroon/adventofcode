#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string_view>

#include "manager.h"

typedef std::map<std::string, std::vector<std::pair<int, std::string>>> M;

int traverse(M& map, const std::string& color) {
    int result = 0;

    if (map.count(color) > 0) {
        for (auto c : map[color]) {
            result += traverse(map, c.second) * c.first + c.first;
        }
    }
    return result;
}

int day7_part2(std::ifstream& input)
{
    std::string line;
    std::vector<int> ids;
    int result;

    M map;
    // std::vector<std::string, bool> can_contain_gold;

    while (std::getline(input, line)) {
        auto split = split_string(line, " bags contain ");
        std::string subject = split[0];
        std::string contain = split[1];

        std::vector<std::pair<int, std::string>> element;

        auto contain_split = split_string(contain, ", ");
        for (std::string& a : contain_split) {
            replace_all(a, " bags", "");
            replace_all(a, " bag", "");
            replace_all(a, ".", "");

            auto element_split = split_string(a, " ");
            int count = atoi(element_split[0].c_str());

            if (element_split.size() < 2) {
                std::cout << "error: " << contain_split[0] << std::endl;
                continue;
            }

            std::vector<std::string> item_vec = std::vector<std::string>(element_split.begin() + 1, element_split.end());
            std::string item = element_split[1];

            for (int c = 2; c < element_split.size(); c++)
                item += " " + element_split[c];

            element.push_back({count, item});
        }

        map[subject] = element;
    }

    return traverse(map, "shiny gold");
}

ADD_SOLUTION(7)
