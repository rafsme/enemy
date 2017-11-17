//
// Created by ezrozpi on 2017-11-16.
//

#include "Game.h"
#include "Factory.h"
#include <cctype>

std::vector<std::shared_ptr<Player>> Game::create_Player(std::vector<std::shared_ptr<Player>> &players)
{

    Factory* factory = new Factory();
    while(1)
    {
        std::cout << "\n[--> New Character\n\n";
        std::cout << "[1]: Warrior\n";
        std::cout << "[2]: Rogue\n";
        std::cout << "[3]: Mage\n";
        std::cout << "\n[0]: Cancel\n";
        std::cout << "\n[>]: ";

        int x;
        std::cin >> x;
        if(std::isdigit( x )==0)
        {
            switch (x)
            {
                case E_warrior:
                {
                    players.push_back (factory->createPlayer (E_warrior));
                    delete factory;
                    return players;
                }

                case E_rogue:
                {
                    players.push_back (factory->createPlayer (E_rogue));
                    delete factory;
                    return players;
                }

                case E_mage:
                {
                    players.push_back (factory->createPlayer (E_mage));
                    delete factory;
                    return players;
                }

                case E_cancel:
                    return players;

                default:
                    std::cout << "\n";
            }
        }
    }

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

void Game::show_Selected(std::vector<std::shared_ptr<Player>> players)
{
    if(players.empty ())
        std::cout << "Empty";
    else
        std::cout << players.at(players.size ()-1)->c_name;
    std::cout << " " << players.size ();
}

int Game::print_Main_Menu(Game* game)
{

    while(1)
    {
        std::cout << "\n[--> Main Menu\n\n";
        std::cout << "[1]: Create \n";
        std::cout << "[2]: Select ( " ;
        game->show_Selected (players);
        std::cout << " )\n";
        std::cout << "[3]: Stats \n";
        std::cout << "[4]: Battle \n";
        std::cout << "\n[0]: Exit \n";
        std::cout << "\n[>]: ";
        int x;
        std::cin >> x;
        if (std::isdigit( x)==0)
        {
            switch (x)
            {
                case 1: {
                    game->create_Player (game->players);
                }
                    break;
                case 0: {
                    std::cout << "Exit Game";
                    return 0;
                }
                default:
                    std::cout << "\n";
            }
        }
    }
}