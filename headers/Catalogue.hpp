#pragma once
#include <string>
#include "BinaryTree.hpp"

class Catalogue{
    public:
        Catalogue();
        ~Catalogue();
        bool loadFromCSV(const std::string& filename);
        bool printAllMonsters(); //temporal function
        //Monster getRandomMonster();
    private:
        void loadCurrentAttribute(Monster &monster, std::stringstream &ss, std::string cell, int ctr);
        BinaryTree<Monster> tree;
};