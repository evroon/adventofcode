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

		std::pair<int, int> min_max = min_and_max(entries);
		result += min_max.second - min_max.first;
	}

	std::cout << result << std::endl;

	return 0;
}
