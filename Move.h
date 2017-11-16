//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_MOVE_H
#define GAME_MOVE_H

#include "Character.h"

class Move
{
public:
    E_move id;
    std::string name;
    int damage;
    bool target;
    Move(E_move id,std::string name,bool target,int damage):id(id),name(name),target(target),damage(damage) {}
};


#endif //GAME_MOVE_H
