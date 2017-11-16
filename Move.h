//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_MOVE_H
#define GAME_MOVE_H

#include <iostream>

enum E_move
{
    E_attack,
    E_heal,
    E_pow_attack,
    E_throw_attack
};

class Move
{
public:
    E_move id;
    std::string name;
    int damage;
    bool target;
    int accuracy;
    int crit_accuracy;
    Move(E_move id,std::string name,bool target,int damage,int accuracy,int crit_accuracy):
            id(id),name(name),target(target),damage(damage), accuracy(accuracy),crit_accuracy(crit_accuracy) {}
};


#endif //GAME_MOVE_H
