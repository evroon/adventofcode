#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "lib.cpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "No day specified" << std::endl;
        return -1;
    }

    long result = run_day(std::atoi(argv[1]));

    std::cout << "Result: " << result << std::endl;
    return 0;
}
