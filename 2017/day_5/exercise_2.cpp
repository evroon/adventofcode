#include "../utils.h"

int main()
{
	std::ifstream myfile("input.txt");
	std::string input((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());
	int steps, index;

	std::vector<std::string> strings = split_string(input, '\n');
	std::vector<int> entries = string_to_int(strings);

	while (index < entries.size())
	{
		int old_index = index;
		index += entries[index];

		if (entries[old_index] >= 3)
			entries[old_index]--;
		else
			entries[old_index]++;

		steps++;
	}

	std::cout << steps << std::endl;

	return 0;
}
