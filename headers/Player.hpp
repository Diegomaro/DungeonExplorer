#include <string>
#include "DoubleLinkedList.hpp"
#include "Monster.hpp"
class Player{
public:
private:
    short hp;
    std::string race;
    std::string nombre;
    short mp;
    DoubleLinkedList<Monster> slayedMonsters;
};