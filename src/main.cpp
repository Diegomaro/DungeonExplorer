#include "Catalogue.hpp"
#include <iostream>

int main(){
    Catalogue catalogue;
    if(!catalogue.loadFromCSV("media/monsters.csv")){
        std::cout << "Could not find file!" << std::endl;
    }
    catalogue.printAllMonsters();
}