#include <iostream>
int main(){
    int a = 42;

    int& ref = a;

    int* ptr = &a;

    std::cout<<"a 的值为: "<<a<<std::endl;
    std::cout<<"ref 的值为: "<<ref<<std::endl;
    std::cout<<"*ptr的值为: "<<*ptr<<std::endl;

    ref = 100;
    std::cout<<"修改后的a值为: "<<a<<std::endl;
    std::cout<<"修改后的ref的值: "<<ref<<std::endl;

    std::cout<<"地址对比"<<std::endl;
    std::cout<<"&a"<<&a<<std::endl;
    std::cout<<"&ref"<<&ref<<std::endl;
    std::cout<<"&ptr"<<&ptr<<std::endl;
}