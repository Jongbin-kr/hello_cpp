#include <iostream>

class Pokemon {
protected:
    std::string name;
    int hp;
    enum Type {ELECTRIC, FIRE} type;
    
public:
    Pokemon(std::string name, int hp, Type type)
    : name(name), hp(hp), type(type){
    }
    
    int getHP(){
        return hp;
    }
    
    std::string getName(){
        return name;
    }
    
    Type getType(){
        return type;
    }
    
    void decreaseHP(int amount){
        hp -= amount;
    }
    
    void attack(Pokemon& opponent){
        std::cout << "[Base] " << name << " attacks " << opponent.getName() << std::endl;
    }

};


class Pikachu: public Pokemon{
private:
    int electricLevel;

public: 
    Pikachu()
    : Pokemon("Pikachu", 100, ELECTRIC), electricLevel(10){
    }
    
    ~Pikachu(){
    }
    
    
    // skills
    void attack(Pokemon& opponent){
        Pokemon::attack(opponent);
        if (opponent.getType() == FIRE){ // NOTE: Type의 값은 문자열이 아니라, 그냥 리터럴로 처리하네.
            opponent.decreaseHP(electricLevel - 2);
        }
        else{
            opponent.decreaseHP(electricLevel);
        }
    }
    
    void cry() {
        std::cout << "Pika pika!" << std::endl;
    }
};


class Charmander: public Pokemon{
private:
    int flameLevel;

public:
    Charmander()
    : Pokemon("Charmander", 200, FIRE), flameLevel(5){
    }
    
    void attack(Pokemon& opponent){
        Pokemon::attack(opponent);
        if (opponent.getType() == ELECTRIC){
            opponent.decreaseHP(flameLevel + 2);
            
        }else{
            opponent.decreaseHP(flameLevel);
        }
    }
};


int main(){
    
    Pikachu pikachu;
    Charmander charmander;
    
    std::cout << "피카츄 피통: " << pikachu.getHP() << std::endl;
    std::cout << "파이리 피통: " << charmander.getHP() << std::endl;
    std::cout << std::endl;
    
    pikachu.attack(charmander);
    std::cout << "피카츄 피통: " << pikachu.getHP() << std::endl;
    std::cout << "파이리 피통: " << charmander.getHP() << std::endl;
    std::cout << std::endl;
    
    charmander.attack(pikachu);
    std::cout << "피카츄 피통: " << pikachu.getHP() << std::endl;
    std::cout << "파이리 피통: " << charmander.getHP() << std::endl;
    std::cout << std::endl;
    
    
    return 0;
}