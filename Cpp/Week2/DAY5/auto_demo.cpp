#include <iostream>
#include <vector>
#include <string>

int main(){
    auto a = 42;
    auto b = 3.14;
    auto c = "hello";
    auto d = std::string("World");

    std::cout << "a = " << a << " (type: int)" << std::endl;
    std::cout << "b = " << b << " (type: double)" << std::endl;
    std::cout << "c = " << c << " (type: const char*)" << std::endl;
    std::cout << "d = " << d << " (type: std::string)" << std::endl;

    int x = 42;
    const int& ref = x;

    auto v1 = ref;
    const auto& v2 = ref;

    v1 = 100;
    // v2 = 100;

    std::cout<<"\n x = "<<x<<", v1 = "<<v1<<std::endl;

    std::vector<std::string> names = {"张三", "李四", "王五"};

    std::vector<std::string>::iterator it = names.begin();
    auto it2 = names.begin();

    for(const auto& name : names){
        std::cout<< name <<" ";
    }
    std::cout<<std::endl;

    auto result = "hello";
    std::cout<<"\n 42 + 3.14 = "<<result<<" (typr: double)"<<std::endl;

    return 0;
}