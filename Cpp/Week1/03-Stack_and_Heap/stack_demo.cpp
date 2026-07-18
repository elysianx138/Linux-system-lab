#include <iostream>
void func2(){
    int c = 30;
    std::cout<<"func2: c = "<<c<<std::endl;
}

void func1(){
    int b = 20;
    std::cout<<"func1: b = "<<b<<std::endl;
    func2();
}

int main(){
    int a = 10;
    std::cout<<"main: a = "<<a<<std::endl;
    func1();
    return 0;
}