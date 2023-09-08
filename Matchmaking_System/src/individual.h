#pragma once

#define HABITS_LIMIT 20
#define HABITS_TEXT_LIMIT 10
#define INTRO_LIMIT 200
#include <string>
#include <iostream>
#include <iomanip>
// #include "matchmakingsystem.h"
#include "coord.h"

class Individual {
public:
    Individual(int id, std::string male, int age,std::string intro, std::vector<std::string> habits, Coord coord);
    void match(Individual* i);

    inline Coord getCoord() { return this->coord; };
    inline std::vector<std::string> getHabits() { return this->habits; }
    void getMatcherInfo();
    void printInfo();
private:
    const unsigned int id; // >0
    const std::string male; // {MALE | FEMALE}
    const unsigned int age; // >= 18;
    const std::string intro;
    const std::vector<std::string> habits;
    const Coord coord;

    Individual* matcher;
};

Individual::Individual(int id, std::string male, int age, std::string intro, std::vector<std::string> habits, Coord coord)
    : id(id), male(std::move(male)), age(age), intro(intro), habits(habits), coord(coord) {}

void Individual::match(Individual* i) {
    matcher = i;
}

void Individual::printInfo() {
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "ID: " << this->id << " Age: " << this->age << std::endl;
    std::cout << "Location: (" << this->coord.x << ", " << this->coord.y << ")" << std::endl;
    for (auto habbit : this->habits) {
        std::cout << habbit << std::endl;
    }
    std::cout << "---------------------------------------" << std::endl;
}

void alignAndPrint(const std::vector<std::string>& leftVec, const std::vector<std::string>& rightVec) {
    size_t maxLeftWidth = 0;

    // Find the maximum width of the strings in the left vector
    for (const std::string& str : leftVec) {
        maxLeftWidth = std::max(maxLeftWidth, str.length());
    }

    // Output the aligned strings
    for (size_t i = 0; i < std::max(leftVec.size(), rightVec.size()); ++i) {
        if (i < leftVec.size()) {
            std::cout << std::left << std::setw(maxLeftWidth) << leftVec[i];
        } else {
            // If left vector is shorter, print empty space
            std::cout << std::left << std::setw(maxLeftWidth) << "";
        }

        std::cout << "  ";  // Add some spacing between left and right columns

        if (i < rightVec.size()) {
            std::cout << rightVec[i];
        }

        std::cout << std::endl;
    }
}

void Individual::getMatcherInfo() {

    std::vector<std::string> this_info;
    std::vector<std::string> matcher_info;

    this_info.push_back("My Info 1");
    this_info.push_back("ID: " + std::to_string(this->id));
    this_info.push_back("Age: " + std::to_string(this->age));
    this_info.push_back("Location: (" + std::to_string(this->coord.x) + ", " + std::to_string(this->coord.y) + ")");
    this_info.push_back("Habit:");
    for(auto habit : this->habits) {
        this_info.push_back(habit);
    }

    matcher_info.push_back("Matcher Info 2");
    matcher_info.push_back("ID: " + std::to_string(this->matcher->id));
    matcher_info.push_back("Age: " + std::to_string(this->matcher->age));
    matcher_info.push_back("Location: (" + std::to_string(this->matcher->coord.x) + ", " + std::to_string(this->matcher->coord.y) + ")");
    matcher_info.push_back("Habit:");
    for(auto habit : this->matcher->habits) {
        matcher_info.push_back(habit);
    }
    
    std::cout << "---------------------------------------" << std::endl;
    alignAndPrint(this_info, matcher_info);
    std::cout << "---------------------------------------" << std::endl;
}