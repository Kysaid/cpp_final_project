#include "../include/matrix.h"
#include <iostream>

int main() {
    std::cout << "=== 矩阵库功能测试（Git 教学修改版） ===\n" << std::endl;

    // 1. 构造矩阵 A (2x2) - 修改了数值
    Matrix a(2, 2);
    a.Set(0, 0, 10.0);
    a.Set(0, 1, 20.0);
    a.Set(1, 0, 30.0);
    a.Set(1, 1, 40.0);
    std::cout << "矩阵 A:\n" << a << std::endl;

    // 2. 构造矩阵 B (2x2) - 修改了数值
    Matrix b(2, 2);
    b.Set(0, 0, 50.0);
    b.Set(0, 1, 60.0);
    b.Set(1, 0, 70.0);
    b.Set(1, 1, 80.0);
    std::cout << "矩阵 B:\n" << b << std::endl;

    // 3. 加法：C = A + B
    Matrix c = a + b;
    std::cout << "矩阵 C = A + B:\n" << c << std::endl;

    // 4. 拷贝构造：D = C
    Matrix d = c;
    std::cout << "矩阵 D (拷贝自 C):\n" << d << std::endl;

    // 5. 移动构造：E = std::move(D)
    Matrix e = std::move(d);
    std::cout << "矩阵 E (移动自 D):\n" << e << std::endl;
    std::cout << "移动后，D 的内容已失效（空壳）" << std::endl;

    // 6. 移动赋值：F = std::move(E)
    Matrix f(2, 2);
    f = std::move(e);
    std::cout << "矩阵 F (移动赋值自 E):\n" << f << std::endl;

    // 7. 修改 F 的元素
    f.Set(0, 0, 99.0);
    std::cout << "修改 F[0][0] = 99 后:\n" << f << std::endl;

    // 8. 测试标量乘法
    std::cout << "--- 标量乘法测试 ---" << std::endl;
    Matrix scaled = a * 2.0;  // 使用重载的 operator*
    std::cout << "矩阵 A * 2.0:\n" << scaled << std::endl;

    std::cout << "=== 测试结束 ===" << std::endl;
    return 0;
}