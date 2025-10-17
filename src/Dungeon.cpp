#include "Dungeon.hpp"

Dungeon::Dungeon(){}

bool Dungeon::createRoom(Monster monster){
    Room *newRoom = new(std::nothrow) Room;
    if(!newRoom){
        return false;
    }
    newRoom->setMonster(monster);
    if(rooms.insertTail(*newRoom)) return true;
    return false;
}
bool Dungeon::clearRooms(){
    if(rooms.clear()) return true;
    return false;
}

bool Dungeon::printRooms(){
    if(rooms.printAll()) return true;
    return false;
}
