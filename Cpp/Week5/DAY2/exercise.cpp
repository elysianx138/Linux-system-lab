#include <iostream>
#include <string>
#include <vector>

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
double total_payroll(const std::vector<Employee*>& employees) {
    double total = 0;
    for(const auto& employee : employees) {
        total += employee->calculate_salary();
    }
    return total;
}

int main() {
    std::vector<Employee*> company;
    company.push_back(new Developer("张三", 10000, 2000));
    company.push_back(new Manager("李四", 15000));
    company.push_back(new Intern("王五", 8000));
    for(const auto& employee : company) {
        employee->display_info();
    }
    std::cout << "Total Payroll: " << total_payroll(company) << std::endl;
    for(const auto& employee : company) {
        delete employee;
    }

    return 0;
}