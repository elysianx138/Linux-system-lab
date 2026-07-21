#include <iostream>
#include <string>

int main(){
    std::string s1 = "Hello";
    std::string s2 = "World";
    std::string s3(5, 'A');
    std::string s4 = s1 + " " + s2;

    std::cout<<"s4 = "<<s4<<std::endl;

    std::cout<<"s4.size() = "<<s4.size()<<std::endl;
    std::cout<<"s4.length() = "<<s4.length()<<std::endl;
    std::cout<<"s4[0] = "<<s4[0]<<std::endl;
    std::cout<<"s4.front() = "<<s4.front()<<std::endl;
    std::cout<<"s4.back() = "<<s4.back()<<std::endl;

    for(int i = 0;i<s4.size();i++){
        std::cout<<s4[i];
    }
    std::cout<<std::endl;
    for(char c : s4)
        std::cout<<c;
    std::cout<<std::endl;

    for(char& c : s4)
        c = toupper(c);
    std::cout<<s4;

    std::cout<<"-----------------------------------------------"<<std::endl;

    std::string s = "Hello World, C++ World";
    size_t pos = s.find("World");
    std::cout<<"\n 第一个 World 位置: "<<pos<<std::endl;

    pos = s.find("World", pos + 1);
    std::cout<<"\n 第二个 World 位置: "<<pos<<std::endl;

    pos = s.find("java");
    std::cout<<" pos "<<pos<<" "<<std::endl;

    std::string sub = s.substr(6, 5);
    std::cout<<"substr(6, 5)"<<sub<<std::endl;

    std::string s5 = "Hello C++";
    s5.insert(6, "beautiful ");
    std::cout<<"insert: "<<s5<<std::endl;

    s5.replace(6, 9, "good");
    std::cout<<"replace: "<<s5<<std::endl;

    s5.erase(5, 5);
    std::cout<<"erase: "<<s5<<std::endl;

    std::string num = "42";
    int n = std::stoi(num);
    double d = std::stod("3.14");
    std::string back = std::to_string(123);

    std::cout << "stoi: " << n + 1 << std::endl;   
    std::cout << "stod: " << d + 1 << std::endl;    
    std::cout << "to_string: " << back << std::endl;
    return 0;
}