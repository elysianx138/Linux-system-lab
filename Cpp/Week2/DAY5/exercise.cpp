#include <iostream>

void compare_num(int& num, int& max, int& min){
    if(num<min) min = num;
    if(max<num) max = num;
}
void find_min_max(const int* arr, int& min, int& max, size_t t){
    if(arr == nullptr){
        std::cerr<<"数组不能为空"<<std::endl;
        return;
    }
    for(size_t p = 0;p < t;p++){
        int num = *(arr + p);
        compare_num(num, max, min);
    }
}

int main(){
    int scores[] = {78, 95, 85, 62, 88, 91, 73};
    int max = -99999;
    int min = 99999;
    size_t t = sizeof(scores) / sizeof(scores[0]);
    find_min_max(scores, min, max, t);
    std::cout<<"Min = "<<min<<" "<<"Max = "<<max<<std::endl;

    return 0;
}