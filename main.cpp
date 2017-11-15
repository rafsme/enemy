//INCLUDE
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

//ENUMS
enum E_enemy
{
    E_orc,
    E_goblin,
    E_warlock
};


//ENEMIES
class Enemy
{
public:
    std::string enemy_name;
    int enemy_health;
    int enemy_mana;
    int enemy_max_health;
    int enemy_max_mana;
    int enemy_strenght;
    int enemy_dexterity;
    int enemy_vitality;
    int enemy_energy;
    int enemy_action = 5;


    Enemy() = default;
    void print();
    virtual void attack() = 0;
    ~Enemy()= default;

};

void Enemy::print()
{
    std::cout << "----------" << '\n';
    std::cout << "[  name  ]: " << enemy_name << '\n';
    std::cout << "[ health ]: " << enemy_health << '/' << enemy_max_health << '\n';
    std::cout << "[  mana  ]: " << enemy_mana << '/' << enemy_max_mana << '\n';
    std::cout << "[ STR:" << enemy_strenght << " DEX:" << enemy_dexterity;
    std::cout << " VIT:" << enemy_vitality << " ENE:" << enemy_energy << " ]" << '\n' << '\n';
}

class Orc: public Enemy
{
public:
    Orc()
    {
        enemy_name = "Orc";
        enemy_strenght = 25;
        enemy_dexterity = 5;
        enemy_vitality = 20;
        enemy_energy = 10;
        enemy_health = 3*enemy_vitality;
        enemy_mana = 1*enemy_energy;
        enemy_max_health = enemy_health;
        enemy_max_mana = enemy_mana;


    }
    void attack()
    {

    };
};


class Goblin: public Enemy
{
public:
    Goblin()
    {
        enemy_name = "Goblin";
        enemy_strenght = 15;
        enemy_dexterity = 15;
        enemy_vitality = 15;
        enemy_energy = 15;
        enemy_health = 1.5*enemy_vitality;
        enemy_mana = 1.5*enemy_energy;
        enemy_max_health = enemy_health;
        enemy_max_mana = enemy_mana;
    }
    void attack() {};
};

class Warlock: public Enemy
{
public:
    Warlock()
    {
        enemy_name = "Warlock";
        enemy_strenght = 5;
        enemy_dexterity = 10;
        enemy_vitality = 5;
        enemy_energy = 30;
        enemy_health = 1*enemy_vitality;
        enemy_mana = 3*enemy_energy;
        enemy_max_health = enemy_health;
        enemy_max_mana = enemy_mana;
    }
    void attack() {};
};

//FACTORY
class Factory
{
public:
    Factory() = default;
    static std::shared_ptr<Enemy> createEnemy(E_enemy type);
};

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
}