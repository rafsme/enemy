//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_GOBLIN_H
#define GAME_GOBLIN_H

#include "Enemy.h"

class Goblin: public Enemy
{
public:
    Goblin()
    {
        id = E_goblin;
        c_name = "Goblin";
        c_hitpoints_max = 25;
        c_hitpoints = c_hitpoints_max;
        c_strength = 10;
        moves[0] = E_attack;
        moves[1] = E_heal;
        moves[2] = E_attack;
        moves[3] = E_heal;
    }
    void printCharacter();
};


#endif //GAME_GOBLIN_H
