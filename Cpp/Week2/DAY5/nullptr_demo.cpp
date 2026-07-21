#include <iostream>
void func(int){
    std::cout<<"int 版本"<<std::endl;
}

void func(int*){
    std::cout<<"指针版本"<<std::endl;
}

int main(){
    // func(NULL);
    func(nullptr);

    return 0;
}