#include <iostream>

void pass_by_value(int arr[5]) {
    // 这里是函数内部，arr 是参数名
    std::cout << "arr[0] 地址：" << &arr[0] << std::endl;
    std::cout << "sizeof(arr) = " << sizeof(arr) << " 字节 ← 函数内部" << std::endl;
    
    // 通过 arr 修改数据
    arr[0] = 999;
}

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    
    std::cout << "numbers 地址：" << numbers << std::endl;
    std::cout << "sizeof(numbers) = " << sizeof(numbers) << " 字节 ← main 中" << std::endl;
    std::cout << "========================" << std::endl;
    
    std::cout << "调用前 numbers[0] = " << numbers[0] << std::endl;
    
    pass_by_value(numbers);
    
    std::cout << "调用后 numbers[0] = " << numbers[0] << std::endl;
    
    return 0;
}