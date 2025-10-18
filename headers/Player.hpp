#pragma once
#include <string>
#include "DoubleLinkedList.hpp"
#include "Monster.hpp"

class Player{
public: 
    Player();
    ~Player();
    void alterHp(short hp);
    void setName(std::string name);
    bool slayedMonster(Monster *pMonster);
private:
    #define MAX_HEALTH 999
    short _hp;
    std::string _race;
    std::string _name;
    short _mp;
    DoubleLinkedList<Monster> slayedMonsters;
};