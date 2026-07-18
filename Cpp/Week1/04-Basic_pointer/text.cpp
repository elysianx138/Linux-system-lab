#include <iostream>
int* create_array(int size){
    int* array = new int[size];
    return array;
}

void print_array(int size,int* array){
    for(int i = 0;i<size;i++){
        *(array + i) = i;
        std::cout<<"array["<<i<<"]: "<<*(array+i)<<std::endl;
    }
}

void delete_array(int* array){
    delete[] array;
}
int main(){
    int* array = create_array(4);
    print_array(4,array);
    delete_array(array);
}