#include <iostream>
#include <cstring>
#include <string>

class FixArray{
    std::string name_;
    int* data_;
    size_t size_;

public:
    FixArray(size_t size, const std::string& name) : name_(name), size_(size), data_(new int[size]()) {
        std::cout<<"构造数组["<<name_<<"]"<<": "<<size<<"个元素"<<std::endl;
    }
    ~FixArray(){
        delete[] data_;
        std::cout<<"数组"<<name_<<"析构成功"<<std::endl;
    }

    FixArray(const FixArray& other) : FixArray(other.size_, other.name_) {
        std::copy(other.data_, other.data_ + size_, data_);
        std::cout<<"拷贝构造 ["<<name_<<"]\n"<<std::endl;
    }

    FixArray& operator=(const FixArray& other){
        if(this != &other){
            int* new_data = new int[other.size_];
            std::copy(other.data_, other.data_ + other.size_, new_data);

            delete[] data_;
            data_ = new_data;
            size_ = other.size_;
            name_ = other.name_;
            std::cout<<"拷贝赋值 ["<<name_<<"]"<<std::endl;
        }
        return *this;
    } 

    int& operator[](size_t t){
        return data_[t];
    }

    size_t size() const{
        return size_;
    }

    const int& operator[](size_t t) const {
        return data_[t];
    }

    void display() const {
        std::cout<<name_<<"数值为: "<<*data_<<std::endl;
    }

};

void print_array(FixArray& array){
    for(int i = 0;i<array.size();i++){
        std::cout<<array[i]<<" "<<std::endl;
    }
    std::cout<<std::endl;
}

int main(){
    FixArray a(3, "A");
    for (size_t i = 0; i < a.size(); i++) a[i] = i * 10;

    FixArray b = a;            // 拷贝构造
    b[0] = 999;

    FixArray c(2, "C");
    c = a;                     // 拷贝赋值

    print_array(a);            // A: 0 10 20
    print_array(b);            // B: 999 10 20（深拷贝，独立！）
    print_array(c);            // C: 0 10 20（size 也正确更新了）

    c = c;                     // 自赋值，不会崩
    std::cout << "自赋值通过 ✅\n";

    // 验证所有析构都正常调用
    std::cout << "--- 准备析构 ---\n";
    return 0;
}