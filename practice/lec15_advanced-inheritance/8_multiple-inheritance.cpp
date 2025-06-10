#include <iostream>

class BasePokemon{
protected:
    std::string name;
    int hp;

public:
BasePokemon(std::string name, int hp)
: name(name), hp(hp){}

virtual ~BasePokemon(){}

int getHP() const{ return hp; }

std::string getName() const {return name;}

};

enum Type {ELECTRIC, FIRE};



class ElectricPokemon{
public:
    Type type;
    int electricLevel;
    
    ElectricPokemon(int level)
    : electricLevel(level), type(ELECTRIC){}
    
    Type getTye(){return type;}
};


class FirePokemon{
public:
    Type type;
    int flameLevel;
    
    FirePokemon(int level)
    : flameLevel(level), type(FIRE){}
    
    Type getType(){ return type; }
};



// Derived classes
class Pikachu: public BasePokemon, public ElectricPokemon{
public:
    std::string cry;
    
    Pikachu()
    : BasePokemon("Pikachu", 100), ElectricPokemon(10), cry("Pika pika!"){}    
};

class Charmander: public BasePokemon, public FirePokemon{
public:
    int height;
    
    Charmander(): BasePokemon("charmander", 200), FirePokemon(5), height(15){}
};



int main(){
    
    Pikachu pikachu;
    std::cout << pikachu.getHP() << std::endl;
    std::cout << pikachu.electricLevel << std::endl;
    std::cout << pikachu.cry << std::endl;
    
    
    Charmander charmander;
    std::cout << charmander.getHP() << std::endl;
    std::cout << charmander.flameLevel << std::endl;
    std::cout << charmander.height << std::endl;
    
    return 0;
}