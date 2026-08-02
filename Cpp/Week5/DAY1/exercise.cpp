#include <iostream>
#include <string>

namespace Math {
    const double PI = 3.14159;
}
class Shape {
protected:
    std::string name_;
public:
    Shape(const std::string& name) : name_(name) {}
    virtual double area() const = 0;
    virtual void describe() const {
        std::cout << "Shape: " << name_ << ", Area: " << area() << std::endl;
    }
    virtual ~Shape() {}
    const std::string& name() const {
        return name_;
    }
};

class Circle : public Shape {
    double radius_;
public:
    Circle(const std::string& name, double r) : Shape(name), radius_(r) {}
    double area() const override {
        return Math::PI * radius_ * radius_;
    }    
};

class Rect : public Shape {
    double w_, h_;
public:
    Rect(const std::string& name, double w, double h) : Shape(name), w_(w), h_(h) {}
    double area() const override {
        return w_ * h_;
    }
};

class Triangle : public Shape {
    double base_, height_;
public:
    Triangle(const std::string& name, double b, double h) : Shape(name), base_(b), height_(h) {}
    double area() const override {
        return 0.5 * base_ * height_;
    }
};


Shape* max_area(Shape** shapes, size_t n) {
    if (n == 0) return nullptr;
    double max_area = -1;
    Shape* max_shape = nullptr;
    for(size_t i = 0; i< n;i++){
        if(max_area < shapes[i]->area()){
            max_area = shapes[i]->area();
            max_shape = shapes[i];
        }
    }
    return max_shape;
}
int main() {
    Shape* shapes[3];
    shapes[0] = new Circle("小圆", 1.0);    // 面积 3.14
    shapes[1] = new Rect("大方", 2, 3);      // 面积 6
    shapes[2] = new Triangle("三角", 4, 5);  // 面积 10

    for (int i = 0; i < 3; i++)
        shapes[i]->describe();   // 多态调用

    Shape* biggest = max_area(shapes, 3);
    std::cout << "最大: " << biggest->name() << "\n";

    for (int i = 0; i < 3; i++)
        delete shapes[i];
}