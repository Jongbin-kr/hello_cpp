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
        std::cout << "[pikachu] Thunderbolts!!!" << std::endl;
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
    
    Pokemon* pokemon1 = new Pikachu();
    Pokemon* pokemon2 = new Charmander();
    
    std::cout << pokemon1->getName() << " has " << pokemon1->getHP() << " HP left." << std::endl;
    std::cout << pokemon2->getName() << " has " << pokemon2->getHP() << " HP left." << std::endl;
    
    // ERROR: Base class에 있는 멤버 펑션만 사용할 수 있다!
    // pokemon1->cry();
    
    
    pokemon1->attack(*pokemon2);
    
    return 0;
}