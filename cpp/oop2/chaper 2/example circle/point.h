#pragma once;
#include<iostream>
using namespace std;
class p{//点类
    private:
    double x,y;//将坐标属性设置为私有
    public:
    void init(double x_=0,double y_=0);
    int Getx();
    int Gety();
};
//在头文件中声明点类