#include <iostream>

enum class Week{
    Monday = 1,
    Tuesday,
    Wednestday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
};

const std::string week_name[] = {
    "","周一","周二","周三","周四","周五","周六","周日"
};

std::string get_day_name(Week day){
    return week_name[static_cast<int>(day)];
}

bool is_weekend(Week day){
    int x = static_cast<int>(day); 
    bool flg = x>=6?true:false;
    return flg;
}

int main(){
    for(int i = 1;i<8;i++){
        Week day = static_cast<Week>(i);
        if(is_weekend(day)){
            std::cout<<i<<" -> "<<get_day_name(day)<<" -> "<<"周末"<<std::endl;
        }else{
            std::cout<<i<<" -> "<<get_day_name(day)<<" -> "<<"工作日"<<std::endl;
        }
        
    }

}