#include "../utils.h"

int main()
{
	std::ifstream myfile("input.txt");
	std::string line;
	int result;

	while (std::getline(myfile, line))
	{
		std::vector<std::string> strings = split_string(line, ' ');
		bool success = true;

		for (int i = 0; i < strings.size(); i++)
		{
			for (int j = i + 1; j < strings.size(); j++)
			{
				if (strings[i] == strings[j] || is_anagram(strings[i], strings[j]))
				{
					success = false;
					break;
				}
			}
			if (!success)
				break;
		}

		if (success)
			result++;
	}

	std::cout << result << std::endl;

	return 0;
}
