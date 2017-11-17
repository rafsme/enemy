//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_ORC_H
#define GAME_ORC_H

#include "Enemy.h"

class Orc: public Enemy
{
public:
    Orc()
    {
        id = E_orc;
        c_name = "Orc";
        c_hitpoints_max = 50;
        c_hitpoints = c_hitpoints_max;
        c_strength = 20;
        moves[0] = E_attack;
        moves[1] = E_heal;
        moves[2] = E_attack;
        moves[3] = E_heal;
    }
    void printCharacter();
};


#endif //GAME_ORC_H
