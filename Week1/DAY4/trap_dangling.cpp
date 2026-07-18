#include <iostream>
int main(){
    int* p = new int(42);
    std::cout<<"delete 前*p = "<<*p<<std::endl;
    delete p;

    std::cout<<"delete 后p:"<< p <<std::endl;
    std::cout<<"delete 后*p = "<<*p<<std::endl;

    p = nullptr;
    return 0;
}