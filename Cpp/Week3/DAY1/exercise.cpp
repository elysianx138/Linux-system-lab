#include <iostream>

namespace Math{
    const double PI = 3.14159;
}

class Circle{
private:
    double radius_;

public:
    Circle(double radius) : radius_(radius){
        std::cout<<radius_<<"的圆构造成功"<<std::endl;
    } 
    double get_radius() const {
        return radius_;
    }
    void set_radius(double r){
        if(r<=0){
            std::cerr<<"半径必须大于零"<<std::endl;
            return;
        }
        this->radius_ = r;
    }

    double area() const {
        return this->radius_ * this->radius_ * Math::PI;
    }

    double circumference() const {
        return this->radius_ * 2 * Math::PI;
    }

};

void find_max_circle(const Circle* circle, size_t t){
        if(circle == nullptr){
            std::cerr<<"传入合法数组"<<std::endl;
        }
        double max_ = -1;
        int pos_ = -1;
        for(size_t p = 0;p < t;p++){
            double r = (circle+p) -> get_radius(); 
            if (max_ < r){
                max_ = r;
                pos_ = p;
            }
        }
        std::cout<<"面积最大的圆的半径为: circle["<<pos_<<"] "<<", 半径为: "<<max_<<std::endl;
    }

int main(){
    Circle* circle = new Circle[2]{{2}, {5}};

    std::cout<<"圆1: 半径="<<circle->get_radius()<<", 面积="<<circle->area()<<", 周长="<<circle->circumference()<<std::endl;
    std::cout<<"圆2: 半径="<<(circle + 1)->get_radius()<<", 面积="<<(circle + 1)->area()<<", 周长="<<(circle + 1)->circumference()<<std::endl;

    find_max_circle(circle, 2);
    delete[] circle;
}



