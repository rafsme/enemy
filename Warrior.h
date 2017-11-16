//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_WARRIOR_H
#define GAME_WARRIOR_H

#include "Player.h"

class Warrior: public Player
{
public:
    Warrior()
    {
        id = E_warrior;
        c_name = "Warrior";
        c_hitpoints_max = 100;
        c_hitpoints = c_hitpoints_max;
        c_strenght = 20;
        moves[0] = E_attack;
        moves[1] = E_heal;
        moves[2] = E_attack;
        moves[3] = E_heal;
    }
};


#endif //GAME_WARRIOR_H
