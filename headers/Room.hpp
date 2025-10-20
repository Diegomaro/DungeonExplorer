#pragma once
#include "Monster.hpp"

class Room{
public:
    Room(Monster monster);
    Monster& getMonster();
    friend std::ostream& operator << (std::ostream &COUT, Room &ROOM);
private:
    Monster _monster;
};