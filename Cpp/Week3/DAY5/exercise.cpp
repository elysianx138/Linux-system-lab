#include <iostream>
#include <cstring>
#include <string>

class ScoreTracker{
    std::string name_;
    size_t capacity_;
    double* scores_;
    size_t count_;
    static size_t total_scores_;

public:
    ScoreTracker(const std::string& name, size_t capacity) : name_(name), capacity_(capacity), scores_(new double[capacity_]()), count_(0){
        ScoreTracker::total_scores_++;
        std::cout<<"跟踪器: "<<name_<<"容量为: "<<capacity_<<std::endl;
    }

    ~ScoreTracker(){
        delete[] scores_;
        ScoreTracker::total_scores_--;
        std::cout<<"跟踪器: "<<name_<<"析构成功!"<<std::endl;
    }

    ScoreTracker(const ScoreTracker& other) : ScoreTracker(other.name_, other.capacity_) {
        std::copy(other.scores_, other.scores_ + other.count_, this->scores_);
        this->count_ = other.count_;
        std::cout<<"跟踪器: "<<other.name_<<"拷贝构造成功"<<std::endl;
    }

    ScoreTracker& operator=(const ScoreTracker& other) {
        if(this == &other)
            return *this;
        double* new_score = new double[other.capacity_];
        std::copy(other.scores_, other.scores_ + other.count_, new_score);
        delete[] this->scores_;
        this->scores_ = new_score;
        this->capacity_ = other.capacity_;
        this->count_ = other.count_;
        this->name_ = other.name_;
        return *this;
    }

    ScoreTracker& add_score(double score){
        size_t i = count_;
        if(count_ <= capacity_ - 1){
            *(scores_ + i) = score;
            if(count_ < capacity_){
                count_++;
            }
        }else{
            std::cout<<"追踪器自动扩容"<<std::endl;
            capacity_++;
            double* new_scores_ = new double[capacity_];
            std::copy(scores_, scores_+count_,new_scores_);
            delete[] scores_;
            scores_ = new_scores_;
            *(scores_ + i) = score;
            count_++;
        }
        return *this;
    }

    double average() const {
        double total_ = 0.0;
        for(size_t i = 0;i<count_;i++){
            total_ += *(scores_+i);
        }
        double average = total_ / count_;
        return average;
    }

    size_t size() const {
        return capacity_;
    }

    double& operator[](size_t t){
        return scores_[t];
    }

    const std::string& name() const {
        return name_;
    }

    void print() const {
        std::cout<<"当前跟踪器信息: "<<name_<<"平均分为: "<<average()<<std::endl;
        for(size_t i = 0;i<count_;i++){
            std::cout<<"所有成绩为: "<<*(scores_+i)<<" ";
        }
        std::cout<<"当前容量为: "<<capacity_<<std::endl;
    }

    static size_t get_total_scores() {
        return ScoreTracker::total_scores_;
    }

};

size_t ScoreTracker::total_scores_ = 0;

int main() {
    // 链式添加
    ScoreTracker t1("周测", 4);
    t1.add_score(85).add_score(92).add_score(78).add_score(88);
    t1.add_score(95);  // 触发扩容
    t1.print();
    
    // 拷贝构造
    ScoreTracker t2 = t1;
    t2.add_score(100);
    std::cout << "t1 和 t2 独立: " << (t1.size() != t2.size() ? "✅" : "❌") << "\n";
    
    // 静态成员
    std::cout << "总共记录了 " << ScoreTracker::get_total_scores() << " 个成绩\n";
    // 拷贝赋值 + 自赋值
    ScoreTracker t3("期末", 4);
    t3 = t1;
    t3 = t3;  // 自赋值
    t3.print();
    
}
