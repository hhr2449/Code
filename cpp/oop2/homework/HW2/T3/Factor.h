#pragma once
#include <iostream>
#include <string>
using namespace std;
class Factor{
    int divident;//被除数
    int divisor;//除数
    bool isIllegal = false;//是否非法
    public:
    Factor();//构造函数，初始化divident和divisor，默认值为0和1，防止除数为0
    ~Factor();
    Factor operator+(const Factor& f);
    Factor operator-(const Factor& f);
    Factor operator*(const Factor& f);
    Factor operator/(const Factor& f);
    bool operator<(const Factor& f);
    bool operator>(const Factor& f);
    bool operator==(const Factor& f);
    int GetGcd();
    void simplify();
    friend istream& operator>>(istream& in,Factor& f);
    friend ostream& operator<<(ostream& out,const Factor& f);
};
istream& operator>>(istream& in,Factor& f);
ostream& operator<<(ostream& out,const Factor& f);