#include <iostream>

namespace Math {
    const double PI = 3.14159;
}
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius_;
public:
    Circle(double r) : radius_(r) {}
    double area() const override {
        return Math::PI * radius_ * radius_;
    }
};

class Base {
public:
    virtual void f() {
        std::cout << "Base::f()" << std::endl;
    }
};
class Derived : public Base {
public:
    void f() override {
        std::cout << "Derived::f()" << std::endl;
    }
};

// void print_area_bad(Shape s) {
//     std::cout << "Area: " << s.area() << std::endl;
// }

void print_area_good(const Shape& s) {
    std::cout << "Area: " << s.area() << std::endl;
}

void call_f(Base b) {
    b.f();
}
void call_f_ref(Base& b) {
    b.f();
}

int main() {
    Derived d;
    call_f_ref(d);
    call_f(d);
    Circle c(1.0);
    print_area_good(c);
}