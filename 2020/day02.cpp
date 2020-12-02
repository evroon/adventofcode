#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

int day2_part2(std::ifstream& input)
{
    std::string line;
    int occurences = 0;

    while (std::getline(input, line))
    {
        int min = std::atoi(line.substr(0, line.find("-")).c_str());
        std::string rest = line.substr(line.find("-")+1, line.size() - 1);
        int max = std::atoi(rest.substr(0, rest.find(" ")).c_str());
        char c = rest.substr(rest.find(" ") + 1, rest.find(":") - 1)[0];

        std::string password = line.substr(line.find(":") + 2, line.size() - 1);
        if ((password[min-1] == c) != (password[max-1] == c)) {
            occurences++;
        }
    }

    return occurences;
}