#include <iostream>
#include <cmath>
namespace Geometry{
    const double PI = 3.14159;
    double area(const double& radius){
        return PI * radius * radius;
    }

    inline double area(const double& width, const double& height){
        return width * height;
    }

    double area(const double& a, const double& b, const double& c){
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
}

int main(){
    std::cout<<"Geometry::area(5) = "<<Geometry::area(5.0)<<std::endl;
    std::cout<<"Geometry::area(4, 6) = "<<Geometry::area(4, 6)<<std::endl;
    std::cout<<"Geometry::area(3, 4, 5) = "<<Geometry::area(3, 4, 5)<<std::endl;

}