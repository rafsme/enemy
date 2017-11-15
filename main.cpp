#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>


//--------------------------------------------


enum E_player
{
    E_warrior,
    E_rogue,
    E_mage
};


enum E_enemy
{
    E_orc,
    E_goblin,
    E_warlock
};


//--------------------------------------------


class Character
{
public:
    std::string c_name;
    int c_hitpoints;
    int c_hitpoints_max;
    int c_strenght;

    Character() = default;
    ~Character() = default;

};


//--------------------------------------------


class Player: public Character
{
public:

};


    class Warrior: public Player
    {
    public:
        Warrior()
        {

        }
    };


    class Rogue: public Player
    {
    public:
        Rogue()
        {

        }
    };


    class Mage: public Player
    {
    public:
        Mage()
        {

        }
    };


//--------------------------------------------


class Enemy: public Character
{
public:

};


    class Orc: public Enemy
    {
    public:
        Orc()
        {

        }
    };


    class Goblin: public Enemy
    {
    public:
        Goblin()
        {

        }
    };


    class Warlock: public Enemy
    {
    public:
        Warlock()
        {

        }
    };


//--------------------------------------------


class Factory
{
public:
    Factory() = default;
    static std::shared_ptr<Character> createPlayer(E_player type);
    static std::shared_ptr<Character> createEnemy(E_enemy type);
};


    std::shared_ptr<Character> Factory::createPlayer(E_player type)
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


    std::shared_ptr<Character> Factory::createEnemy(E_enemy type)
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


//--------------------------------------------
//--------------------------------------------
//--------------------------------------------
//--------------------------------------------


int main()
{
    return 0;
}

/*




//FACTORY



//MAIN
int main()
{
    srand( time( NULL ) );
    Factory* factory = new Factory();
    std::vector<std::shared_ptr<Enemy>> enemies;
    int N = 10;

    for(int i = 0; i < N; i++)
    {
        int x = (std::rand()%3);
        switch(x)
        {
            case E_orc:
                enemies.push_back (factory->createEnemy (E_orc));
            case E_goblin:
                enemies.push_back (factory->createEnemy (E_goblin));
            case E_warlock:
                enemies.push_back (factory->createEnemy (E_warlock));
        }
    }

    for(int i = 0; i < N; i++)
    {
        enemies[i]->print();
    }
    return 0;
}*/