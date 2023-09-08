#pragma once

#include "player.h"
#include "card.h"

class AI_Player : public Player {
public:
    bool is_human;
    
    AI_Player();
    Card show(int _) override;
};

AI_Player::AI_Player() : is_human(false) {};

Card AI_Player::show(int _ = -1) {
    std::srand(std::time(0));
    int idx = rand() % this->hand.size();
    Card choosed_card = this->hand[idx];
    this->hand.erase(this->hand.begin() + idx);
    return choosed_card;
}