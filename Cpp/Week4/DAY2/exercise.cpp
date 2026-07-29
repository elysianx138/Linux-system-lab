#include <iostream>

class Counter{
    int count_;

public:
    Counter(int count) : count_(count) {}
    Counter& operator++(){
        ++count_;
        return *this;
    }
    Counter operator++(int){
        Counter temp(count_);
        ++count_;
        return temp;
    }
    int operator()() const {
        return count_;
    }
    int operator[](int x) const {
        return count_ + x;      
    }
};

int main(){
    Counter c(5);

    Counter val = c++;
    std::cout<< val() <<std::endl;
    Counter& ref = ++c;
    std::cout<< ref() <<std::endl;
    std::cout<< c() <<std::endl;
    std::cout<< c[0] <<std::endl;
    std::cout<< c[1] <<std::endl;

}