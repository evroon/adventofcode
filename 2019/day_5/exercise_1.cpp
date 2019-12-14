#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <array>
#include <cmath>

std::vector<int> get_inputs(int p_i, const std::vector<int> &p_data)
{
    int value = p_data[p_i];
    int opcode = value % 100;
    int arg_count = opcode > 2 ? 1 : 3;

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

    for (int i = 0; i < data.size();)
    {
        int opcode = data[i] % 100;
        if (opcode == 99)
            break;

        std::vector<int> inputs = get_inputs(i, data);

        switch (opcode)
        {
        case 1:
            data[inputs[2]] = inputs[0] + inputs[1];
            break;

        case 2:
            data[inputs[2]] = inputs[0] * inputs[1];
            break;

        case 3:
            data[data[i + 1]] = 1;
            break;

        case 4:
            std::cout << "output " << data[data[i + 1]] << std::endl;
            break;
        }

        i += inputs.size() + 1;
    }

    return 0;
}