#include <iostream>
#include <fstream>
#include <stdlib.h>

int main()
{
	std::ifstream myfile("input.txt");
	std::string line;
	int i = 0;

	while (std::getline(myfile, line))
	{
		int c = atoi(line.c_str());
		i += c;
	}

	std::cout << i << std::endl;

	return 0;
}

