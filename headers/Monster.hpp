#pragma once
#include <string>

class Monster{
public:
    Monster();
    ~Monster();
    void setName(std::string);
    void setCr(double cr);
    void setType(std::string);
    void setSize(std::string);
    void setAc(int ac);
    void setHp(int hp);
    void setAllign(std::string);
    std::string getName();
    double getCr();
    std::string getType();
    std::string getSize();
    int getAc();
    int getHp();
    std::string getAllign();
    bool operator > (Monster &RIGHT);
    bool operator < (Monster &RIGHT);
    bool operator >= (Monster &RIGHT);
    friend std::ostream& operator << (std::ostream &COUT, Monster &MONSTER);
private:
    std::string _name;
    double _cr; //challenge rating
    std::string _type;
    std::string _size;
    int _ac; //armor class
    int _hp; //hit points
    std::string _align; //behaviour inclination
};