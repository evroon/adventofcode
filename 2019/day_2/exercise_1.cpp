#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

int main()
{
    std::ifstream myfile("input.txt");
    std::string line;
    std::vector<int> input;

    while (std::getline(myfile, line, ','))
        input.push_back(stoi(line));

    input[1] = 12;
    input[2] = 2;

    for (int i = 0; i < input.size(); i += 4)
    {
        int op = input[i];

        if (op == 99)
            break;

        int a = input[i + 1];
        int b = input[i + 2];
        int c = input[i + 3];

        if (op == 1)
            input[c] = input[a] + input[b];
        else if (op == 2)
            input[c] = input[a] * input[b];
    }

    std::cout << input[0] << std::endl;
    return 0;
}