#include <iostream>
int main(){
    int a = 10;
    int b = 20;

    int& ref = a;
    std::cout<<"ref绑定到a: "<<ref<<std::endl;

    ref = b;
    std::cout<<"ref的值为: "<<ref<<std::endl;
    std::cout<<"a的值为: "<<a<<std::endl;
    std::cout<<"b的值为: "<<b<<std::endl;

    a = 999;
    std::cout<<"修改a后ref的值: "<<ref<<std::endl;
    return 0;
}