#include <iostream>


class Pokemon {
    public:
        enum Type {ELECTRIC, FIRE};
        
    protected:
        std::string name;
        int hp;
        Type type;
        
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
        
        void printMemory(){
            std::cout << "Pokemon: " << std::endl;
            std::cout << "this: " << this << std::endl;
            std::cout << "hp: " << &hp << std::endl;
            std::cout << "type: " << &type << std::endl;
            std::cout << "size: " << sizeof(*this) << " bytes" << std::endl;
            std::cout << "============================" << std::endl;
            
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
        
        void printMemory(){
            std::cout << "Pikachu: " << std::endl;
            std::cout << "this: " << this << std::endl;
            std::cout << "hp: " << &hp << std::endl;
            std::cout << "type: " << &type << std::endl;
            std::cout << "Electric level: " << &electricLevel << std::endl;
            std::cout << "size: " << sizeof(*this) << " bytes" << std::endl;
            std::cout << "============================" << std::endl;
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

        void printMemory(){
            std::cout << "Charmander: " << std::endl;
            std::cout << "this: " << this << std::endl;  // 이름 문자열 24바이트 (표준 구현)
            std::cout << "hp: " << &hp << std::endl;
            std::cout << "type: " << &type << std::endl;
            std::cout << "flame level: " << &flameLevel << std::endl;
            std::cout << "size: " << sizeof(*this) << " bytes" << std::endl;
            std::cout << "============================" << std::endl;
            
        }
    };

    
int main(){
    
    Pokemon pokemon("GenericPokemon", 50, Pokemon::ELECTRIC);
    Pikachu pikachu;
    Charmander charmander;
    
    pokemon.printMemory();
    pikachu.printMemory();
    charmander.printMemory();
    
    
    return 0;
}