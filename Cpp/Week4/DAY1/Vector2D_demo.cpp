#include <iostream>

class Vector2D{
    double x_, y_;

public:
    Vector2D(double x = 0, double y = 0) : x_(x), y_(y){}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x_ + other.x_, y_ + other.y_);
    }

    Vector2D operator*(double scalar) const {
        return Vector2D(x_ * scalar, y_ * scalar);
    }

    friend Vector2D operator*(double scalar, const Vector2D& v) {
        return Vector2D(scalar * v.x_, scalar * v.y_);
    }

    bool operator==(const Vector2D& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }
    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v){
        os << "(" <<v.x_<<", "<<v.y_<<")";
        return os;
    }
};

int main(){
    Vector2D v1(1, 2), v2(3, 4);

    Vector2D sum = v1 + v2;
    Vector2D scaled = v1 * 2.5;
    Vector2D scaled2 = 2.0 *  v1;  

    std::cout<< sum << std::endl;
    std::cout<< scaled2 <<std::endl;
    std::cout<< (v1 == v2)<<std::endl;
    std::cout<< (v1 != v2)<<std::endl;
}