#include <iostream>

int max(int a, int b){
    return (a > b)?a : b;
}

double max(double a, double b){
    return (a > b)?a : b;
}

int max(int a, int b,int c){
    return max(max(a, b), c);
}

void greet(const std::string& name, const std::string& prefix = "你好"){
    std::cout<< prefix <<", "<<name<<"!"<<std::endl;
}

inline int square(int x){
    return x * x;
}

namespace Math{
    const double PI = 3.14159;
    double area_of_circle(double r){
        return PI*r*r;
    }
}

namespace Project{
    int value = 100;
}

namespace Project{
    int value2 = 42;
}

int main(){
    std::cout<<"============函数重载============="<<std::endl;
    std::cout<<"max(3, 7) = "<<max(3, 7)<<std::endl;
    std::cout<<"max(3.5, 2.1) = "<<max(3.5, 2.1)<<std::endl;
    std::cout<<"max(1, 5, 3) = "<<max(1, 5, 3)<<std::endl;

    std::cout<<"\n =============默认参数==================="<<std::endl;
    greet("张三");
    greet("张三", "晚上好");

    std::cout<<"\n ===================inline================"<<std::endl;
    std::cout<<"square(5) = "<<square(5)<<std::endl;

    std::cout<<"\n ==========命名空间==============="<<std::endl;
    std::cout<<"Math:PI = "<<Math::PI<<std::endl;
    std::cout<<"圆面积(5) = "<<Math::area_of_circle(5)<<std::endl;
    std::cout<<"Project::value = "<<Project::value<<std::endl;
    std::cout<<"Project::value2 = "<<Project::value2<<std::endl;

    return 0;
}