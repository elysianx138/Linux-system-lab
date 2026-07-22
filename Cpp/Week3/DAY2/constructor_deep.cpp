#include <iostream>
#include <string>

class Student{
private:
    std::string name_;
    int id_;
    const int class_id_;
    static int total_count_;

public:
    Student(const std::string& name, int id, int class_id) : name_(name), id_(id), class_id_(class_id){
        total_count_ ++;
        std::cout << "主构造: " << name_ << " (班级" << class_id_ << ")" << std::endl;
    }

    Student(const std::string& name,int id) : Student(name, id, 1){
        std::cout<< "委托构造 -> ";
    }

    Student() : name_("未命名"), id_(0), class_id_(0){
        total_count_++;
        std::cout << "默认构造" << std::endl;
    }

    Student(const Student& other) : name_(other.name_), id_(other.id_), class_id_(other.class_id_){
        total_count_++;
        std::cout << "拷贝构造: " << name_ << std::endl;
    }

    void display() const{
        std::cout << name_ << " (ID:" << id_ << ", 班级:" << class_id_ << ")" << std::endl;
    }

    ~Student(){
        total_count_--;
        std::cout << "析构: " << name_ << std::endl;
    }

    static int get_total_count(){
        return total_count_;
    }
};

int Student::total_count_ = 0;

int main(){
    std::cout << "========== 各种构造方式 ==========" << std::endl;
    
    std::cout << "① 默认构造:" << std::endl;
    Student s0;

    std::cout << "\n② 主构造:" << std::endl;
    Student s1("张三", 1001, 2);

    std::cout << "\n③ 委托构造:" << std::endl;
    Student s2("李四", 1001);

    std::cout << "\n④ 拷贝构造:" << std::endl;
    Student s3 = s1;

    std::cout<<"\n====================当前学生总数================="<<std::endl;
    std::cout<<"total_count_ = "<<Student::get_total_count()<<std::endl;

    std::cout<<"\n====================所有学生信息================="<<std::endl;
    s0.display();
    s1.display();
    s2.display();
    s3.display();

    std::cout<<"\n====================程序结束,开始析构============"<<std::endl;
    return 0;

}