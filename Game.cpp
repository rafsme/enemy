//
// Created by ezrozpi on 2017-11-16.
//

#include "Game.h"
#include "Factory.h"

std::vector<std::shared_ptr<Player>> Game::create_Player(std::vector<std::shared_ptr<Player>> players)
{
    Factory* factory = new Factory();
    int x = (std::rand () % 3);
    switch (x)
    {
        case E_warrior:
            players.push_back (factory->createPlayer (E_warrior));
        case E_rogue:
            players.push_back (factory->createPlayer (E_rogue));
        case E_mage:
            players.push_back (factory->createPlayer (E_mage));
    }
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
    return enemies;
}


std::vector<Move*> Game::create_moves(std::vector<Move*> moves)
{
    moves.push_back (new Move(E_attack,"Fast attack",0,20,90,5));
    moves.push_back (new Move(E_pow_attack,"Powerful swing",0,40,70,10));
    moves.push_back (new Move(E_throw_attack,"Throw weapon",0,50,50,15));
    moves.push_back (new Move(E_heal,"Wound heal",1,10,100,10));

    return moves;
}

void Game::print_attacks(std::shared_ptr<Player> player, std::vector<Move*> moves)
{
    int x;
    std::cin >> x;
    E_move mov = player->moves[x];


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

void calc_Battle(std::shared_ptr<Player> player,std::shared_ptr<Enemy> enemy)
{
    player->c_hitpoints -= 10;
}