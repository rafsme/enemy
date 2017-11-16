//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "Character.h"

enum E_player
{
    E_warrior,
    E_rogue,
    E_mage
};

class Player: public Character
{
public:
    E_player id;

};


#endif //GAME_PLAYER_H
