#include <iostream>
#include <cstring>
class Matrix {
    size_t rows_, cols_;
    double** data_;
    static size_t matrix_count_;
    mutable double cached_det_; 
    mutable bool cached_valid_;

public:
    Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols), data_(new double* [rows_]()){
        for(size_t i = 0;i<rows_;i++)
            data_[i] = new double[cols_]();
        Matrix::matrix_count_++;
        cached_det_ = 0;
        cached_valid_ = false;
        std::cout<<"二维动态数组创建成功"<<std::endl;
    }
    ~Matrix(){
        Matrix::matrix_count_--;
        std::cout<<"析构成功"<<std::endl;
        for(size_t i = 0;i<rows_;i++)
            delete[] data_[i];
        delete[] data_;
    }

    Matrix(const Matrix& other) : Matrix(other.rows_, other.cols_){
  
        for(size_t i = 0;i<rows_;i++){
            for(size_t j = 0;j<cols_;j++){
                data_[i][j] = other.data_[i][j];
            }
        }
    
    }
    Matrix& operator=(const Matrix& other){
        if(other == *this){
            return *this;
        }
        for(size_t i = 0;i<rows_;i++) delete[] data_[i];
        delete[] data_;

        rows_ = other.rows_;
        cols_ = other.cols_;
        data_ = new double*[rows_];
        for(size_t i = 0;i<rows_;i++) {
            data_[i] = new double[cols_];
            for(size_t j = 0;j<cols_;j++){
                data_[i][j] = other.data_[i][j];
            }
        }
        return *this;
        
    }

    double& operator()(size_t i, size_t j){
        return data_[i][j];
    }

    const double operator()(size_t i, size_t j) const {
        return data_[i][j];
    }

    Matrix operator+(const Matrix& other) const {
        Matrix temp(rows_, cols_);
        for(size_t i = 0;i<rows_;i++){
            for(size_t j = 0;j<cols_;j++){
                temp.data_[i][j] = this->data_[i][j] + other.data_[i][j];
            }
        }
        return temp;
    }

    Matrix operator*(double scaler) const {
        Matrix temp(rows_, cols_);
        for(size_t i = 0;i<rows_;i++){
            for(size_t j = 0;j<cols_;j++){
                temp.data_[i][j] = scaler * this->data_[i][j];
            }
        }
        
        return temp;
    }

    friend Matrix operator*(double scaler, const Matrix & m) {
        Matrix temp(m.rows_, m.cols_);
        for(size_t i = 0;i<m.rows_;i++){
            for(size_t j = 0;j<m.cols_;j++){
                temp.data_[i][j] = scaler * m.data_[i][j];
            }
        }
        temp.cached_det_ = scaler * m.cached_det_;
        return temp;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix temp(rows_, other.cols_);
        for(size_t i = 0;i<rows_;i++){
            for(size_t j = 0;j<other.cols_;j++){
                for(size_t k = 0;k<cols_;k++){
                    temp.data_[i][j] += data_[i][k] * other.data_[k][j]; 
                }
            }
        }
        return temp;
    }

    bool operator==(const Matrix& other) const {
        if(cols_ != other.cols_ || rows_ != other.rows_){
            return false;
        }else{
            for(size_t i = 0;i<rows_;i++){
                for(size_t j = 0;j<cols_;j++){
                    if(data_[i][j] != other.data_[i][j]){
                        return false;
                    }
                }
            }
            return true;
        }
    }

    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }

    static size_t get_matrix_count() {
        return matrix_count_;
    }

    size_t rows() const {
        return rows_;
    }
    size_t cols() const {
        return cols_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m){
        for(size_t i = 0;i<m.rows_;i++){
            for(size_t j = 0;j<m.cols_;j++){
                os<<m.data_[i][j]<<" ";
            }
            os<<"\n";
        }
        return os;
    }
};

size_t Matrix::matrix_count_ = 0;

int main() {
    // 构造
    Matrix a(2, 3);
    a(0, 0) = 1; a(0, 1) = 2; a(0, 2) = 3;
    a(1, 0) = 4; a(1, 1) = 5; a(1, 2) = 6;

    Matrix b(2, 3);
    b(0, 0) = 6; b(0, 1) = 5; b(0, 2) = 4;
    b(1, 0) = 3; b(1, 1) = 2; b(1, 2) = 1;

    // 加法
    Matrix sum = a + b;
    std::cout << "加法结果:\n" << sum;

    // 标量乘法
    Matrix scaled = a * 2.0;
    std::cout << "标量乘法:\n" << scaled;

    // 友元标量乘法
    Matrix scaled2 = 2.0 * a;
    std::cout << "友元标量乘法:\n" << scaled2;
    std::cout << "(scaled == scaled2): " << (scaled == scaled2 ? "✅" : "❌") << "\n";

    // 矩阵乘法
    // a 是 2×3，a 的转置是 3×2 → 结果 2×2
    Matrix at(3, 2);  // 手动构建转置
    at(0, 0) = 1; at(0, 1) = 4;
    at(1, 0) = 2; at(1, 1) = 5;
    at(2, 0) = 3; at(2, 1) = 6;
    Matrix prod = a * at;
    std::cout << "矩阵乘法 a * aT:\n" << prod;

    // const 对象测试
    const Matrix& cref = a;
    std::cout << "const 访问: " << cref(0, 0) << "\n";  // 调 const 版本
    // cref(0, 0) = 99;  // ❌ 编译报错

    // 静态成员
    std::cout << "矩阵总数: " << Matrix::get_matrix_count() << "\n";

    // 拷贝构造 + 赋值
    Matrix c = a;
    Matrix d(1, 1);
    d = a;
    std::cout << "拷贝正确: " << (c == a && d == a ? "✅" : "❌") << "\n";
}