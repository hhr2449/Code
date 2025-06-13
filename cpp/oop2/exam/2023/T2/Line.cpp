#pragma once
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Line{
    public:
        T k, b;
    Line(T k, T b = 0) {
        this->k = k;
        this->b = b;
    }
    bool intersect(const Line& l) {
        if(abs(k - l.k) < 1e-6 && abs(b - l.b) >= 1e-6) {
            return false;
        }
        return true;
    }
    void show() {
        cout << k << ',' << b << endl;
    }
    bool operator<(const Line& l) {
        return k < l.k;
    }
};