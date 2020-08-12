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
		for (int c= 0;c < entries.size(); c++)
			std::cout << entries[c] << " ";

		std::cout << std::endl;

		for (int c = 0; c < history.size(); c++) {
			if (history[c] == entries) {
				std::cout << history.size() << " " << std::endl;
				return 0;
			}
		}

		history.push_back(entries);
		int arg_max = arg_min_and_max(entries).second;
		int blocks_to_distribute = entries[arg_max];
		int blocks_distributed = 0;
		int blocks_per_block = ceil(blocks_to_distribute / (float) entries.size());
		for (int c = arg_max + 1; true; c++)
		{
			if (c >= entries.size())
				c = 0;

			if (c == arg_max)
				break;

			if (blocks_per_block >= 1 && blocks_distributed + blocks_per_block > blocks_to_distribute) {
				blocks_per_block--;
			}

			entries[c] += blocks_per_block;
			blocks_distributed += blocks_per_block;
		}
		entries[arg_max] = blocks_to_distribute - blocks_distributed;
	}

	return 0;
}
