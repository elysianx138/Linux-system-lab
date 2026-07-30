#include <iostream>

class Array{
    int data_[3] = {1, 2, 3};
    mutable int count_ = 0;
    std::string name_;
public:
    int& operator[](size_t i) {
        std::cout<< "非const版本\n";
        return data_[i];
    }
    std::string get_name() const {
        count_++;  
        return name_;
    }

    const int& operator[](size_t i) const {
        std::cout<< "const版本\n";
        return data_[i];
    }
};

int main(){
    Array arr;
    arr[0] = 42;
    std::cout<<arr[0];
    std::cout<<std::endl;

    const Array& carr = arr;
    // carr[0] = 42;
    std::cout<< carr[0];
}