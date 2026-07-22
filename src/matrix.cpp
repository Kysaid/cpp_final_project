#include "../include/matrix.h"
#include <cstring>
#include <stdexcept>

// 1. 默认构造
Matrix::Matrix() : data_(nullptr), rows_(0), cols_(0) {}

// 2. 参数构造
Matrix::Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols) {
    data_ = new double[rows * cols]();
}

// 3. 析构
Matrix::~Matrix() {
    delete[] data_;
}

// 4. 拷贝构造
Matrix::Matrix(const Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
    data_ = new double[rows_ * cols_]();
    std::memcpy(data_, other.data_, sizeof(double) * rows_ * cols_);
}

// 5. 拷贝赋值
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    delete[] data_;
    rows_ = other.rows_;
    cols_ = other.cols_;
    data_ = new double[rows_ * cols_]();
    std::memcpy(data_, other.data_, sizeof(double) * rows_ * cols_);
    return *this;
}

// 6. 移动构造
Matrix::Matrix(Matrix&& other) noexcept
    : data_(other.data_), rows_(other.rows_), cols_(other.cols_) {
    other.data_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
}

// 7. 移动赋值
Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this == &other) return *this;
    delete[] data_;
    data_ = other.data_;
    rows_ = other.rows_;
    cols_ = other.cols_;
    other.data_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
    return *this;
}

// 8. 设置值
void Matrix::Set(size_t row, size_t col, double value) {
    if (row < rows_ && col < cols_) {
        data_[row * cols_ + col] = value;
    }
}

// 9. 获取值
double Matrix::Get(size_t row, size_t col) const {
    if (row < rows_ && col < cols_) {
        return data_[row * cols_ + col];
    }
    return 0.0;
}

// 10. 打印
void Matrix::Print() const {
    std::cout << "Matrix (" << rows_ << "x" << cols_ << "):" << std::endl;
    for (size_t i = 0; i < rows_; ++i) {
        std::cout << "  ";
        for (size_t j = 0; j < cols_; ++j) {
            std::cout << data_[i * cols_ + j] << " ";
        }
        std::cout << std::endl;
    }
}

// 11. 加法
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::invalid_argument("维度不匹配！");
    }
    Matrix result(rows_, cols_);
    for (size_t i = 0; i < rows_ * cols_; ++i) {
        result.data_[i] = data_[i] + other.data_[i];
    }
    return result;
}

// 标量乘法（成员函数）
Matrix Matrix::Multiply(double scalar) const {
    Matrix result(rows_, cols_);
    for (size_t i = 0; i < rows_ * cols_; ++i) {
        result.data_[i] = data_[i] * scalar;
    }
    return result;
}

// 标量乘法（运算符重载）
Matrix Matrix::operator*(double scalar) const {
    return Multiply(scalar);  // 复用上面的实现
}

// 12. 输出流（友元）
std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    os << "Matrix (" << m.rows_ << "x" << m.cols_ << "):" << std::endl;
    for (size_t i = 0; i < m.rows_; ++i) {
        os << "  ";
        for (size_t j = 0; j < m.cols_; ++j) {
            os << m.data_[i * m.cols_ + j] << " ";
        }
        os << std::endl;
    }
    return os;
}