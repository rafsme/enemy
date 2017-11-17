//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include <iostream>
#include <array>

enum E_move
{
    E_attack,
    E_heal
};


class Character
{
public:
    std::string c_name;
    int c_hitpoints;
    int c_hitpoints_max;
    int c_strength;
    std::array<E_move,4> moves;

    Character() = default;
    ~Character() = default;

    Character(std::string name,int hitpoints,int hitpoints_max,int strenght):
            c_name(name),c_hitpoints(hitpoints),c_hitpoints_max(hitpoints_max),c_strength(strenght)
    {}

    virtual void printCharacter() = 0;
};



#endif //GAME_CHARACTER_H
