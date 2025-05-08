#pragma once
#include "Robot.h"
class Alice : public Robot
{
    public:
        Alice (int k_) : Robot(k_) {}//注意派生类中的基类部分应该在初始化列表中通过调用基类的构造函数来初始化
        void add_part(Part p) {
            cnt++;
            ans += p.id;
        }
     friend ostream& operator<<(ostream& out, const Alice& a);
};
ostream& operator<<(ostream& out, const Alice& a){
    out << "Build robot Alice";
    return out;
} 