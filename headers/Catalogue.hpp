#pragma once
#include <string>
#include "BinaryTree.hpp"

class Catalogue{
public:
    Catalogue();
    ~Catalogue();
    bool loadFromCSV(const std::string& filename);
    bool printAllMonsters(); //temporal function to check if all monsters were added
    Monster* getRandomMonster();
private:
    int _size;
    BinaryTree<Monster> _tree;
    bool loadCurrentAttribute(Monster &monster, std::string cell, int ctr);
    bool integerCheck(std::string string);
    bool numericCheck(std::string string);
};