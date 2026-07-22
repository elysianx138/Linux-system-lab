#include <iostream>
#include <string>

class Student{
private:
    std::string name_;
    int id_;
    double score_;

public:
    Student(const std::string& name, int id, double score) : name_(name), id_(id), score_(score){
        std::cout<<"学生"<<name_<<"已经创建"<<std::endl;
    }

    std::string get_name() const {
        return name_;
    }

    int get_id() const {
        return id_;
    }

    double get_score() const {
        return score_;
    }

    void set_score(double score){
        if(score < 0 || score > 100){
            std::cerr<<"错误:分数必须在0-100之间"<<std::endl;
            return;
        }
        score_ = score;
    }

    void display() const {
        std::cout<<name_<<" ("<<id_<<") 分数:"<<score_<<std::endl;
    }
};

int main(){
    Student s("张三", 1001, 92.5);
    s.display();

    s.set_score(-100);
    s.set_score(98.5);
    s.display();

    Student* p = new Student("李四", 1002, 88.0);
    p->display();
    p->set_score(95.0);
    delete p;
    
    return 0;
}