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
    E_player id;
};


    class Warrior: public Player
    {
    public:
        Warrior()
        {
            id = E_warrior;
            c_name = "Warrior";
            c_hitpoints_max = 100;
            c_hitpoints = c_hitpoints_max;
            c_strenght = 20;
        }
    };


    class Rogue: public Player
    {
    public:
        Rogue()
        {
            id = E_rogue;
            c_name = "Rogue";
            c_hitpoints_max = 100;
            c_hitpoints = c_hitpoints_max;
            c_strenght = 20;
        }
    };


    class Mage: public Player
    {
    public:
        Mage()
        {
            id = E_mage;
            c_name = "Mage";
            c_hitpoints_max = 100;
            c_hitpoints = c_hitpoints_max;
            c_strenght = 20;
        }
    };


//--------------------------------------------


class Enemy: public Character
{
public:
    E_enemy id;
};


    class Orc: public Enemy
    {
    public:
        Orc()
        {
            id = E_orc;
            c_name = "Orc";
            c_hitpoints_max = 50;
            c_hitpoints = c_hitpoints_max;
            c_strenght = 20;
        }
    };


    class Goblin: public Enemy
    {
    public:
        Goblin()
        {
            id = E_goblin;
            c_name = "Goblin";
            c_hitpoints_max = 25;
            c_hitpoints = c_hitpoints_max;
            c_strenght = 10;
        }
    };


    class Warlock: public Enemy
    {
    public:
        Warlock()
        {
            id = E_warlock;
            c_name = "Warlock";
            c_hitpoints_max = 100;
            c_hitpoints = c_hitpoints_max;
            c_strenght = 30;
        }
    };


//--------------------------------------------


class Factory
{
public:
    Factory() = default;
    static std::shared_ptr<Player> createPlayer(E_player type);
    static std::shared_ptr<Enemy> createEnemy(E_enemy type);
};


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


//--------------------------------------------

class Game
{
public:
    void print_battle(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy);
    void print_attacks();
};


void Game::print_battle(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy)
{

    std::cout << "-------------" << '\n';
    std::cout << enemy->c_name << '\n';
    std::cout << enemy->c_hitpoints << "|" << enemy->c_hitpoints_max << '\n';
        switch(enemy->id)
    {
        case E_orc:
        {
            std::cout << "      _" << '\n';
            std::cout << "     )_(" << '\n';
            std::cout << "   C|/|\\|D" << '\n';
            std::cout << "    | | |" << '\n';
            std::cout << "     / \\" << '\n';
        }
            break;
        case E_goblin:
        {
            std::cout << "      _" << '\n';
            std::cout << "     \\_/" << '\n';
            std::cout << "   |\\/|\\|" << '\n';
            std::cout << "   \\_\\| |" << '\n';
            std::cout << "     / \\" << '\n';
        }
            break;
        case E_warlock:
        {
            std::cout << "      _" << '\n';
            std::cout << "    @(O)" << '\n';
            std::cout << "    |/|\\" << '\n';
            std::cout << "    | |" << '\n';
            std::cout << "    |/ \\" << '\n';
        }
            break;
        default:
            break;
    }

    std::cout << '\n';
    std::cout << '\n';

    switch(player->id)
    {
        case E_warrior:
        {
            std::cout << "     |_|" << '\n';
            std::cout << "     [_] /" << '\n';
            std::cout << "    /\\|\\/_" << '\n';
            std::cout << "    \\/|/" << '\n';
            std::cout << "     / \\" << '\n';
        }
            break;
        case E_rogue:
        {
            std::cout << "      _" << '\n';
            std::cout << "     /_\\" << '\n';
            std::cout << "    \\/|\\/" << '\n';
            std::cout << "      |" << '\n';
            std::cout << "     / \\" << '\n';
        }
            break;
        case E_mage:
        {
            std::cout << "      _" << '\n';
            std::cout << "     (0) *" << '\n';
            std::cout << "     /|\\/" << '\n';
            std::cout << "      |/" << '\n';
            std::cout << "     / \\" << '\n';
        }
            break;
        default:
            break;
    }
    std::cout << player->c_name << '\n';
    std::cout << player->c_hitpoints << "|" << player->c_hitpoints_max << '\n';
    std::cout << "-------------" << '\n';
}


//--------------------------------------------


int main()
{

    Game* game = new Game();
    Factory* factory = new Factory();
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::shared_ptr<Enemy>> enemies;
    int x;
    int n=10;
    for(int i=0; i<n;i++)
    {
        x = (std::rand () % 3);
        switch (x)
        {
            case E_warrior:
                players.push_back (factory->createPlayer (E_warrior));
            case E_rogue:
                players.push_back (factory->createPlayer (E_rogue));
            case E_mage:
                players.push_back (factory->createPlayer (E_mage));
        }


        x = (std::rand () % 3);
        switch (x)
        {
            case E_orc:
                enemies.push_back (factory->createEnemy (E_orc));
            case E_goblin:
                enemies.push_back (factory->createEnemy (E_goblin));
            case E_warlock:
                enemies.push_back (factory->createEnemy (E_warlock));
        }
        game->print_battle (players[ i ] , enemies[ i ]);
    }

    return 0;
}