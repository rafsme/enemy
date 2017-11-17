//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "Character.h"

enum E_player
{
    E_cancel,
    E_warrior,
    E_rogue,
    E_mage
};

class Player: public Character
{
public:
    E_player id;
    Player(E_player id_player, std::string name, int hitpoints, int strenght):
            id(id_player),Character(name,hitpoints,hitpoints,strenght)
    {}
};


#endif //GAME_PLAYER_H
