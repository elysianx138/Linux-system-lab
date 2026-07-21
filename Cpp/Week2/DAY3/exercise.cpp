#include <iostream>
#include <string>

std::string find_name(const std::string& s){
    size_t pos = s.find(" ");
    return s.substr(0, pos);
}

int cal_total_scores(const std::string& s){
    size_t start = s.find(" ");
    int total_score = 0;

    while(start < s.size()){
        size_t end = s.find(" ",start);

        if (end == std::string::npos)
            end = s.size();

        total_score += stoi(s.substr(start, end - start));
        start = end + 1;
    }
}

double cal_pertage_score(int total_score, int count){
    return static_cast<double>(total_score)/count;
}

int main(){
    int _size;
    std::string str;
    std::cout<<"请输入学生个数: "<<std::endl;
    std::cin>>_size;
    std::cin.ignore();
    for(int i = 0;i<_size;i++){
        std::cout<<"输入学生信息: "<<std::endl;
        getline(std::cin, str);
        
        std::string _name = find_name(str);
        int total_socre = cal_total_scores(str);
        double avg = cal_pertage_score(total_socre, 3);

        std::cout<<_name<<": 总分="<<total_socre<<", 平均分="<<avg<<std::endl;
    }


    return 0;
}