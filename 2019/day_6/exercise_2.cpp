#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <map>

struct node
{
    node *parent;
    std::string name;
    std::vector<node*> child_nodes;
};

typedef std::map<std::string, node*> node_map;

node* get_by_name(const std::string &p_name, node_map &p_map)
{
    if (p_map[p_name] != nullptr)
        return p_map[p_name];

    return p_map[p_name] = new node;
}

bool search_node(node* p_node, int* p_steps)
{
    int current_steps = *p_steps;
    (*p_steps)++;

    for (node* n : p_node->child_nodes)
    {

        if (n->name == "SAN") {
            return true;
        }

        if (search_node(n, p_steps))
            return true;

        *p_steps = current_steps;
    }

    return false;
}

int main()
{
    std::ifstream myfile("input.txt");
    std::string line;

    int steps = 0;
    node_map map;

    while (std::getline(myfile, line))
    {
        std::string token = line.substr(0, line.find(")"));
        std::string parent_name = line.substr(0, line.find(")"));
        std::string current_name = line.substr(line.find(")") + 1);

        node *current = get_by_name(current_name, map);
        current->parent = get_by_name(parent_name, map);
        current->name = current_name;
        current->parent->child_nodes.push_back(current);
    }
    
    node* current = map["YOU"];
    while (current != nullptr)
    {
        if (search_node(current, &steps))
            break;

        current = current->parent;
        steps += 1;
    }

    for (node_map::iterator it = map.begin(); it != map.end(); it++)
    {
        delete it->second;
    }

    std::cout << steps << std::endl;
    return 0;
}