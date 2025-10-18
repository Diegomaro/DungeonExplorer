#pragma once
#include <string>
#include "DoubleLinkedList.hpp"
#include "Monster.hpp"

class Player{
public: 
    Player();
    ~Player();
    void alterHp(short hp); //checar esto
    void setName(std::string);
    bool slayedMonster(Monster *pMonster);
private:
    #define MAX_HEALTH 999
    short _hp;
    std::string _race;
    std::string _name;
    short _mp;
    DoubleLinkedList<Monster> slayedMonsters;
};