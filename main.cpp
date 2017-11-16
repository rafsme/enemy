#include <iostream>
#include <vector>
#include <memory>
#include <ctime>

//--------------------

#include "Player.h"
#include "Enemy.h"
#include "Move.h"
#include "Game.h"

//--------------------

int main()
{
    srand( time( NULL ) );
    while(1)
    {

        Game* game = new Game();
        game->moves = game->create_moves (game->moves);
        game->players = game->create_Player (game->players);
        game->enemies = game->create_Enemy (game->enemies);
        game->print_battle (game->players[0] , game->enemies[0]);
        game->print_moves (game->players[0],game->moves);
        game->print_attacks();
    };
    return 0;
}

//--------------------