#include "../utils.h"

int main()
{
	std::ifstream myfile("input.txt");
	std::string line;
	int result;

	while (std::getline(myfile, line))
	{
		std::vector<std::string> strings = split_string(line, '\t');
		std::vector<int> entries = string_to_int(strings);

		for (int i = 0; i < entries.size(); i++)
		{
			for (int j = 0; j < entries.size(); j++)
			{
				if (i != j && entries[i] % entries[j] == 0)
					result += entries[i] / entries[j];
			}
		}
	}

	std::cout << result << std::endl;

	return 0;
}
