#include <iostream>
void swap_ptr(int* a, int* b){
    int _temp = *a;
    *a = *b;
    *b = _temp;
}

void swap_ref(int& a, int& b){
    int _temp = a;
    a = b;
    b = _temp; 
}
int main(){
    int a = 10;
    int b = 20;
    std::cout<<"a : b"<<a<<":"<<b<<std::endl;
    swap_ptr(&a, &b);
    std::cout<<"a : b"<<a<<":"<<b<<std::endl;
    swap_ref(a, b);
    std::cout<<"a : b"<<a<<":"<<b<<std::endl;
}