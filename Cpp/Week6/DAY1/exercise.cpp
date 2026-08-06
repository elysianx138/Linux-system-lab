#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
template <typename T>
class ScoreBox {
    T score_;
public:
    ScoreBox(const T& score) : score_(score) {};
    T get() const {
        return score_;
    }
};

template <typename T>
T find_best(const T* arr, size_t size) {
    if (size == 0){
        throw std::runtime_error("数组不能为空");
    }
    T max = arr[0];
    for(size_t i = 0;i<size;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

class ScoreManager {
    int* scores_;
    size_t size_;
public:
    ScoreManager(size_t size) : scores_(new int[size]()), size_(size) {}
    ~ScoreManager(){
        delete[] scores_;
    }
    ScoreManager(const ScoreManager& other) : ScoreManager(other.size_){
        for(size_t i = 0;i<other.size_;i++){
            *(scores_+i) = *(other.scores_ + i);
        }
    }
    const ScoreManager& operator=(const ScoreManager& other){
        if(this == &other){
            return *this;
        }
        int* new_scores_ = new int[other.size_];
        for(size_t i = 0;i<other.size_;i++){
            *(new_scores_+i) = *(other.scores_ + i);
        }
        delete[] scores_;
        scores_ = new_scores_;
        size_ = other.size_;
        return *this;
    }
          
    void set(size_t i, int value){
        *(scores_+i) = value;
    }
    double average() const {
        if (size_ == 0){
            throw std::runtime_error("除数不能为0");
        }
        int total = 0;
        for(size_t i = 0;i<size_;i++){
            total += *(scores_+i);
        }
        return static_cast<double>(total) / size_;
    }
    void save_to_file(const std::string& path) const {
        std::ofstream out(path);
        for(size_t i = 0;i<size_;i++){
            out<<*(scores_+i)<<std::endl;
        }
        std::cout<<"保存成功"<<std::endl;
        out.close();
    }
    static ScoreManager* load_from_file(const std::string& path) { 
        std::ifstream in(path);
        if(!in.is_open()){
            std::cout<<"文件路径不存在,请检查路径"<<std::endl;
            return nullptr;
        }
        std::string line;
        size_t size = 0;
        size_t i = 0;
        while (std::getline(in, line)) {
            size++;
        }
        ScoreManager* scoremanager = new ScoreManager(size);
        in.clear(); 
        in.seekg(0); 

        while (std::getline(in, line)) {
            scoremanager->set(i, std::stoi(line));
            i++;
        }
        
        in.close();
        return scoremanager;
    }
};
int main() {
    // ① ScoreBox
    ScoreBox<int> int_box(85);
    ScoreBox<double> double_box(92.5);
    std::cout << int_box.get() << " " << double_box.get() << "\n";

    // ② find_best
    int ints[] = {78, 95, 85, 62, 88};
    double dbls[] = {9.5, 8.8, 9.9, 7.5};
    std::cout << find_best(ints, 5) << "\n";     // 95
    std::cout << find_best(dbls, 4) << "\n";     // 9.9

    // ③ 空数组抛异常
    try {
        int empty[1];
        find_best(empty, 0);   // 应该抛异常
    } catch (const std::exception& e) {
        std::cout << "捕获: " << e.what() << "\n";
    }

    // ④ ScoreManager 保存 + 读取
    ScoreManager m(5);
    for (int i = 0; i < 5; i++) m.set(i, ints[i]);
    m.save_to_file("scores.txt");

    ScoreManager* loaded = ScoreManager::load_from_file("scores.txt");
    std::cout << "从文件读回的平均分: " << loaded->average() << "\n";
    delete loaded;

    return 0;
}