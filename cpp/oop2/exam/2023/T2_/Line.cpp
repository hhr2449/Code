#include "Line.h"
#include <cmath>
#include <iostream>

template <typename T>
Line<T>::Line(T k, T b) : k(k), b(b) {}

template <typename T>
Line<T>::Line(T k) : k(k), b(0) {}

template <typename T>
bool Line<T>::intersect(const Line<T>& other) {
    // 两条直线相交的条件：斜率不同或重合
    return (k != other.k) || (b == other.b);
}

template <typename T>
void Line<T>::show() {
    std::cout << k << "," << b << std::endl;
}

template <typename T>
bool Line<T>::operator<(const Line<T>& other) const {
    return k < other.k;
}

// 显式实例化（确保编译器生成 int 和 double 版本的代码）
template class Line<int>;
template class Line<double>;