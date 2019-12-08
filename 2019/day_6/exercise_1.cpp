#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <map>

struct node
{
    node *parent;
    std::string name;
};

typedef std::map<std::string, node*> node_map;

node* get_by_name(const std::string &p_name, node_map &p_map)
{
    if (p_map[p_name] != nullptr)
        return p_map[p_name];

    return p_map[p_name] = new node;
}

int main()
{
    std::ifstream myfile("input.txt");
    std::string line;

    int result = 0;
    node_map map;

    while (std::getline(myfile, line))
    {
        std::string token = line.substr(0, line.find(")"));
        std::string parent_name = line.substr(0, line.find(")"));
        std::string current_name = line.substr(line.find(")") + 1);

        node *current = get_by_name(current_name, map);
        current->parent = get_by_name(parent_name, map);
        current->name = current_name;
    }
    
    for (node_map::iterator it = map.begin(); it != map.end(); it++)
    {
        node *current = it->second;

        while (current != nullptr && current->parent != nullptr)
        {
            result++;
            current = current->parent;
        }
    }

    for (node_map::iterator it = map.begin(); it != map.end(); it++)
    {
        delete it->second;
    }

    std::cout << result << std::endl;
    return 0;
}