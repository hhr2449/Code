#pragma once
#include <bits/stdc++.h>
#include "Line.cpp"
using namespace std;
template <typename T>
class Point {
    public:
        T x, y;
        Point(T x, T y) {
            this->x = x;
            this->y = y;
        }
        void move(T dx, T dy) {
            x += dx;
            y += dy;
        }
        void show() {
            cout << '(' << x << ',' << y << ')' << endl;
        }
        bool check(Line<T> const& l) {
            if(abs(l.k*x + l.b - y) < 1e-6) {
                return true;
            }
            return false;
        }
};