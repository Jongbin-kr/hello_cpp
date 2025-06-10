#include <iostream>

class BasePokemon{
protected:
    std::string name;
    int hp;
    enum Type {ELECTRIC, FIRE} type;

public:
    BasePokemon(std::string name, int hp, Type type)
    : name(name), hp(hp), type(type){}

    Type getType() const {return type;}
};


class ElectricPokemon: public BasePokemon{
public:
    int electricLevel;
    std::string cry;
    
    ElectricPokemon(std::string name, int hp, int electriclevel)
    : BasePokemon(name, hp, ELECTRIC), electricLevel(electriclevel){
    }
};

class FirePokemon: public BasePokemon{
public:
    int flameLevel;
    
    FirePokemon(std::string name, int hp, int flamelevel)
    : BasePokemon(name, hp, FIRE), flameLevel(flamelevel){}
};



int main(){
    
    
    return 0;
}

