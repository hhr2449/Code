#pragma once
#include<iostream>
#include"point.h"//圆类的定义中用到了点类
using namespace std;
class circle{
    private:
    p p1;//圆心
    double r;//半径
    public:
    void init(double x_=0,double y_=0,double r_=0);
    void Judge(p p2);
};