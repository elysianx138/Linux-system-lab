#include <iostream>

int global_var = 0;

int main(){
    int local_var = 0;
    int stack_array[10];

    int* heap_var = new int(0);
    int* heap_array = new int[10];

    std::cout<<"全部变量(数据段)"<< &global_var << std::endl;
    std::cout<<"局部变量(栈)"<< &local_var << std::endl;
    std::cout<<"栈数组(栈)"<< &stack_array << std::endl;

    std::cout<<"堆变量(堆)"<< heap_var << std::endl;
    std::cout<<"堆数组(堆)"<< heap_array << std::endl;

    delete heap_var;
    delete[] heap_array;
    return 0;
}
