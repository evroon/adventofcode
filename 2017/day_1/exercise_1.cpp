#include "../utils.h"

int main()
{
	std::ifstream myfile("input.txt");
	std::string line;
	int result = 0;


	while (std::getline(myfile, line))
	{
		char previous = line[line.size() - 1];

		for (int c = 0; c < line.size(); c++)
		{
			char current = line[c];

			if (current == previous)
				result += current - 48;

			previous = current;
		}
	}

	std::cout << result << std::endl;

	return 0;
}
