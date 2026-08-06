#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ofstream out("data.txt");
    out << "Hello, File"<<std::endl;
    out << 42 <<std::endl;
    out.close();

    std::ifstream in("data.txt");
    std::string line;
    while (std::getline(in, line)) {
        std::cout<< line <<std::endl;
    }
    in.close();
}
