#include "../utils.h"

int main()
{
	std::ifstream myfile("input.txt");
	std::string line;
	int result;

	std::getline(myfile, line);
	int input = atoi(line.c_str());
	int current_value = 1;
	int index = 1;

	// Calculate the bottomright value of the spiral. Each spirals adds 8, 16, 24 etc. to the bottomright value.
	while (current_value < input) {
		current_value += index * 8;
		index++;
	}

	std::pair<int, int> xy(index - 1, -(index - 1));
	int edge_length = xy.first * 2 + 1;
	int offset = current_value - input;

	// Check on which edge the point lies and calculate the Manhattan distance.
	if (offset < edge_length)
		result = abs(xy.first - offset) + abs(xy.second);
	else if (offset < edge_length * 2 - 1)
		result = abs(-xy.first) + abs(xy.second + (offset - edge_length + 1));
	else if (offset < edge_length * 3 - 2)
		result = abs(-xy.first + (offset - edge_length * 2 + 2)) + abs(-xy.second);
	else
		result = abs(xy.first) + abs(-xy.second - (offset - edge_length * 3 + 3));

	std::cout << result << std::endl;

	return 0;
}
