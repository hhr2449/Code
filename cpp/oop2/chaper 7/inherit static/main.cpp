//继承中同名静态成员的处理方式与非静态处理方式类似
#include<iostream>
using namespace std;
class Base{
    public:
    static int m_A;
    void func(){
        cout << "Base::func()" << '\n';
    }
};
int Base::m_A = 100;
class Son:public Base{
    public:
    static int m_A;
    void func(){
        cout << "Son::func()" << '\n';
    }
};
int Son::m_A = 200;

void test01(){
    cout << "Base::m_A = " << Base::m_A << '\n';
    cout << "Son::m_A = " << Son::m_A << '\n';
    cout << "Base::m_A = " << Base::m_A << '\n';//直接通过类名访问Base的静态成员变量
    cout << "Son::m_A = " << Son::m_A << '\n';//通过类名访问Son的静态成员变量
    cout << "Base::m_A = " << Son::Base::m_A << '\n';//通过Son的类名访问父类Base下的静态成员变量
    Son s;
    s.func();
    s.Base::func();
}

int main(){
    test01();

}