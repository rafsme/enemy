cmake_minimum_required(VERSION 3.8)
project(Game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Character.cpp Character.h Player.cpp Player.h Warrior.cpp Warrior.h Rogue.cpp Rogue.h Mage.cpp Mage.h Enemy.cpp Enemy.h Orc.cpp Orc.h Goblin.cpp Goblin.h Warlock.cpp Warlock.h Move.cpp Move.h Factory.cpp Factory.h Game.cpp Game.h)
add_executable(Game ${SOURCE_FILES})