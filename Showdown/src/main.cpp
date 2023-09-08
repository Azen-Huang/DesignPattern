#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <sstream>

#include "game.h"

using namespace std;
/*
// run code //
make
./main
// run code //
*/

int main() {
    Game* game = new Game(3);
    game->start();
    while (game->isEnd()) {
        game->one_round();
    }
    game->final_game_info();
    delete game;
    return 0;
}