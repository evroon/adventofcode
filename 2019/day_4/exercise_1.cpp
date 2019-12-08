#include <iostream>
#include <fstream>
#include <stdlib.h>

int main()
{
	std::ifstream myfile("input.txt");
	std::string line;
    std::getline(myfile, line);

    std::string token = line.substr(0, line.find("-"));
	int start = std::stoi(line.substr(0, line.find("-")));
	int end = std::stoi(line.substr(line.find("-") + 1));

    int result = 0;

	for (int i = start; i <= end; i++) {
        std::string s = std::to_string(i);
        int last = 0;
        bool found = false;
        bool failed = false;

        for (int j = 0; j < s.length(); j++) {
            int current = s[j] - 48;

            if (current < last) {
                failed = true;
                break;
            }

            if (current == last)
                found = true;

            last = current;
        }
        if (!failed && found)
            result += 1;
	}

    std::cout << result << std::endl;
	return 0;
}