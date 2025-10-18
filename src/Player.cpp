#include "Player.hpp"

Player::Player(): _hp(100) {}

Player::~Player(){
    slayedMonsters.clear();
}

void Player::setName(std::string name){
    _name = name;
}

void Player::alterHp(short hp){
    if(_hp + hp > 999){
        _hp = 999;
        std::cout << "Max health reached!" << std::endl;
    }
    _hp += hp;
}

bool Player::slayedMonster(Monster *pMonster){
    if(!pMonster){
        return false;
    }
    Monster copyMonster = *pMonster;
    slayedMonsters.insertNodeInOrder(copyMonster);
    return true;
}