#include "Catalogue.hpp"
#include "Dungeon.hpp"
#include <iostream>

#define NUM_ROOMS 20

int main(){
    Catalogue catalogue;
    Dungeon dungeon;
    if(!catalogue.loadFromCSV("media/monsters.csv")){
        std::cout << "Could not create file!" << std::endl;
        return 0;
    }
    std::cout << "Creating Dungeon..." << std::endl;
    for (int i = 0; i < NUM_ROOMS; i++){
        Monster *pMonster = nullptr;
        pMonster = catalogue.getRandomMonster();
        if(!pMonster){
            std::cout << "Error obtaining random monster!" << std::endl;
            return 0;
        }

        Monster copyMonster = *pMonster;
        if(!dungeon.createRoom(copyMonster)){
            std::cout << "Could not create room!" << std::endl;
            return 0;
        }
    }
    if(!dungeon.printRooms()) {
        std::cout << "Error printing rooms!" << std::endl;
        return 0;
    }
}