#pragma once

#include <iostream>
#include <vector>

#include "individual.h"
#include "matchstrategy.h"

class MatchmakingSystem {
private:
    std::vector<Individual*> individuals;
    MatchStrategy* matchStrategy;
public:
    MatchmakingSystem(MatchStrategy* matchStrategy);
    void match();
    inline void addIndividual(Individual* individual) {individuals.push_back(individual);};
};

MatchmakingSystem::MatchmakingSystem(MatchStrategy* matchStrategy) : matchStrategy(matchStrategy) {}

void MatchmakingSystem::match() {
    std::cout << "Start Match" << std::endl;
    for (auto i : individuals) {
        std::vector<Individual*> match_rank = this->matchStrategy->match(i, individuals);
        i->match(match_rank[0]);
    }
    return;
}
