#include "../utils.h"

int main()
{
	std::ifstream myfile("input.txt");
	std::string input((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());
	std::vector<std::string> strings = split_string(input, '\t');
	std::vector<int> entries = string_to_int(strings);
	std::vector< std::vector<int> > history;

	while (true)
	{
		for (int c = 0; c < history.size(); c++) {
			if (history[c] == entries)
				break;
		}

		history.push_back(entries);
		int arg_max = arg_min_and_max(entries).second;
		int blocks_to_distribute = entries[arg_max];
		int blocks_distributed = 0;

		for (int c = arg_max + 1; c != arg_max; c++)
		{
			if (c == entries.size())
				c = 0;

			if (blocks_distributed < blocks_to_distribute) {
				entries[c]++;
				blocks_distributed++;
			}
		}
	}

	std::cout << history.size() << std::endl;

	return 0;
}
