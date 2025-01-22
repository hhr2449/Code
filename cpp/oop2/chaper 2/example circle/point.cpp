#include"point.h"
#include<iostream>
using namespace std;


    void p::init(double x_,double y_){//获取点坐标
        x=x_,y=y_;
    }
    int p::Getx(){return x;}
    int p::Gety(){return y;}//通过成员函数来获取数据
//在对应源文件中定义成员函数
//!注意在声明时指定缺省值，定义的时候不用指定缺省值