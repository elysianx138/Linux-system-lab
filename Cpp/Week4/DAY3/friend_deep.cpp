#include <iostream>
class Engine{
    int horsepower_;
    friend class Mechanic;
public:
    Engine(int hp) : horsepower_(hp) {}
    const int get_horsepower() const {
        return horsepower_;
    }
};

class Mechanic{
public:
    void tune(Engine& e){
        e.horsepower_ += 50;
    }
};


int main(){
    Engine e(200);
    Mechanic m;
    m.tune(e);
    std::cout<<e.get_horsepower()<<std::endl;
}