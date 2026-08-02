#include <iostream>

namespace Math {
    const double PI = 3.14159;
}

class Shape {
public:
    virtual double area() const {
        return 0;
    }
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

class Rect : public Shape {
    double w_, h_;
public:
    Rect(double w, double h) : w_(w), h_(h) {}
    double area() const override {
        return w_ * h_;
    }
};

int main(){
    Shape* shapes[2];
    shapes[0] = new Circle(1.0);
    shapes[1] = new Rect(2, 3);

    for (int i = 0; i < 2; i++) {
        std::cout << "Area: " << shapes[i]->area() << std::endl;
        delete shapes[i];
    }
    return 0;
}
