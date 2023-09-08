#pragma once

#include "player.h"
#include "card.h"
class Human_Player : public Player {
public:
    bool is_human;
    Human_Player();
    Card show(int idx) override;
};

Human_Player::Human_Player() : is_human(true) {};

Card Human_Player::show(int idx) {
    Card choosed_card = this->hand[idx];
    this->hand.erase(this->hand.begin() + idx);
    return choosed_card;
}