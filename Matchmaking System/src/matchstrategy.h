#pragma once

#include <vector>

#include "individual.h"
class MatchStrategy {
public:
    virtual ~MatchStrategy() {}
    virtual std::vector<Individual*> match(Individual* i, std::vector<Individual*>& individuals) = 0;
};