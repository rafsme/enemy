//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include <iostream>

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
    int c_strenght;
    E_move moves[4];

    Character() = default;
    ~Character() = default;
    virtual void printCharacter() = 0;
};


#endif //GAME_CHARACTER_H
