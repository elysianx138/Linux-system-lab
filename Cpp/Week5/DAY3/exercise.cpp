#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

class Animal {
protected:
    std::string name_;
public:
    Animal(const std::string& name) : name_(name) {}
    virtual void make_sound() const = 0;
    virtual ~Animal() {}
    const std::string& name() const {
        return name_;
    }
};
class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal(name) {}
    void make_sound() const override {
        std::cout << " Woof! Woof!" << std::endl;
    }
    void fetch() const {
        std::cout << name_ << " is fetching the ball!" << std::endl;
    }
};
class Cat : public Animal {
public:
    Cat(const std::string& name) : Animal(name) {}
    void make_sound() const override {
        std::cout<< "Meow! Meow!" << std::endl;
    }
    void purr() const {
        std::cout << name_ << " is purring!" << std::endl;
    }
};
class Bird : public Animal {
public:
    Bird(const std::string& name) : Animal(name) {}
    void make_sound() const override {
        std::cout << "Chirp! Chirp!" << std::endl;
    }
    void fly() const {
        std::cout << name_ << " is flying!" << std::endl;
    }
};

void interact(Animal& animal) {
    if(Dog* dog = dynamic_cast<Dog*>(&animal)){
        dog->fetch();
    }else if(Cat* cat = dynamic_cast<Cat*>(&animal)){
        cat->purr();
    }else if(Bird* bird = dynamic_cast<Bird*>(&animal)){
        bird->fly();
    }
}

int main() {
    std::vector<Animal*> animals;
    animals.push_back(new Dog("旺财"));
    animals.push_back(new Cat("咪咪"));
    animals.push_back(new Bird("啾啾"));
    
    for(const auto& animal : animals) {
        animal->make_sound();
        interact(*animal);
    }
    
    for(const auto& animal : animals){
        std::cout<< typeid(*animal).name() <<std::endl;
        delete animal;
    }
    return 0;
}