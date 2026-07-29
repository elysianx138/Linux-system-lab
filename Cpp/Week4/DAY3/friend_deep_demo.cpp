#include <iostream>
class Engine;

class Mechanic {
public:
    void tune(Engine& e);
};

class Engine {
    int horsepower_;
public:
    Engine(int hp) : horsepower_(hp) {}

    friend void Mechanic::tune(Engine& e);
};

void Mechanic::tune(Engine& e) {
    e.horsepower_ += 50;
}