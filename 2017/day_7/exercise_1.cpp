#include "../utils.h"

int main()
{
	std::ifstream myfile("input.txt");
	std::string line;
	std::map<std::string, int> entries;

	while (std::getline(myfile, line))
	{
		std::vector<std::string> strings = split_string(line, ' ');
		entries[strings[0]]++;

		for (int c = 3; c < strings.size(); c++) {
			replace(strings[c], ",", "");
			entries[strings[c]]++;
		}
	}

	for (auto const x : entries)
	{
		if (x.second < 2)
			std::cout << x.first << std::endl;
	}

	return 0;
}
