//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_ROGUE_H
#define GAME_ROGUE_H

#include "Player.h"

class Rogue: public Player
{
public:
    Rogue()
    {
        id = E_rogue;
        c_name = "Rogue";
        c_hitpoints_max = 100;
        c_hitpoints = c_hitpoints_max;
        c_strenght = 20;
        moves[0] = E_attack;
        moves[1] = E_throw_attack;
        moves[2] = E_pow_attack;
        moves[3] = E_heal;
    }
    void printCharacter();
};


#endif //GAME_ROGUE_H
