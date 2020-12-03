#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

int main()
{
    std::ifstream myfile("input.txt");
    std::string line;
    std::getline(myfile, line);
    bool destroyed = true;

    while (destroyed)
    {
        destroyed = false;
        for (int c = 0; c < line.size() - 1; c++)
        {
            if ((char) line[c] == ((char) line[c + 1]) + (97-65) || (char) line[c] == ((char) line[c + 1]) - (97-65))
            {
                line.erase (c, 2);
                destroyed = true;
            }
        }
    }
    
    std::cout << line.size() << std::endl;
    return 0;
}

