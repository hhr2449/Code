#ifndef LINE_H
#define LINE_H

template <typename T>
class Line {
public:
    Line(T k, T b); // 构造函数（k 和 b）
    Line(T k); // 构造函数（k，b 默认为 0）
    bool intersect(const Line<T>& other); // 判断是否相交
    void show(); // 输出直线方程
    bool operator<(const Line<T>& other) const; // 比较斜率
    T k, b; // 斜率和截距
};

#endif // LINE_H