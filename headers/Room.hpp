#pragma once
#include "Monster.hpp"

class Room{
public:
    void setMonster(Monster monster);
    Monster& getMonster();

    friend std::ostream& operator <<(std::ostream &COUT, Room &ROOM);

private:
    Monster _monster;
};