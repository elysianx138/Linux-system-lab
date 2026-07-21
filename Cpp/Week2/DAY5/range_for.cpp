#include <iostream>

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    std::cout<<"读模式(拷贝): "<<std::endl;
    for(int x : arr){
        std::cout<< x << " ";
    }

    std::cout<<"\n 写模式(引用): ";
    for(int& x : arr){
        x *= 2;
        std::cout<< x << " ";
    }

    std::cout<<"\n 只读模式(const): ";
    for(const int& x : arr){
        std::cout<< x << " ";
    }

    std::cout<<"\n auto版本: ";
    for(const auto& x : arr){
        std::cout<< x << " ";
    }

    std::cout<<std::endl;
    return 0;
}