#include <iostream>
void chang_it(int* x){
    std::cout<<"函数内部 x 的地址: "<<x<<std::endl;
    *x = 100;
    std::cout<<"函数内部 x 指向的值: "<<*x<<std::endl;
}

int main(){
    int a = 42;
    std::cout<<"调用前 a 的值: "<<a<<std::endl;
    std::cout<<"调用前 a 的地址: "<<&a<<std::endl;

    chang_it(&a);

    std::cout<<"调用后 a 的值: "<<a<<std::endl;

    return 0;
}