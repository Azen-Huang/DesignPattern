#pragma once

#include <vector>
#include <algorithm>
#include <random>
#include "card.h"

class Deck {
public:
    std::vector<Card> deck;

    Deck();
    void shuffle();
};

Deck::Deck() {
    std::vector<std::string> ranks = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    std::vector<std::string> suits = {"C", "D", "H", "S"}; 

    for (auto rank : ranks) {
        for (auto suit : suits) {
            Card card(rank, suit);
            this->deck.push_back(card);
        }
    }
}   

void Deck::shuffle() {
    auto rng = std::default_random_engine {};
    std::shuffle(this->deck.begin(), this->deck.end(), rng);
    return;
}