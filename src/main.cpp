#include "../include/matrix.h"

int main() {
    Matrix a(2, 2);
    a.Set(0, 0, 1);
    a.Set(0, 1, 2);
    a.Set(1, 0, 3);
    a.Set(1, 1, 4);

    Matrix b(2, 2);
    b.Set(0, 0, 5);
    b.Set(0, 1, 6);
    b.Set(1, 0, 7);
    b.Set(1, 1, 8);

    Matrix c = a + b;
    std::cout << c << std::endl;  // 使用重载的 <<
    return 0;
}