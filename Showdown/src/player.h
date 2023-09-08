#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "card.h"
#include "deck.h"

class Player {
public:
    std::string name;
    std::vector<Card> hand;
    int point;
    bool can_exchange;
    int exchange_round;
    bool is_human;
    Player* exchange_player;

    Player();
    virtual Card show(int idx) = 0;
    void name_himself(std::string name);
    void draw(Deck* deck);
    void exchange_hands(Player* exchange_player, int exchange_round);
    void get_point();

    // Player& operator=(const Player& other);
    void print_hand();
};

Player::Player() : 
    name(""), 
    point(0), 
    can_exchange(true),
    exchange_round(0), 
    is_human(false) {}

void Player::name_himself(std::string name) {
    this->name = name;
    return;
}

void Player::draw(Deck* deck) {
    if (this->hand.size() >= 13) {
        std::cout << "Your hand is full." << std::endl;
        return;
    }
    this->hand.push_back(deck->deck[0]);
    deck->deck.erase(deck->deck.begin());
    return;
}

void Player::exchange_hands(Player* exchange_player, int exchange_round) {
    this->exchange_round = exchange_round;
    this->exchange_player = exchange_player;
    this->can_exchange = false;

    std::vector<Card> tmp = this->hand;
    this->hand = exchange_player->hand;
    exchange_player->hand = tmp;
    return;
}

void Player::get_point() {
    this->point += 1;
    return;
}

void Player::print_hand() {
    std::cout << this->name << std::endl;
    for (auto card : this->hand) {
        std::cout << card.rank << card.suit << ", ";
    }
    std::cout << std::endl;
    return;
}

