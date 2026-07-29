#include <iostream>
class Matrix2x2;

class Vector2D {
private:
    double x_, y_;
public:
    friend class Matrix2x2;
    Vector2D(double x, double y) : x_(x), y_(y) {}
    static void print(Vector2D& v) {
        std::cout<<"("<<v.x_<<", "<<v.y_<<") "<<std::endl;
    }
    Vector2D operator*(const Matrix2x2& other) ;
    //{
    //     Vector2D temp(0, 0);
    //     temp.x_ = x_ * other.m_[0][0] + y_ * other.m_[1][0];
    //     temp.y_ = x_ * other.m_[0][1] + y_ * other.m_[1][1];
    //     Vector2D::print(temp);
    //     return temp;
    // }   
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "("<<v.x_<<", "<<v.y_<<") "<<'\n';
        return os;
    }
};


class Matrix2x2 {
    double m_[2][2];
public:
    Matrix2x2(double a = 0, double b = 0, double c = 0, double d = 0) {
        m_[0][0] = a, m_[0][1] = b, m_[1][0] = c, m_[1][1] = d;
        std::cout<<"矩阵创建成功!"<<std::endl;
        print(*this);
    }
    friend class Vector2D;
    static void print(const Matrix2x2& ma) {
        for(int i = 0;i<2;i++){
            for(int j = 0;j<2;j++){
                std::cout<<ma.m_[i][j]<<' ';
            }
            std::cout<<std::endl;
        }
    }

    const Matrix2x2 operator*(const Matrix2x2& other) {
        Matrix2x2 temp;
        temp.m_[0][0] = m_[0][0] * other.m_[0][0] + m_[0][1] * other.m_[1][0];
        temp.m_[0][1] = m_[0][0] * other.m_[0][1] + m_[0][1] * other.m_[1][1];
        temp.m_[1][0] = m_[1][0] * other.m_[0][0] + m_[1][1] * other.m_[1][0];
        temp.m_[1][1] = m_[1][0] * other.m_[0][1] + m_[1][1] * other.m_[1][1];
        Matrix2x2::print(temp);
        return temp;
    }

    Vector2D operator*(const Vector2D& v) ;
    // {
    //     Vector2D temp(0, 0);
    //     temp.x_ = m_[0][0] * v.x_ + m_[0][1] * v.y_;
    //     temp.y_ = m_[1][0] * v.x_ + m_[1][1] * v.y_;
    //     Vector2D::print(temp);
    // }

    const bool operator==(const Matrix2x2& other) const {
        return  other.m_[0][0] == m_[0][0] && other.m_[0][1] == m_[0][1] && other.m_[1][0] == m_[1][0] && other.m_[1][1] == m_[1][1];
    } 
    const bool operator!=(const Matrix2x2& other) const {
        return !(*this==other);
    }
    friend std::ostream& operator<<(std::ostream& os, const Matrix2x2& m) {
        os<<"["<<m.m_[0][0]<<' '<<m.m_[0][1]<<"]"<<'\n'<<"["<<m.m_[1][0]<<' '<<m.m_[1][1]<<"]"<<'\n';
        return os;
    }
};

Vector2D Vector2D::operator*(const Matrix2x2& other){
    Vector2D temp(0, 0);
    temp.x_ = x_ * other.m_[0][0] + y_ * other.m_[1][0];
    temp.y_ = x_ * other.m_[0][1] + y_ * other.m_[1][1];
    Vector2D::print(temp);
    return temp;
}

Vector2D Matrix2x2::operator*(const Vector2D& v){
    Vector2D temp(0, 0);
    temp.x_ = m_[0][0] * v.x_ + m_[0][1] * v.y_;
    temp.y_ = m_[1][0] * v.x_ + m_[1][1] * v.y_;
    Vector2D::print(temp);
    return temp;
}

int main() {
    Matrix2x2 m(1, 2, 3, 4);   // [1 2]
                                // [3 4]
    Matrix2x2 identity(1, 0, 0, 1);  // 单位矩阵

    Vector2D v(5, 6);

    std::cout << "m * v = " << m * v << "\n";    // (1*5+2*6, 3*5+4*6) = (17, 39)
    std::cout << "v * m = " << v * m << "\n";    // (5*1+6*3, 5*2+6*4) = (23, 34)
    
    Matrix2x2 result = m * identity;
    std::cout << "m * I = " << (result == m ? "✅" : "❌") << "\n";
}