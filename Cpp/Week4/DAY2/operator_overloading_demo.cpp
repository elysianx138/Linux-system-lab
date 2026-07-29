#include <iostream>

class IntArray{
    int* data_;
    size_t size_;
public:
    IntArray(size_t size) : data_(new int[size]()), size_(size){}

    int& operator[](size_t i){
        return data_[i];
    }

    const int& operator[](size_t i) const {
        return data_[i];
    }

    size_t size() const {
        return size_;
    }
};

class Counter{
    int count_ = 0;
public:
    Counter& operator++(){
        ++count_;
        return *this;
    }
    Counter operator++(int){
        Counter temp = *this;
        ++count_;
        return temp;
    }

    int get() const {
        return count_;
    }
};

class Adder{
    int base_;
public:
    Adder(int base) : base_(base){}

    int operator()(int x) const {
        return base_ + x;
    }
};


int main(){
    IntArray arr(3);
    arr[0] = 42;
    const IntArray& carr = arr;
    std::cout<<carr[0]<<std::endl;

    Counter c;
    Counter& ref = ++c;
    std::cout<< ref.get()<<std::endl;
    Counter val = c++;
    std::cout<< val.get()<<std::endl;

    Adder add5(5);
    std::cout<<add5(5)<<std::endl;
    std::cout<<add5(10)<<std::endl;
}