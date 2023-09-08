#pragma once

#include <string>

class Card {
public:
    std::string rank;
    std::string suit;

    Card(std::string rank, std::string suit);
};

Card::Card(std::string rank, std::string suit) {
    this->rank = rank;
    this->suit = suit;
}
