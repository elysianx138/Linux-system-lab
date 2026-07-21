#include <iostream>

void print_by_value(std::string s){
    std::cout<<s<<std::endl;
}

void print_by_const_ref(const std::string& s){
    // s = "Hello, World";
    std::cout<<s<<std::endl;
}

void print_by_ref(std::string& s){
    s = "Hell, World";
    std::cout<<s<<std::endl;
}

int main(){
    std::string msg = "Hello, const reference!";

    print_by_value(msg);
    print_by_const_ref(msg);
    print_by_ref(msg);

    return 0;
}