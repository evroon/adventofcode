#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <array>
#include <cmath>

std::vector<int> get_arguments(int p_i, const std::vector<int> &p_data)
{
    int value = p_data[p_i];
    int opcode = value % 100;
    int arg_count = 3;

    if (opcode == 3 || opcode == 4)
        arg_count = 1;
    else if (opcode == 5 || opcode == 6)
        arg_count = 2;

    std::vector<int> result;
    result.resize(arg_count);

    for (int c = 0; c < arg_count; c++)
    {
        int mode = int(value / std::pow(10, c + 2)) % 10;

        if (c == 2)
            result[c] = p_data[p_i + 3];
        else if (mode == 0)
            result[c] = p_data[p_data[p_i + c + 1]];
        else if (mode == 1)
            result[c] = p_data[p_i + c + 1];
    }

    return result;
}

int main()
{
    std::ifstream myfile("input.txt");
    std::string line;
    std::vector<int> data;

    while (std::getline(myfile, line, ','))
        data.push_back(stoi(line));

    int diagnostic_code = 5;

    for (int i = 0; i < data.size();)
    {
        int opcode = data[i] % 100;
        if (opcode == 99)
            break;

        std::vector<int> args = get_arguments(i, data);

        switch (opcode)
        {
        case 1:
            data[args[2]] = args[0] + args[1];
            break;

        case 2:
            data[args[2]] = args[0] * args[1];
            break;

        case 3:
            data[data[i + 1]] = diagnostic_code;
            break;

        case 4:
            std::cout << "output " << data[data[i + 1]] << std::endl;
            break;

        case 5:
            if (args[0] != 0)
                i = args[1];
            else
                i += 3;
            break;

        case 6:
            if (args[0] == 0)
                i = args[1];
            else
                i += 3;
            break;

        case 7:
            data[args[2]] = args[0] < args[1];
            break;

        case 8:
            data[args[2]] = args[0] == args[1];
            break;
        }

        if (opcode != 5 && opcode != 6)
            i += args.size() + 1;
    }

    return 0;
}