#include <iostream>
int main(){
    int a = 3.14;
    double b = 10;
    bool c = 42;
    int d = true;

    std::cout << "int a = 3.14 → " << a << std::endl;
    std::cout << "double b = 10 → " << b << std::endl;
    std::cout << "bool c = 42 → " << c << std::endl;
    std::cout << "int d = true → " << d << std::endl;

    std::cout << "\n——— ② C 风格强转（不推荐） ———" << std::endl;
    double pi = 3.14159;
    int e = (int)pi;      
    std::cout << "(int)pi = " << e << std::endl;

    std::cout << "\n——— ③ C++ 风格强转（推荐） ———" << std::endl;
    pi = 3.14159;
    int f = static_cast<int>(pi);
    std::cout<< "static_cast<int>(pi) = "<< f <<std::endl;

    // int* p = static_cast<int*>(pi);

    std::cout<<" \n--- enum class ---"<<std::endl;
    enum class Color {
        Red,
        Green,
        Blue,
    };

    enum class Trafficlight {
        Red,
        Yellow,
        Green,
    };

    Color color = Color::Red;
    Trafficlight light = Trafficlight::Green;

    // int x = color;
    int x = static_cast<int>(color);
    std::cout<< "static_cast<int>(Color::Red) = "<<x<<std::endl;

    return 0;
}