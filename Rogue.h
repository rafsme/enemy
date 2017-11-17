//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_ROGUE_H
#define GAME_ROGUE_H

#include "Player.h"

class Rogue: public Player
{
public:
    Rogue():Player(E_rogue,"Rogue",100,20)
    {
        moves[0] = E_attack;
        moves[1] = E_heal;
        moves[2] = E_attack;
        moves[3] = E_heal;
    }
    void printCharacter();
};


#endif //GAME_ROGUE_H
