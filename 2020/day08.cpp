#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string_view>

#include "manager.h"

int execute(const std::vector<std::pair<std::string, int>>& program)
{
    std::vector<int> history = {};
    int accumulator = 0, pointer = 0;

    while (true)
    {
        if (pointer == program.size())
            break;

        if (contains(history, pointer))
            return -1;

        history.push_back(pointer);

        auto instruction = program[pointer];

        if (instruction.first == "nop")
            pointer++;
        else if (instruction.first == "acc") {
            accumulator += instruction.second;
            pointer++;
        } else if (instruction.first == "jmp") {
            pointer += instruction.second;
        }
    }

    return accumulator;
}

R day8_part1(std::ifstream& input)
{
    std::string line;
    int pointer = 0;

    std::vector<std::pair<std::string, int>> program;

    while (std::getline(input, line)) {
        auto split = split_string(line, " ");
        program.push_back({split[0], atoi(split[1].c_str())});
    }

    return execute(program);
}

R day8_part2(std::ifstream& input)
{
    std::string line;
    int pointer = 0;

    std::vector<std::pair<std::string, int>> orig_program;

    while (std::getline(input, line)) {
        auto split = split_string(line, " ");
        orig_program.push_back({split[0], atoi(split[1].c_str())});
    }

    for (int c = 0; c < orig_program.size(); c++) {
        std::vector<std::pair<std::string, int>> program = orig_program;

        if (program[c].first == "nop")
            program[c].first = "jmp";
        else if (program[c].first == "jmp")
            program[c].first = "nop";

        R result = execute(program);
        if (result != -1)
            return result;
    }
    return -1;
}

ADD_SOLUTION(8)
