#include <typeinfo>
#include <string>
#include <iostream>

class Employee {
protected:
    std::string name_;
    double base_salary_;
public:
    Employee(const std::string& name, double base_salary) : name_(name), base_salary_(base_salary) {}
    virtual double calculate_salary() const = 0;
    const virtual void display_info() const {
        std::cout << "Employee: " << name_ << ", Base Salary: " << this->calculate_salary() << std::endl;
    }
    virtual ~Employee() {}
    const std::string& name() const {
        return name_;
    }
};
class Developer : public Employee {
    double project_bonus_;
public:
    Developer(const std::string& name, double base_salary, double project_bonus) : Employee(name, base_salary), project_bonus_(project_bonus) {}
    double calculate_salary() const override {
        return base_salary_ + project_bonus_; 
    }
};

class Manager : public Employee {
public:
    Manager(const std::string& name, double base_salary) : Employee(name, base_salary) {}
    double calculate_salary() const override {
        return base_salary_ * 1.5;
    }
};

class Intern : public Employee {
public:
    Intern(const std::string& name, double base_salary) : Employee(name, base_salary) {}
    double calculate_salary() const override {
        return base_salary_ * 0.5;
    }
};
int main() {
    Employee* e1 = new Manager("张三", 15000);
    Employee* e2 = new Developer("李四", 10000, 2000);

    std::cout<< typeid(*e1).name() << std::endl;
    std::cout<< typeid(*e2).name() << std::endl;

    if (typeid(*e1) == typeid(Manager)) {
        std::cout << "e1是Manager"<<std::endl;
    } else {
        std::cout << "e1不是Manager"<<std::endl;
    }
    return 0;
}