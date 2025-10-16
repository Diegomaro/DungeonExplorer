#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Catalogue.hpp"

Catalogue::Catalogue(){}

Catalogue::~Catalogue(){}

bool Catalogue::loadFromCSV(const std::string& filename){
    std::ifstream file;
    std::string line;
    file.open(filename);
    if(!file.is_open()){
        return false;
    }

    std::getline(file,line);
    //gets rid of the definition line
    while(std::getline(file, line)){
        Monster monster = Monster();
        int ctr = 0;
        std::stringstream ss(line);
        std::string cell;
        while(getline(ss, cell, ',')){
            loadCurrentAttribute(monster, ss, cell, ctr);
            ctr++;
        }
        tree.insertNode(monster);
    }
    file.close();
    return true;
}

bool Catalogue::printAllMonsters(){
    return tree.printAll();
}

void Catalogue::loadCurrentAttribute(Monster &monster, std::stringstream &ss, std::string cell, int ctr){
    switch(ctr){
        case 0: {				
            monster.setName(cell);
        } break;
        case 1: {				
            int cr;
            ss >> cr;
            monster.setCr(cr);
            //hacer comprobacion de floats
        } break;
        case 2: {				
            monster.setType(cell);
        } break;
        case 3: {				
            monster.setSize(cell);
        } break;
        case 4: {		
            int ac;
            ss >> ac;		
            monster.setAc(ac);
        } break;
        case 5: {	
            int hp;
            ss >> hp;			
            monster.setHp(hp);
        } break;
        case 6: {				
            monster.setAllign(cell);
        } break;
        default: {
            std::cout << "Error defining monsters!" << std::endl;
        }
    }
}