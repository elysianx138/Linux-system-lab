#include <iostream>
void test(int x){
    std::cout<<"函数内部 x 的地址: "<<&x<<std::endl;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x = 10;
    int y = 20;
    std::cout<<"调用前 x 的值: "<<x<<std::endl;
    std::cout<<"调用前 y 的值: "<<y<<std::endl;
    std::cout<<"函数外部 x 的地址: "<<&x<<std::endl;
    test(x);

    swap(&x, &y);

    std::cout<<"调用后 x 的值: "<<x<<std::endl;
    std::cout<<"调用后 y 的值: "<<y<<std::endl;
    return 0;
}