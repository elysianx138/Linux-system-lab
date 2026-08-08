#include <iostream>
#include <string>

template <typename T = int>
class Counter {
    T value_;
public:
    Counter(const T& v = T()) : value_(v) {}
    void add(const T& delta) {
        value_ += delta;
    }
    T get() const {
        return value_;
    }
};

int main() {
    Counter<> c1;
    Counter<double> c2(1.5);

    c1.add(5);
    std::cout<< c1.get() <<std::endl;
    std::cout<< c2.get() <<std::endl;
}