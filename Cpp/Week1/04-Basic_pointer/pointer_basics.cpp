#include <iostream>
int main(){
    int a = 42;
    int* p = &a;

    std::cout<<"a的值: "<<a<<std::endl;
    std::cout<<"a的地址: "<<&a<<std::endl;
    std::cout<<"p的值(地址): "<<p<<std::endl;
    std::cout<<"p指向的☞: "<<*p<<std::endl;

    *p = 100;
    std::cout<<"修改后a的值: "<<a<<std::endl;

    return 0;
}