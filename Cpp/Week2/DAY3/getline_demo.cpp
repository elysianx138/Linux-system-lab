#include <iostream>
#include <string>

int main(){
    std::string line;
    // std::cout<<"请输入一个字符串: "<<std::endl;
    // std::cin>>line;
    // std::cout<<line<<std::endl;
    std::cout<<"请输入一个字符串: "<<std::endl;
    std::getline(std::cin, line);
    std::cout<<line<<std::endl;

    std::cout<<"输入一个数字: \n";
    int n;
    std::cin>>n;
    std::cin.ignore();
    std::cout<<"输入一个字符串: ";
    std::string s;
    std::getline(std::cin, s);
    std::cout<<"字符串是: '"<<s<<"' "<<std::endl;

    return 0;
}