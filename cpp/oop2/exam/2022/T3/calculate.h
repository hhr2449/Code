#pragma once
#include <bits/stdc++.h>
#define ll long long
using namespace std;
template <class T>
class calculate {
    public:
        T res;
        calculate(char expressionType,ll x_,ll y_,ll z_) {
            T x = x_, y = y_, z = z_;
            if(expressionType == 'A') {
                res = x*x + y*y + z*z;
            }
            else if(expressionType == 'B') {
                res = x*y+y/z-x*z;
            }
            else {
                T a = 2;
                T b = 1;
                T tem1 = y - a;
                T tem2 = z + b;
                T tem3 = 3;
                res = y*tem3*z-x*z/tem1-x*y/tem2;
            }
        }
        friend std::ostream& operator<<(std::ostream& out, const calculate& cal) {
            out << cal.res ;
            return out;
        }//!模板友元函数直接在类内定义就好，类外声明太麻烦了
};
