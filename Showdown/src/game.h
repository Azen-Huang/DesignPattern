#pragma once

#include "deck.h"
#include "ai_player.h"
#include "human_player.h"
#include "card.h"
#include "player.h"

#include <unordered_map>
class Game {
public:
    int round;
    std::vector<Player*> players;
    Deck* deck;

    Game(int num_AI);
    void start();
    Player* get_winner(std::vector<std::pair<Player*, Card>> show_pool);
    void one_round();
    bool isEnd();
    void final_game_info();
};

Game::Game(int num_AI) : round(0) {
    assert(num_AI <= 4); 
    for (int i = 0; i < num_AI; ++i) {
        Player* player = new AI_Player();
        player->name_himself("AI_" + std::to_string(i));
        players.push_back(player);
    }

    for (int i = 0; i < 4 - num_AI; ++i) {
        Player* player = new Human_Player();
        player->is_human = true;
        player->name_himself("Human_" + std::to_string(i));
        players.push_back(player);
    }

    deck = new Deck();
    std::cout << "Deck Size: " << deck->deck.size() << std::endl;
}

void Game::start() {
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Start shuffle." << std::endl;
    deck->shuffle();

    std::cout << "Start Draw." << std::endl;
    int n = deck->deck.size();
    for (int i = 0; i < n; ++i) {
        Player* player = players[i % 4];
        player->draw(deck);
    }

    std::cout << "Draw End." << std::endl;
    std::cout << "Deck Size: " << deck->deck.size() << std::endl;
    for (auto player : players) {
        player->print_hand();
    }
    std::cout << "--------------------------------------------" << std::endl;
}

void Game::one_round() {
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Round " << this->round << std::endl;
    for (int i = 0; i < players.size(); ++i) {
        if (players[i]->is_human && players[i]->can_exchange) {
            std::string is_exchange_hand;
            std::cout << "Do your want exchange your hand cards(y, n): ";
            std::cin >> is_exchange_hand;
            if (is_exchange_hand == "y") {
                std::cout << "Your id is " << i << std::endl;
                std::cout << "Whose hand do you want to exchange(0, 1, 2, 3): ";
                int idx;
                std::cin >> idx;
                players[i]->exchange_hands(players[idx], this->round);
            }
        }

        if (!players[i]->can_exchange && this->round - players[i]->exchange_round == 3) {
            players[i]->exchange_hands(players[i]->exchange_player, 0);
        }
    }

    std::vector<std::pair<Player*, Card>> show_pool;
    for (auto player : players) {
        if (player->is_human) {
            int choice;
            player->print_hand();
            std::cout << "Choose your card(0-idx): ";
            std::cin >> choice;
            show_pool.push_back({player, player->show(choice)});
        }
        else {
            show_pool.push_back({player, player->show(-1)});
        }
    }

    Player* winner = this->get_winner(show_pool);
    winner->get_point();
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Player " << winner->name << " win!" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    for (auto [player, card] : show_pool) {
        std::cout << "Player " << player->name << " choose " << card.rank << card.suit << std::endl;
    }
    this->round += 1;
    std::cout << "--------------------------------------------" << std::endl;
}

Player* Game::get_winner(std::vector<std::pair<Player*, Card>> show_pool) {
    Player* winner;
    int max_score = -1;

    std::unordered_map<std::string, int> rank_score = {
        {"1", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, 
        {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, 
        {"J", 11}, {"Q", 12}, {"K", 13}
    };
    std::unordered_map<std::string, int> suit_score = {
        {"C", 0}, 
        {"D", 14},
        {"H", 14 * 2}, 
        {"S", 14 * 3}
    }; 

    for (auto [player, card] : show_pool) {
        int score = rank_score[card.rank] + suit_score[card.suit];
        if (score > max_score) {
            max_score = score;
            winner = player;
        }
    }

    return winner;
}

bool Game::isEnd() {
    return this->round * 4 != 52;
}

void Game::final_game_info() {
    std::cout << "--------------------------------------------" << std::endl;
    std::string winner_name;
    int max_point = -1;
    for (auto player : this->players) {
        std::cout << player->name << " Pointer: " << player->point << std::endl;
        if (max_point < player->point) {
            max_point = player->point;
            winner_name = player->name;
        }
    }
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Winner is " << winner_name << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
}