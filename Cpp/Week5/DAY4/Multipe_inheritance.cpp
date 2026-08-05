#include <iostream>
class Flyable {
public:
    virtual void fly() {
        std::cout << "飞行中" <<std::endl;
    }
};
class Swimmable {
public:
    virtual void swim() {
        std::cout << "游泳中" <<std::endl;
    }
};

class Duck : public Flyable, public Swimmable {
public:
    void quack() {
        std::cout<< "嘎嘎" <<std::endl;
    }
};

int main() {
    Duck d;
    d.fly();
    d.swim();
    d.quack();
    return 0;
}