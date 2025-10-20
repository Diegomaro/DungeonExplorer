#include "Room.hpp"

Room::Room(Monster monster): _monster(monster) {}

Monster& Room::getMonster(){
    return _monster;
}

std::ostream& operator << (std::ostream& COUT, Room &ROOM){
    return COUT << ROOM.getMonster().getName();
}