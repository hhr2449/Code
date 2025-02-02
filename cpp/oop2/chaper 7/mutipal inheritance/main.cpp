//最好不要出现多继承，因为可能产生二义性
#include<iostream>
using namespace std;
class Base1{
    
    public:
    int m_A;
    Base1(){
        m_A = 10;
        m_B = 20;
    }
    protected:
    int m_B;
};
class Base2{
    
    public:
    int m_A;
    Base2(){
        m_A = 100;
    }
};
class Son : public Base1,public Base2{
    public:
    int m_C;
    Son(){
        m_C = 1000;
    }
};

void test01(){
    Son s;
    cout << s.Base1::m_A << '\n';
    cout << s.Base2::m_A << '\n';//父类之间存在同名的成员，需要限定作用域进行区分
    cout << s.m_C << '\n';
}
int main(){
    test01();
}