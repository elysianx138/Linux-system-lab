#include <iostream>
int main(){
    int* p;
    std::cout<<"p存的地址未: "<<p<<std::endl;
    *p = 42;
    std::cout<<"*p = "<<*p<<std::endl;
    
    return 0;
}