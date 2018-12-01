#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

int main()
{
    std::ifstream myfile("input.txt");
	std::string line;
	std::vector<int> history;
	int i = 0;

	while (true)
	{
		bool eof = std::getline(myfile, line);
		if (!eof)
		{
			myfile.clear();
			myfile.seekg(0, std::ios::beg);
			std::getline(myfile, line);
		}
		int c = atoi(line.c_str());
		history.push_back(i);
		i += c;

		for (int k = 0; k < history.size(); k++)
		{
			if (history[k] == i)
			{
				std::cout << i << std::endl;
				return 0;
			}
		}
	}
	
	std::cout << "end" << std::endl;
    return 0;
}

