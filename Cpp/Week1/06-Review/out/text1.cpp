#include <iostream>

void double_it(int& x){
    x *= 2;
}

int main(){
    int n = 5;
    double_it(n);
    std::cout<<n<<std::endl;
    return 0;
}