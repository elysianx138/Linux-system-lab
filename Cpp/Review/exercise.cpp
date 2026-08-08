#include <iostream>
bool find_extremes(const int* arr, size_t t, int& max, int& min){
    if(arr==nullptr || t == 0){
        return false;
    }
    for(size_t i = 0;i<t;i++){
        if(max<arr[i])
            max = arr[i];
        if(min>arr[i])
            min = arr[i];
    }
    return true;
}

int main() {
    int scores[] = {78, 95, 85, 62, 88};
    int max = scores[0], min = scores[0];

    if (find_extremes(scores, 5, max, min)) {
        std::cout << "最高: " << max << " 最低: " << min << "\n";
    }

    if (!find_extremes(nullptr, 5, max, min)) {
        std::cout << "nullptr 被拦截 ✅\n";
    }
    if (!find_extremes(scores, 0, max, min)) {
        std::cout << "size=0 被拦截 ✅\n";
    }
}