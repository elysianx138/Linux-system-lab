#include <iostream>
#include <string>

template <typename T>
void my_swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename t>
class Box {
    t value_;
public:
    Box(const t& v) : value_(v) {};
    t get() const {return value_;}
    void set(const t& v) {
        value_ = v;
    }
};

int main() {
    int x = 1, y = 2;
    my_swap(x, y);
    std::cout << x << " " << y << "\n";

    double d1 = 1.5, d2 = 2.5;
    my_swap(d1, d2);
    
    std::string s1 = "a", s2 = "b";
    my_swap(s1, s2); 

    Box<int> int_box(42);
    Box<std::string> str_box("hi");

    std::cout<< int_box.get()<<std::endl;
    std::cout<< str_box.get()<<std::endl;
} 