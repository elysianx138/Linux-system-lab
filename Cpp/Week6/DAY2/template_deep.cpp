#include <iostream>
#include <string>
template <typename T1, typename T2>
class Pair {
    T1 first_;
    T2 second_;
public:
    Pair(const T1& first, const T2& second) : first_(first), second_(second) {}
    T1 first() const {
        return first_;
    }
    T2 second() const {
        return second_;
    }
};

int main() {
    Pair<int, std::string> p1(1, "one");
    Pair<double, double> p2(3.14, 2.72);

    std::cout << p1.first() << " " << p1.second() << "\n";  
    std::cout << p2.first() << " " << p2.second() << "\n"; 
}