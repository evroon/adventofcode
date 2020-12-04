#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <map>

int sum(const std::vector<int>& array)
{
    int result = 0;

    for (int c = 0; c < array.size(); c++)
        result += array[c];

    return result;
}

std::pair<int, int> arg_min_and_max(const std::vector<int>& array)
{
    int min = 1000000000;
    int max = 0;
    int arg_min, arg_max;

    for (int c = 0; c < array.size(); c++)
    {
        const int current = array[c];

        if (min > current) {
            min = current;
            arg_min = c;
        }

        if (max < current) {
            max = current;
            arg_max = c;
        }
    }

    return std::pair<int, int>(arg_min, arg_max);
}

std::pair<int, int> min_and_max(const std::vector<int>& array)
{
    std::pair<int, int> args = arg_min_and_max(array);
    return std::pair<int, int>(array[args.first], array[args.second]);
}

std::vector<int> find(const std::string& p_haystack, const std::string& p_needle) {
	std::vector<int> result;
	int index = 0;

	for (int c = 0; c < p_haystack.size(); c++)
	{
		if (p_haystack[c] == p_needle[index])
		{
			if (index == p_needle.length() - 1)
			{
				result.push_back(c - p_needle.length() + 1);
				index = 0;
			}

			index++;
		}
		else index = 0;
	}

	return result;
}

std::vector<std::string> split_string(const std::string& p_src, const std::string& p_delim) {
	std::vector<std::string> result;
    std::vector<int> find_result = find(p_src, p_delim);
    find_result.emplace(find_result.begin(), 0);

    for (int c = 0; c < find_result.size(); c++) {
        int start = find_result[c] + (c != 0 ? p_delim.size() : 0);
        result.push_back(p_src.substr(start, find_result[c+1] - start));
    }

	return result;
}

std::vector<std::string> split_string(const std::string& to_split, char delim)
{
    std::stringstream test;
    std::string segment;
    std::vector<std::string> result;

    test.str(to_split);

    while(std::getline(test, segment, delim))
        result.push_back(segment);

    return result;
}

std::vector<int> string_to_int(const std::vector<std::string>& array)
{
    std::vector<int> result;

    for (int c = 0; c < array.size(); c++)
        result.push_back(atoi(array[c].c_str()));

    return result;
}

bool is_anagram(const std::string& first, const std::string& second)
{
    if (first.size() != second.size())
        return false;

    std::string first_copy = first, second_copy = second;
    std::sort(first_copy.begin(), first_copy.end());
    std::sort(second_copy.begin(), second_copy.end());

    return first_copy == second_copy;
}

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if (start_pos == std::string::npos)
        return false;
    str = str.replace(start_pos, from.length(), to);
    return true;
}

void replace_all(std::string& str, const std::string& from, const std::string& to) {
    while (replace(str, from, to)) { }
}

bool is_int(const std::string& str) {
    for (char c: str) {
        if (!isdigit(c))
            return false;
    }
    return true;
}


bool is_hex(const std::string& str) {
    for (char c: str) {
        if (!isdigit(c) && c > 'f')
            return false;
    }
    return true;
}
