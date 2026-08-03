#include <vector>
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

class Rect : public Shape {
    double w_, h_;
public:
    Rect(double w, double h) : w_(w), h_(h) {}
    double area() const override {
        return w_ * h_;
    }
};
int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(1.0));
    shapes.push_back(new Rect(2, 3));
    shapes.push_back(new Circle(2.0));

    double total = 0;
    for (auto& shape : shapes) {
        total += shape->area();
    }
    std::cout << "Total area: " << total << std::endl;
    for (auto& shape : shapes) {
        delete shape;
    }
    return 0;
}
