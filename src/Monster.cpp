#include "Monster.hpp"
Monster::Monster(){}

Monster::~Monster(){}

void Monster::setName(std::string name) {_name = name;}

void Monster::setCr(double cr){_cr = cr;}

void Monster::setType(std::string type){_type = type;}

void Monster::setSize(std::string size){_size = size;}

void Monster::setAc(int ac){_ac = ac;}

void Monster::setHp(int hp){_hp = hp;}

void Monster::setAllign(std::string allign){_align = allign;}

std::string Monster::getName(){return _name;}

double Monster::getCr(){return _cr;}

std::string Monster::getType(){return _type;}

std::string Monster::getSize(){return _size;}

int Monster::getAc(){return _ac;}

int Monster::getHp(){return _hp;}

std::string Monster::getAllign(){return _align;}

bool Monster::operator > (Monster &RIGHT){
    return (this->getName() > RIGHT.getName());
}

bool Monster::operator < (Monster &RIGHT){
    return (this->getName() < RIGHT.getName());
}

bool Monster::operator >= (Monster &RIGHT){
    return (this->getName() >= RIGHT.getName());
}

std::ostream& operator << (std::ostream& COUT, Monster &MONSTER){
    return COUT << MONSTER.getName();
}