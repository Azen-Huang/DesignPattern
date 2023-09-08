#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <sstream>

#include "matchmakingsystem.h"
#include "individual.h"
#include "coord.h"
#include "matchstrategy.h"
#include "distanceBasedStrategy.h"
#include "habitBasedStrategy.h"
#include "reversed.h"

using namespace std;
/*
// run code //
make
./main
// run code //
*/
enum gender {
    MALE = 0,
    FEMALE = 1
};

int main() {
    MatchStrategy* myStrategy = new DistanceBaseStrategy();
    // MatchStrategy* myStrategy = new reversed(new DistanceBaseStrategy());
    // MatchStrategy* myStrategy = new HabitBaseStrategy();
    // MatchStrategy* myStrategy = new reversed(new HabitBaseStrategy());
    MatchmakingSystem* system = new MatchmakingSystem(myStrategy);
    
    Individual* alice = new Individual(
        0, "FEMALE", 18, 
        "Hello, My name is Alice.", 
        {"Habit 1", "Habit 2", "Habit 3", "Habit 4"},
        Coord(3, 4)
        );
    
    Individual* ben = new Individual(
        1, "MALE", 18, 
        "Hello, My name is Ben.", 
        {"Habit 1", "Habit 2", "Habit 5", "Habit 6"},
        Coord(10, 9)
        );
    
    Individual* catty = new Individual(
        2, "FEMALE", 18, 
        "Hello, My name is Catty.", 
        {"Habit 0", "Habit 2", "Habit 5", "Habit 7"},
        Coord(3, 5)
        );

    system->addIndividual(alice);
    system->addIndividual(ben);
    system->addIndividual(catty);

    system->match();

    alice->getMatcherInfo();
    ben->getMatcherInfo();
    catty->getMatcherInfo();
    // cout << "hello world" << endl;
}