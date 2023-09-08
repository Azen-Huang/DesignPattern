#pragma once

#include <vector>
#include <algorithm>

#include "individual.h"
#include "matchstrategy.h"
class DistanceBaseStrategy : public MatchStrategy {
public:
    DistanceBaseStrategy() { std::cout << "Use Distance-Base Strategy." << std::endl; }
    std::vector<Individual*> match(Individual* i, std::vector<Individual*>& individuals) override;
};


std::vector<Individual*> DistanceBaseStrategy::match(Individual* i, std::vector<Individual*>& individuals) {
    int best_distance = INT_MAX;
    int worst_distance = -1;
    Individual* best_candidates;
    Individual* worst_candidates;
    for (auto j : individuals) {
        if (i == j) continue;
        Coord i_coord = i->getCoord();
        Coord j_coord = j->getCoord();
        int distance = (i_coord.x - j_coord.x) * (i_coord.x - j_coord.x) + (i_coord.y - j_coord.y) * (i_coord.y - j_coord.y);
        if (distance < best_distance) {
            best_distance = distance;
            best_candidates = j;
        }
        if (distance > worst_distance) {
            worst_distance = distance;
            worst_candidates = j;
        }
    }
    return {best_candidates, worst_candidates};
}