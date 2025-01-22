#include"circle.h"
#include<cmath>

    void circle::init(double x_,double y_,double r_){//设置圆心和半径
        p1.init(x_,y_);//调用点类的成员函数来初始化
        r=r_;
    }
    void circle::Judge(p p2){//可以再圆的成员函数中进行判断，将点作为参数传入
        double dist=sqrt(pow(p2.Getx()-p1.Getx(),2)+pow(p2.Gety()-p1.Gety(),2));//获取距离
        if(dist<r){
            cout << "点在圆内" << '\n';
        }
        else if(dist==r){
            cout << "点在圆上" << '\n';
        }
        else{
            cout << "点在圆外" << '\n';
        }
    }
