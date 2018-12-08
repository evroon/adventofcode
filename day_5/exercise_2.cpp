#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>


int main()
{
    std::ifstream myfile("input.txt");
    std::string orig, line;
    std::getline(myfile, orig);
    bool destroyed = true;
    int min = orig.size();

    for (int t = 'a'; t <= 'z'; t++)
    {
        destroyed = true;
        line = orig;
        line.erase(std::remove(line.begin(), line.end(), (char) t), line.end());
        line.erase(std::remove(line.begin(), line.end(), (char) t - (97-65)), line.end());

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
        std::cout << (char) t << " " << line.size() << std::endl;

        if (min > line.size())
            min = line.size();
    }

    std::cout << std::endl;
    std::cout << min << std::endl;
    
    return 0;
}

