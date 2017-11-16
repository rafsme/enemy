//
// Created by ezrozpi on 2017-11-16.
//

#include "Game.h"
#include "Factory.h"

std::vector<std::shared_ptr<Player>> Game::create_Player(std::vector<std::shared_ptr<Player>> players)
{

    Factory* factory = new Factory();

    std::cout << "[1]: Warrior\n";
    std::cout << "[2]: Rogue\n";
    std::cout << "[3]: Mage\n";
    std::cout << "[>]: ";

    int x;
    std::cin >> x;

    switch (x)
    {
        case E_warrior:
            players.push_back (factory->createPlayer (E_warrior));
        case E_rogue:
            players.push_back (factory->createPlayer (E_rogue));
        case E_mage:
            players.push_back (factory->createPlayer (E_mage));
    }
    delete factory;
    return players;
}


std::vector<std::shared_ptr<Enemy>> Game::create_Enemy(std::vector<std::shared_ptr<Enemy>> enemies)
{
    Factory* factory = new Factory();
    int x = (std::rand () % 3);
    switch (x)
    {
        case E_orc:
            enemies.push_back (factory->createEnemy (E_orc));
        case E_goblin:
            enemies.push_back (factory->createEnemy (E_goblin));
        case E_warlock:
            enemies.push_back (factory->createEnemy (E_warlock));
    }
    delete factory;
    return enemies;
}


std::vector<Move*> Game::create_moves(std::vector<Move*> moves)
{
    moves.push_back (new Move(E_attack,"Attack",0,20));
    moves.push_back (new Move(E_heal,"Heal",1,10));
    return moves;
}

void Game::print_attacks()
{
    int x;
    std::cin >> x;
}

void Game::print_battle(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy)
{

    std::cout << "-------------" << '\n';
    std::cout << enemy->c_name << '\n';
    std::cout << enemy->c_hitpoints << "|" << enemy->c_hitpoints_max << '\n';
    enemy->printCharacter ();
    std::cout << '\n';
    std::cout << '\n';
    player->printCharacter ();
    std::cout << player->c_name << '\n';
    std::cout << player->c_hitpoints << "|" << player->c_hitpoints_max << '\n';
    std::cout << "-------------" << '\n';
}


void Game::print_moves(std::shared_ptr<Player> player,std::vector<Move*> moves)
{
    int n = 4;
    //std::cout << moves.size () <<'\n';
    for(int i = 0; i < n; i++)
    {
        std::cout << "[" <<i+1<<"]: ";
        for(int j = 0; j < moves.size (); j++)
        {
            if (player->moves[ i ] == moves[ j ]->id)
            {
                std::cout << moves[ j ]->name << " ";
                if (moves[ j ]->target == 0)
                {
                    std::cout << "enemy (-";
                    std::cout << moves[j]->damage << "hp)\n";
                }
                else
                {
                    std::cout << "yourself (+";
                    std::cout << moves[j]->damage << "hp)\n";
                }
            }

        }
    }

}

int Game::print_Main_Menu(Game* game)
{

    while(1)
    {
        std::cout << "[1]: Create \n";

        std::cout << "[2]: Select \n";
        std::cout << "[3]: Stats \n";
        std::cout << "[4]: Battle \n";
        std::cout << "[0]: Exit \n";
        std::cout << "[>]: ";
        int x;
        std::cin >> x;
        switch(x)
        {
            case 1:
            {
                game->create_Player(game->players);
            }
            break;
            case 0:
            {
                std::cout << "Exit Game";
                return 0;
            }
    }
    }
}