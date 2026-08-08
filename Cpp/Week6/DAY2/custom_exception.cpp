#include <stdexcept>
#include <iostream>
class ScoreOutOfRange : public std::runtime_error {
public:
    ScoreOutOfRange(int score) : std::runtime_error("分数越界: " + std::to_string(score)) {}
};

double check_score(int score) {
    if(score < 0 || score > 100)
        throw ScoreOutOfRange(score);
    return score;
}

int main() {
    try {
        check_score(85);
        check_score(105);
    } catch (const ScoreOutOfRange& e) {
        std::cout<<"越界: "<<e.what()<<std::endl;
    } catch (const std::exception& e) {
        std::cout<< "其他错误: "<<e.what()<<std::endl;
    }
}