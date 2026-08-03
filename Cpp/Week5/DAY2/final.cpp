namespace Math {
    constexpr double PI = 3.14159265358979323846;
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
    double area() const final override {
        return Math::PI * radius_ * radius_;
    }
};
// class SpecialCircle : public Circle {
// public:
//     SpecialCircle(double r) : Circle(r) {}
//     double area() const override {
//         return Circle::area() * 2; // Example modification
//     }
// };

// class SpecialCircle : public Circle {
// public:
//     double area() const override {
//         return Circle::area() * 2; // Example modification
//     }
// };