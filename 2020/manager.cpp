#include "manager.h"

void SolutionManager::add_day(uint day, R (*function)(std::ifstream &input))
{
    days[day] = function;
}

SolutionManager* SolutionManager::get_singleton() {
    static SolutionManager singleton;
    return &singleton;
}
