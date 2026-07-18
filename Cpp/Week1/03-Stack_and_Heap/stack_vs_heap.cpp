#include <iostream>
void stack_vs_heap(){
    int stack_arry[1000];
    for(int i =0;i<1000;i++){
        stack_arry[i] = i;
    }


    int* heap_arry = new int[1000];
    for (int i = 0;i<1000;i++){
        heap_arry[i] = i;
    }
    delete[] heap_arry;

    std::cout<<"栈数组地址: "<<stack_arry<<std::endl;
    std::cout<<"堆数组地址: "<<heap_arry<<std::endl;
    
}

int main(){
    stack_vs_heap();
    return 0;
}