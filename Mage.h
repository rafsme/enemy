//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_MAGE_H
#define GAME_MAGE_H

#include "Player.h"

class Mage: public Player
{
public:
    Mage()
    {
        id = E_mage;
        c_name = "Mage";
        c_hitpoints_max = 100;
        c_hitpoints = c_hitpoints_max;
        c_strenght = 20;
        moves[0] = E_attack;
        moves[1] = E_heal;
        moves[2] = E_attack;
        moves[3] = E_heal;
    }
    void printCharacter();
};


#endif //GAME_MAGE_H
