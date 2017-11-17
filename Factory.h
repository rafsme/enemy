//
// Created by ezrozpi on 2017-11-16.
//

#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H

#include <memory>
#include "Player.h"
#include "Enemy.h"

class Factory
{
public:
    Factory(){}
    Factory(const Factory &);
    Factory& operator= (const Factory&);
    ~Factory(){}
    static Factory& getInstance()
    {
        static Factory instance;
        return instance;
    }
    static std::shared_ptr<Player> createPlayer(E_player type);
    static std::shared_ptr<Enemy> createEnemy(E_enemy type);
};

#endif //GAME_FACTORY_H
