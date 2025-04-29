#include <iostream>

class Pokemon {
protected:
    std::string name;
    int hp;
    enum Type {ELECTRIC, FIRE} type;
    
public:
    Pokemon(std::string name, int hp, Type type)
    : name(name), hp(hp), type(type){
        std::cout << "[Base] constructed at " << this << std::endl;
    }
    
    ~Pokemon(){
        std::cout << "[Pokemon] destructed at " << this << std::endl;
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

    void showMemory(){
        std::cout << "-------------------------" << std::endl;
        std::cout << "Pokemon: " << std::endl;
        std::cout << "This: " << this << " " << sizeof(this) << std::endl;
        std::cout << "sizeof(this): " << sizeof(*this) << std::endl;
        std::cout << "name: " << name << " " << &name << std::endl;
        std::cout << "HP: " << hp << " " << &hp << std::endl;
        std::cout << "type: " << type << " " << &type << std::endl;
        
    }

};


class Pikachu: public Pokemon{
private:
    int electricLevel;

public: 
    Pikachu()
    : Pokemon("Pikachu", 100, ELECTRIC), electricLevel(10){
        std::cout << "[Pikachu] constructed at " << this << std::endl;
        
    }
    
    ~Pikachu(){
        std::cout << "[Pikachu] destructed at " << this << std::endl;
    }
    
    
    // skills
    void attack(Pokemon& opponent) {
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
    
    void showMemory() {
        std::cout << "-------------------------" << std::endl;
        std::cout << "Pikachu: " << std::endl;
        std::cout << "This: " << this << " " << sizeof(this) << std::endl;
        std::cout << "sizeof(this): " << sizeof(*this) << std::endl;
        std::cout << "name: " << name << " " << &name << " " << sizeof(name) << std::endl;
        std::cout << "HP: " << hp << " " << &hp << " " << sizeof(hp) << std::endl;
        std::cout << "type: " << type << " " << &type << " " << sizeof(type) << std::endl;
        std::cout << "electric: " << electricLevel << " " << &electricLevel << " " << sizeof(electricLevel) << std::endl;
        
        
    }
};


class Charmander: public Pokemon{
private:
    int flameLevel;

public:
    Charmander()
    : Pokemon("Charmander", 200, FIRE), flameLevel(5){
        std::cout << "[Charmander] constructed at " << this << std::endl;
        
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
    
    std::cout << "======== Memory substitution ======" << std::endl;
    Pokemon* pokemon1 = new Pikachu();
    Pokemon* pokemon2 = new Charmander();
    
    std::cout << pokemon1->getName() << " has " << pokemon1->getHP() << " HP left." << std::endl;
    std::cout << pokemon2->getName() << " has " << pokemon2->getHP() << " HP left." << std::endl;
    
    // ERROR: Base class에 있는 멤버 펑션만 사용할 수 있다!
    // pokemon1->cry();
    
    
    std::cout << "\n\n======== overrides ======" << std::endl;
    
    pokemon1->attack(*pokemon2);  // virtual function을 쓰면, override가 가능하다!
    
    
    std::cout << "\n\n======== Memory layout ======" << std::endl;
    
    pokemon1->showMemory();
    
    Pikachu pika;
    pika.showMemory();
    /* 
    // NOTE:
    // 신기하게 virtual-override설정을 하면, sizeof(*this)가 48.
    vptr때문에 8바이트가 추가된다!
    
    */
    
    
    return 0;
}