//
// Created by ezrozpi on 2017-11-16.
//

#include "Factory.h"
#include "Warrior.h"
#include "Rogue.h"
#include "Mage.h"
#include "Orc.h"
#include "Goblin.h"
#include "Warlock.h"



std::shared_ptr<Player> Factory::createPlayer(E_player type)
{
    switch(type)
    {
        case E_warrior:
            return std::make_shared<Warrior>();
        case E_rogue:
            return std::make_shared<Rogue>();
        case E_mage:
            return std::make_shared<Mage>();
        default:
            return nullptr;
    }
}


std::shared_ptr<Enemy> Factory::createEnemy(E_enemy type)
{
    switch(type)
    {
        case E_orc:
            return std::make_shared<Orc>();
        case E_goblin:
            return std::make_shared<Goblin>();
        case E_warlock:
            return std::make_shared<Warlock>();
        default:
            return nullptr;
    }
}