#include <iostream>
#include <stdexcept>
#include <cstring>
class OutOfRange : public std::runtime_error {
public:
    OutOfRange(size_t size) : std::runtime_error("下标越界: " + std::to_string(size)) {}
};

// template <typename T>
class ScoreOutOfRange : public std::runtime_error {
public:
    ScoreOutOfRange(int score) : std::runtime_error("分数越界: " + std::to_string(score)) {}
};

template <typename T = int>
class Scores {
    size_t size_;
    T* data_;
public:
    Scores(size_t size) : size_(size), data_(new T[size_]()) {};
    ~Scores(){
        delete[] data_;
    }
    Scores(const Scores& other) : Scores(other.size_) {
        std::copy(other.data_, other.data_+other.size_, data_);
    }
    Scores& operator=(const Scores& other) {
        if(this == &other){
            return *this;
        }
        T* new_data_ = new T[other.size_];
        std::copy(other.data_, other.data_+other.size_, new_data_);
        delete[] data_;
        data_ = new_data_;
        size_ = other.size_;
        return *this;
    }

    void set(size_t i, T value){
        if(i>=size_){
            throw OutOfRange(i);
        }
        if(value<0 || value>100){
            throw ScoreOutOfRange(value);
        }
        data_[i] = value;
        
    }

    void print() const {
        for(size_t i = 0;i<size_;i++){
            std::cout<<data_[i]<<" ";
        }
        std::cout<<std::endl;
    }
};

template <typename T>
T better(const T& a, const T& b) {
    return a > b? a : b;
}

int better(int a, int b) {
    return a + b;
}
int main() {
    // ① 默认类型 + 显式类型
    Scores<> s1(3);              // T = int（默认）
    Scores<double> s2(2);        // T = double

    s1.set(0, 85); s1.set(1, 92); s1.set(2, 78);
    s2.set(0, 95.5); s2.set(1, 88.5);

    // ② 越界 → 自定义异常 + 多重 catch
    try {
        s1.set(2, 150);   
               // ❌ 下标越界 → 抛异常（用 std::out_of_range 或自定义）
            // ❌ 分数越界 → 抛 ScoreOutOfRange
    }
    catch (const ScoreOutOfRange& e) {       // 先子类
        std::cout << "分数错误: " << e.what() << "\n";
    }
    catch (const OutOfRange& e) {
        std::cout<< "越界: " << e.what() <<std::endl;
    }
    catch (const std::exception& e) {        // 后基类
        std::cout << "其他错误: " << e.what() << "\n";
    }

    try {
        s1.set(5, 90);   
               // ❌ 下标越界 → 抛异常（用 std::out_of_range 或自定义）
            // ❌ 分数越界 → 抛 ScoreOutOfRange
    }
    catch (const ScoreOutOfRange& e) {       // 先子类
        std::cout << "分数错误: " << e.what() << "\n";
    }
    catch (const OutOfRange& e) {
        std::cout<< "越界: " << e.what() <<std::endl;
    }
    catch (const std::exception& e) {        // 后基类
        std::cout << "其他错误: " << e.what() << "\n";
    }

    // ③ 模板重载验证
    std::cout << better(1, 2) << "\n";       // 普通函数 → 3
    std::cout << better(1.5, 2.5) << "\n";   // 模板 → 2.5
    std::cout << better(5, 10) << "\n";      // 普通函数 → 15

    // ④ 打印
    s1.print();
    s2.print();

    return 0;
}


