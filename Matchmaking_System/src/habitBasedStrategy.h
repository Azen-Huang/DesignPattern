#pragma once

#include <vector>

#include "individual.h"
#include "matchstrategy.h"
class HabitBaseStrategy : public MatchStrategy {
public:
    HabitBaseStrategy() { std::cout << "Use Habit-Base Strategy." << std::endl; }
    std::vector<Individual*> match(Individual* i, std::vector<Individual*>& individuals) override;
};

std::vector<Individual*> HabitBaseStrategy::match(Individual* i, std::vector<Individual*>& individuals) {
    int best_habit_count = -1;
    int worst_habit_count = INT_MAX;
    Individual* best_candidates;
    Individual* worst_candidates;

    for (auto j : individuals) {
        if (i == j) continue;
        std::vector<std::string> intersection;
        std::set_intersection(begin(i->getHabits()), end(i->getHabits()), begin(j->getHabits()), end(j->getHabits()), std::back_inserter(intersection));
        int count = intersection.size();
        if (count > best_habit_count) {
            best_habit_count = count;
            best_candidates = j;
        }
        if (count < worst_habit_count) {
            worst_habit_count = count;
            worst_candidates = j;
        }
    }
    return {best_candidates, worst_candidates};
}