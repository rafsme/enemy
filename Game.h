//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <vector>
#include <memory>
#include "Move.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
    std::vector<Move*> moves;
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::shared_ptr<Enemy>>  enemies;

    Game()
    {

    }
    std::vector<std::shared_ptr<Player>> create_Player(std::vector<std::shared_ptr<Player>> players);
    std::vector<std::shared_ptr<Enemy>> create_Enemy(std::vector<std::shared_ptr<Enemy>> enemies);
    std::vector<Move*> create_moves(std::vector<Move*> moves);
    void print_battle(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy);
    void print_moves(std::shared_ptr<Player> player,std::vector<Move*> moves);
    void print_attacks();
    void showMove(std::shared_ptr<Player> player);
    int print_Main_Menu(Game* game);
};


#endif //GAME_GAME_H
