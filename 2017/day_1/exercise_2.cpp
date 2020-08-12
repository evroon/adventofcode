#include "../utils.h"

int main()
{
	std::ifstream myfile("input.txt");
	std::string line;
	int result = 0;


	while (std::getline(myfile, line))
	{
		char previous = line[line.size() - 1];
		int offset = line.size() / 2;

		for (int c = 0; c < line.size(); c++)
		{
			char current = line[c];
			char next = line[(c + offset) % (line.size())];

			if (current == next)
				result += current - 48;
		}
	}

	std::cout << result << std::endl;

	return 0;
}
