#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>

#include "Catalogue.hpp"

Catalogue::Catalogue(){
    _size = 0;
    std::srand((std::time(nullptr)));
}

Catalogue::~Catalogue(){}

bool Catalogue::loadFromCSV(const std::string& filename){
    std::ifstream file;
    std::string line;
    file.open(filename);
    if(!file.is_open()){
        return false;
    }
    std::cout << "Getting monsters..." << std::endl;
    std::getline(file,line);
    while(std::getline(file, line)){
        Monster monster = Monster();
        int ctr = 0;
        std::stringstream ss(line);
        std::string cell;
        while(getline(ss, cell, ',')){
            if(!loadCurrentAttribute(monster, cell, ctr))return false;
            ctr++;
        }
        _tree.insertNode(monster);
        _size++;
    }
    file.close();
    return true;
}

bool Catalogue::loadCurrentAttribute(Monster &monster, std::string cell, int ctr){
    if(cell.empty()) return false;
    switch(ctr){
        case 0: {
            monster.setName(cell);
        } break;
        case 1: {
            double cr;
            if(numericCheck(cell)){
                cr = std::stod(cell);
                monster.setCr(cr);
            } else return false;
        } break;
        case 2: {
            monster.setType(cell);
        } break;
        case 3: {
            monster.setSize(cell);
        } break;
        case 4: {
            int ac;
            if(integerCheck(cell)){
                ac = std::stoi(cell);
                monster.setAc(ac);
            } else return false;
        } break;
        case 5: {
            int hp;
            if(integerCheck(cell)){
                hp = std::stoi(cell);
                monster.setHp(hp);
            } else return false;
        } break;
        case 6: {
            monster.setAllign(cell);
        } break;
        default: {
            std::cout << "Error defining monsters!" << std::endl;
            return false;
        }
    }
    return true;
}

bool Catalogue::integerCheck(std::string string){
    for(int i = 0; i < (int)string.size(); i++){
        if(string[i] == '0' || string[i] == '1' ||
            string[i] == '2' || string[i] == '3' ||
            string[i] == '4' || string[i] == '5' ||
            string[i] == '6' || string[i] == '7' ||
            string[i] == '8' || string[i] == '9'){
        } else {
            std::cout << "Error with integer value!" << std::endl;
            return false;
        }   
    }
    return true;
}

bool Catalogue::numericCheck(std::string string){
    bool dot = false;
    if(string[0] == '.') {
            std::cout << "Error with float value!" << std::endl;
        return false;
    }
    for(int i = 0; i < (int)string.size(); i++){
        if(string[i] == '0' || string[i] == '1' ||
            string[i] == '2' || string[i] == '3' ||
            string[i] == '4' || string[i] == '5' ||
            string[i] == '6' || string[i] == '7' ||
            string[i] == '8' || string[i] == '9'){
        } else if(string[i] == '.' && dot == false){
            dot = true;
        } else {
            std::cout << "Error with float value!" << std::endl;
            return false;
        }
    }
    return true;
}

Monster* Catalogue::getRandomMonster(){
    return _tree.getRandomNode();
}

bool Catalogue::printAllMonsters(){
    return _tree.printAll();
}