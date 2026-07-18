#include <iostream>
int* creat_array(int size){
    int* arr = new int[size];

    for(int i = 0;i<size;i++){
        arr[i] = i * 2;
    }

    std::cout<<"在堆上分配 "<<size<<"个 int,地址: "<<arr<<std::endl;

    return arr;
}

int main(){
    int* my_array = creat_array(5);
    for(int i = 0;i<5;i++){
        std::cout<<my_array[i]<<std::endl;
    }
    std::cout<<std::endl;
    delete[] my_array;
    return 0;
}