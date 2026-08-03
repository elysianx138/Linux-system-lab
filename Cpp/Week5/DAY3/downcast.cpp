#include <iostream>
#include <string>
class Employee {
protected:
    std::string name_;
    int base_;
public:
    Employee(std::string name, int base) : name_(name), base_(base) {}
    virtual double calculate_salary() const = 0;
    virtual ~Employee() {}
};

class Manager : public Employee {
    int team_size;
public:
    Manager(int size, std::string name, int base) : team_size(size), Employee(name, base) {}
    double calculate_salary() const override {
        return base_ + team_size * 1000;
    }
    void hold_meeting() const {
        std::cout << "Holding a meeting with the team of size " << team_size << std::endl;
    }
};
int main() {
    Employee* e = new Manager(5, "Alice", 50000);
    Manager* m = static_cast<Manager*>(e);
    m->hold_meeting();
    
    // Employee* e2 = new Developer(5, "Bob", 40000);
    // Manager* m2 = dynamic_cast<Manager*>(e2);
    // m2->hold_meeting();

    Employee* d = new Manager(3, "Charlie", 60000);
    Manager* m2 = dynamic_cast<Manager*>(d);
    if(m2 != nullptr) {
        m2->hold_meeting();
    } else {
        std::cout << "Downcasting failed." << std::endl;
    }
    delete e;
    delete m;
    delete m2;
    delete d;
    return 0;
}