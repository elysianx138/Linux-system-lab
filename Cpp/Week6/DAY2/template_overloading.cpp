#include <iostream>
template <typename T>
T max_val(const T& a, const T& b) {
    std::cout<<"执行T"<<std::endl;
    return (a > b) ? a : b;
}

int max_val(int a, int b) {
    std::cout<<"执行int"<<std::endl;
    return (a > b) ? a : b;
}
template <typename T>
T devided(const T& a, const T& b){
    if(b==0){
        return;
    } else {
        return a / b;
    }
}

int main(){
    max_val(1, 2);
    max_val(1.5, 2.5);
    max_val(3, 4);
}
