#include <iostream>

int* create_array(int size){
    int* arr = new int[size];
    return arr;
}

void fill_and_print_array(int* array, int size){
    for(int i = 0;i<size;i++){
        *(array + i) = i+1;
        std::cout<<"array["<<i<<"] = "<<*(array + i)<<std::endl;
    }
}

void delete_array(int* array){
    delete[] array;
}

int main(){
    int* array = create_array(5);
    fill_and_print_array(array, 5);
    delete_array(array);
}