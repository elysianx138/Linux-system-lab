#include <iostream>
void chang_int(int x){
    x = 100;
    std::cout<<"函数内部 x 的值: "<<x<<std::endl;
}

int main(){
    int a = 42;
    std::cout<<"调用前 a 的值: "<<a<<std::endl;

    chang_int(a);

    std::cout<<"调用后 a 的值: "<<a<<std::endl;

    return 0;
}