#include <string>

class Monster{
public:
    Monster();
    ~Monster();
    void setName(std::string);
    void setCr(float);
    void setType(std::string);
    void setSize(std::string);
    void setAc(short);
    void setHp(short);
    void setAllign(std::string);

    std::string getName();
    float getCr();
    std::string getType();
    std::string getSize();
    short getAc();
    short getHp();
    std::string getAllign();

    bool operator >(Monster &RIGHT);
    bool operator <(Monster &RIGHT);
    friend std::ostream& operator <<(std::ostream &COUT, Monster &MONSTER);
private:
    std::string _name;
    float _cr; //challenge rating
    std::string _type;
    std::string _size;
    short _ac; //armor class
    short _hp; //hit points
    std::string _align; //behaviour inclination
};