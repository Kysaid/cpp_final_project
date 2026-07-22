#pragma once
#include <iostream>

class Matrix {
private:
    double* data_;
    size_t rows_;
    size_t cols_;

public:
    // 构造 / 析构
    Matrix();
    Matrix(size_t rows, size_t cols);
    ~Matrix();

    // 拷贝控制（三/五法则）
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    // 移动语义（C++11）
    Matrix(Matrix&& other) noexcept;
    Matrix& operator=(Matrix&& other) noexcept;

    // 基础操作
    void Set(size_t row, size_t col, double value);
    double Get(size_t row, size_t col) const;
    void Print() const;

    // 运算符重载
    Matrix operator+(const Matrix& other) const;
    Matrix Multiply(double scalar) const;
    Matrix operator*(double scalar) const;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
};