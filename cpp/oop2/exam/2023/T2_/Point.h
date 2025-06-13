#ifndef POINT_H
#define POINT_H

template <typename T>
class Line; // 前向声明，因为 Point 需要用到 Line

template <typename T>
class Point {
public:
    Point(T x, T y); // 构造函数
    void move(T dx, T dy); // 移动点
    void show(); // 输出点坐标
    bool check(const Line<T>& l); // 判断点是否在直线上
    T x, y; // 坐标
};

#endif // POINT_H