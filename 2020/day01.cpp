#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

int main()
{
    std::ifstream input("inputs/day01.txt");
    std::string line;
    std::vector<int> history;

    while (std::getline(input, line))
    {
        int value = atoi(line.c_str());
        for (int c = 0; c < history.size(); c++) {
            for (int d = 0; d < history.size(); d++) {
                if (history[c] + history[d] + value == 2020) {
                    std::cout << history[c] * history[d] * value << std::endl;
                    break;
                }
            }
        }
        history.push_back(value);
    }

    return 0;
}