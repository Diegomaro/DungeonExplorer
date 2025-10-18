#pragma once
#include "DoubleLinkedList.hpp"
#include "Room.hpp"

class Dungeon{
public:
    Dungeon();
    bool createRoom(Monster monster);
    bool clearRooms();
    bool printRooms();
private:
    DoubleLinkedList<Room> rooms;
};