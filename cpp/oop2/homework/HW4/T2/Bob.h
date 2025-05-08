#pragma once
#include "Robot.h"
class Bob : public Robot
{
    public:
        Bob (int k_) : Robot(k_) {}//注意派生类中的基类部分应该在初始化列表中通过调用基类的构造函数来初始化
        void add_part(Part p) {
            cnt++;
            ans += p.id*p.id;
        }
        friend ostream& operator<<(ostream& out, const  Bob& b);
};
ostream& operator<<(ostream& out, const  Bob& b){//注意左移运算符不能够使用成员函数重载，因为如果使用成员函数重载，那么调用形式就成了a << cout
    out << "Build robot Bob";
    return out;
} 