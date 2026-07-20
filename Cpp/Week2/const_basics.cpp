#include <iostream>
int main(){
    const int a = 42;
    // a = 100;
    
    std::cout<<"const int a = "<<a<<std::endl;

    int x = 10;
    int y = 20;

    int* const p1 = &x;
    *p1 = 100;
    // p1 = y;

    const int* p2 = &x;
    p2 = &y;
    // *p2 = 100

    const int* const p3 = &x;
    // *p3 = 100
    // p3 = &y

    return 0;
}