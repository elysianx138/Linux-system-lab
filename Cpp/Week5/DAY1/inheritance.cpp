#include <iostream>
#include <string>

class Animal {
protected:
    std::string name_;
public:
    Animal(const std::string& name) : name_(name) {}

    void eat() const {
        std::cout << name_ << " is eating." << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal(name) {}

    void bark() const {
        std::cout << name_ << " is barking." << std::endl;
    }
};

int main() {
    Dog dog("旺财");
    dog.eat();  
    dog.bark(); 
    return 0;
}