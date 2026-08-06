#include <iostream>
#include <stdexcept>

double divide(double a, double b){
    if (b == 0)
        throw std::runtime_error("除数不能为0");
    return a/b;
}

int main() {
    try {
        std::cout<<divide(10, 2)<<std::endl;
        std::cout<<divide(10, 0)<<std::endl;
    } catch (const std::exception& e){
        std::cout<<"错误: "<<e.what()<<std::endl;
    }
    std::cout<<"结束"<<std::endl;
}