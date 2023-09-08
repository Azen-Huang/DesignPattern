#pragma once

#include <vector>

#include "individual.h"
#include "matchstrategy.h"
class reversed : public MatchStrategy {
public:
    reversed(MatchStrategy* strategy) : strategy(strategy) { std::cout << "Use Reversed." << std::endl; }
    std::vector<Individual*> match(Individual* i, std::vector<Individual*>& individuals);
private:
    MatchStrategy* strategy;
};

std::vector<Individual*> reversed::match(Individual* i, std::vector<Individual*>& individuals) {
    std::vector<Individual*> candidates = this->strategy->match(i, individuals);
    std::swap(candidates[0], candidates[1]);
    return candidates;
}