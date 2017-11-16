//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_WARLOCK_H
#define GAME_WARLOCK_H

#include "Enemy.h"

class Warlock: public Enemy
{
public:
    Warlock()
    {
        id = E_warlock;
        c_name = "Warlock";
        c_hitpoints_max = 100;
        c_hitpoints = c_hitpoints_max;
        c_strenght = 30;
        moves[0] = E_attack;
        moves[1] = E_heal;
        moves[2] = E_attack;
        moves[3] = E_heal;
    }
    void printCharacter();
};


#endif //GAME_WARLOCK_H
