#ifndef POINT
#define POINT
#include"Line.cpp"
#include<iostream>
using namespace std;
const double epslion = 1e-6;
template<typename T>
class Point{
    public:
    T x,y;
    Point(T x,T y):x(x),y(y){};
    void move(T dx,T dy){
        x+=dx;
        y+=dy;
    }
    void show(){
        cout << '(' << x << ',' << y << ')' << '\n';
    }
    bool check(Line<T> const& l){
        if(y-l.k*x+l.b<=epslion){
            return true;
        }
        else{
            return false;
        }
    }
};
#endif