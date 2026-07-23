#include <iostream>
#include <string>

class FileManager{
    std::string* data_;
    std::string* name_;
    std::string* mode_;
    
public:
    FileManager(const std::string& name, const std::string& mode) : data_(new std::string("")), name_(new std::string(name)), mode_(new std::string(mode)){
        std::cout<<*mode_<<"文件: "<<*name_<<": 内容为: "<<*data_<<std::endl;
    }
    ~FileManager(){
        std::cout<<"关闭文件: "<<*name_<<std::endl;
        delete data_;
        delete name_;
        delete mode_;
    }

    void write(const std::string& data){
        *data_ = data;
    }
    std::string read() const {
        return *data_;
    }

    std::string get_filename() const {
        return *name_;
    }
};

void func(FileManager& fm){
    std::string data = fm.read();
    std::cout<<"data = "<<data<<std::endl;
    fm.write("Hello World");
    data = fm.read();
    std::cout<<"data = "<<data<<std::endl;
}

int main(){
    {
        FileManager* fm = new FileManager("学习资料.txt", "打开");
        func(*fm);
        delete fm;
    }
    std::cout<<"==========================="<<std::endl;
    FileManager fm_1("文件1.txt", "打开");
    FileManager fm_2("文件2.txt", "打开");

    std::cout<<"文件2先析构"<<std::endl;
    std::cout<<"文件1后析构"<<std::endl;

}

