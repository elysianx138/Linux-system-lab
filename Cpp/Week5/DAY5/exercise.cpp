#include <iostream>
#include <string>
#include <vector>

class Animal {
protected:
    std::string name_;
public:
    Animal(const std::string& name) : name_(name) {};
    virtual void speak() const = 0;
    virtual void move() const = 0;
    virtual ~Animal() {};
    const std::string& name() const {
        return name_;
    }
};

class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal(name) {};
    void speak() const override {
        std::cout<< "汪汪" <<std::endl;
    }
    void move() const override {
        std::cout<< "跑" <<std::endl;
    }
    void fetch() const {
        std::cout<<name_<<"正在捡球"<<std::endl;
    }

};

class Cat : public Animal {
public:
    Cat(const std::string& name) : Animal(name) {};
    void speak() const override {
        std::cout<< "喵喵" <<std::endl;
    }
    void move() const override {
        std::cout<< "跳" <<std::endl;
    } 
    void purr() const {
        std::cout<<name_<<"正在呼噜"<<std::endl;
    }
};

class Bird : public Animal {
public:
    Bird(const std::string& name) : Animal(name) {};
    void speak() const override {
        std::cout<< "啾啾" <<std::endl;
    }
    void move() const override {
        std::cout<< "飞" <<std::endl;
    }
    void fly() const {
        std::cout<<name_<<"正在飞"<<std::endl;
    }
};

void zoo_show(const std::vector<Animal*>& zoo) {
    for(const auto& animal : zoo) {
        if(animal == nullptr)
            return;
        animal->move();
        animal->speak();
        std::cout<<std::endl;
    }
}

void find_dog(const std::vector<Animal*>& animals){
    for(const auto& animal : animals){
        if(animal == nullptr)
            return;
        if(Dog* dog = dynamic_cast<Dog*>(animal)){
            dog->fetch();
        }
    }
}

class AnimalFactory {
public:
    static Animal* create(const std::string& type, const std::string& name) {
        if(type == "dog"){
            Animal* dog = new Dog(name);
            return dog;
        } else if(type == "cat") {
            Animal* cat = new Cat(name);
            return cat;
        } else if(type == "bird") {
            Animal* bird = new Bird(name);
            return bird;
        } else {
            return nullptr;
        }
    }
};

int main() {
    std::vector<Animal*> zoo;
    zoo.push_back(AnimalFactory::create("dog", "旺财"));
    zoo.push_back(AnimalFactory::create("cat", "咪咪"));
    zoo.push_back(AnimalFactory::create("bird", "小翠"));

    zoo_show(zoo);    // 多态：每个动物 speak + move
    find_dog(zoo);    // dynamic_cast 找出狗

    for (Animal* a : zoo) delete a;   // 虚析构
}
