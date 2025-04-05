#include "Factor.h"
//输入数据保证分母不为0，且均为正数
Factor::Factor(){};
Factor::~Factor(){};
//找最大公因数
//辗转相除法
//规定不出现0，数据经过过滤
int Factor::GetGcd(){
    int a=divident,b=divisor;
    if(a<b){
        swap(a,b);
    }
    int remider = a%b;
    while(remider!=0){
        a = b;
        b = remider;
        remider = a%b;
    }
    return b;

};
void Factor::simplify(){
    //提前过滤有0的情况
    if(divisor==0){
        isIllegal = true;
        return;
    }
    if(divident==0){
        divisor = 1;
        return;
    }
    //把最大公因数给除掉
    int gcd = GetGcd();
    divident /= gcd;
    divisor /= gcd;
};
Factor Factor::operator+(const Factor& f){
    Factor res;
    res.divisor = divisor*f.divisor;
    res.divident = divident*f.divisor+f.divident*divisor;
    res.simplify();
    return res;
};
Factor Factor::operator-(const Factor& f){
    Factor res;
    res.divident = divident-f.divident;
    res.divisor = divisor-f.divisor;
    res.simplify();
    return res;
};
Factor Factor::operator*(const Factor& f){
    Factor res;
    res.divident = divident*f.divident;
    res.divisor = divisor*f.divisor;
    res.simplify();
    return res;
};
Factor Factor::operator/(const Factor& f){
    Factor res;
    res.divident = divident*f.divisor;
    res.divisor = divisor*f.divident;
    res.simplify();
    return res;
};
bool Factor::operator<(const Factor& f){
    if(divident*f.divisor<f.divident*divisor){
        return true; 
    }
    else{
        return false;
    }
};
bool Factor::operator>(const Factor& f){
    if(divident*f.divisor>f.divident*divisor){
        return true; 
    }
    else{
        return false;
    }
};
bool Factor::operator==(const Factor& f){
    if(divident*f.divisor==f.divident*divisor){
        return true;
    }
    else{
        return false;
    }
};
istream& operator>>(istream& in,Factor& f){
    string str;
    in >> str;
    int pos = str.find('/');
    string str1 = str.substr(0,pos);
    string str2 = str.substr(pos+1,str.length()-pos-1);
    f.divident = stoi(str1);
    f.divisor = stoi(str2);
    return in;
};
ostream& operator<<(ostream& out,const Factor& f){
    if(f.isIllegal){
        out << "nan" ;
    }
    else{
        out << f.divident << '/' << f.divisor;
    }
    return out;
};

