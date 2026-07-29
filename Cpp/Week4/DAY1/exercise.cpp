#include <iostream>
#include <numeric>
class Fraction{
    int x_, y_;

public:
    Fraction(int x, int y) : x_(x), y_(y){
        if(y_ == 0) 
            std::cout<< "未定义" <<std::endl;
        else {
            int g = std::gcd(x, y);
            x_ = x / g;
            y_ = y / g;
        }
    }
    Fraction operator+(const Fraction& other){
        int denominator_ = y_ * other.y_;
        int numerator_ = x_ * other.y_ + other.x_ * y_;
        int gcd_ = std::gcd(denominator_, numerator_);
        return Fraction(numerator_ / gcd_, denominator_ / gcd_);
    }
    Fraction operator-(const Fraction& other){
        int denominator_ = y_ * other.y_;
        int numerator_ = x_ * other.y_ - other.x_ * y_;
        int gcd_ = std::gcd(denominator_, numerator_);
        return Fraction(numerator_ / gcd_, denominator_ / gcd_);
    }
    Fraction operator*(const Fraction& other){
        int gcd_ = std::gcd(x_ * other.x_, y_ * other.y_);
        return Fraction(x_ * other.x_ / gcd_, y_ * other.y_ / gcd_);
    }
    Fraction operator/(const Fraction& other){
        Fraction other_(other.y_, other.x_);
        return *this * other_;
    }

    bool operator>(const Fraction& other) const {
        return x_ * other.y_ > other.x_ * y_;
    }
    bool operator<(const Fraction& other) const {
        return x_ * other.y_ < other.x_ * y_;
    }
    bool operator==(const Fraction& other) const {
        return x_ * other.y_ == other.x_ * y_;
    }
    bool operator!=(const Fraction& other) const {
        return !(x_ * other.y_ == other.x_ * y_);
    }


    
    friend std::ostream& operator<<(std::ostream& os, const Fraction& v){
        double gcd_ = std::gcd(v.x_, v.y_);
        os << (v.x_ / gcd_) << "/" << (v.y_ / gcd_);
        return os;
    }

};

int main() {
    Fraction a(1, 2);   // 1/2
    Fraction b(2, 3);   // 2/3
    
    Fraction sum = a + b;      // 1/2 + 2/3 = 7/6
    Fraction diff = a - b;     // 1/2 - 2/3 = -1/6
    Fraction prod = a * b;     // 1/2 * 2/3 = 2/6 = 1/3
    Fraction quot = a / b;     // 1/2 ÷ 2/3 = 3/4
    
    std::cout << a << "\n";    // 输出 "1/2"
    std::cout << sum << "\n";  // 输出 "7/6"
    std::cout << prod << "\n"; // 输出 "1/3"（约分后）

    std::cout << (a > b) << "\n";  // 0（1/2 < 2/3）
    std::cout << (a < b) << "\n";  // 1
}