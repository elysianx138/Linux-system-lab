#include <iostream>
int main(){
    int* p = new int(42);

    std::cout<<"p里存的地址: "<<p<<std::endl;
    std::cout<<"p本身的地址: "<<&p<<std::endl;
    std::cout<<"P指向的数值: "<<*p<<std::endl;

    *p = 100;
    std::cout<<"修改后: "<<*p<<std::endl;

    delete p;
    p = nullptr;

    return 0;

}