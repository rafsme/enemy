//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "Character.h"

enum E_enemy
{
    E_orc,
    E_goblin,
    E_warlock
};

class Enemy: public Character
{
public:
    E_enemy id;
};


#endif //GAME_ENEMY_H
