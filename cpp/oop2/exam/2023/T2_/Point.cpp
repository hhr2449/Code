#include "Point.h"
#include <iostream>
#include "Line.h"
template <typename T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template <typename T>
void Point<T>::move(T dx, T dy) {
    x += dx;
    y += dy;
}

template <typename T>
void Point<T>::show() {
    std::cout << "(" << x << "," << y << ")" << std::endl;
}

template <typename T>
bool Point<T>::check(const Line<T>& l) {
    // 判断点是否在直线上：y == kx + b
    return (y == l.k * x + l.b);
}

// 显式实例化（确保编译器生成 int 和 double 版本的代码）
template class Point<int>;
template class Point<double>;