#include <iostream>

void blow_stack(){
    int big_array[10000000];
    std::cout<< "分配了 40 MB 在栈上"<<std::endl;
}

int main(){
    blow_stack();
    return 0;
}