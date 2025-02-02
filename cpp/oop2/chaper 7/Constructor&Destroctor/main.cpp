#include<iostream>
using namespace std;
class Base{
    public:
    int m_A;
    protected:
    int m_B;
    private:
    int m_C;
    public:
    Base(){
        cout << "Base 构造" << '\n';
        m_A = 100;
        m_B = 200;
        m_C = 300;
    }
    ~Base(){
        cout << "Base 析构" << '\n';
    }
    void m_Func(){
        cout << "Base m_Func" << '\n';
    }
     void m_Func(int a){
        cout << "Base m_Func" << '\n';
    }
};
class Son : public Base{
    public:
    int m_D;
    int m_B;
    Son(){
        cout << "Son 构造" << '\n';
        m_D = 400;
        m_B = 2000;
    }
    ~Son(){
        cout << "Son 析构" << '\n';
    }
    friend void test01();
     void m_Func(){
        cout << "Son m_Func" << '\n';
    }
};
void test01(){
    Son s;
    cout << "s.m_A = " << s.m_A << '\n';//构造父类时初始化的数据同样也会被继承
    cout << "s.m_B = " << s.m_B << '\n';
    cout << "s.m_D = " << s.m_D << '\n';
    cout << "Son下的m_B = " << s.m_B << '\n';
    cout << "Base下的m_B = " << s.Base::m_B << '\n';
    s.m_B= 2;
    cout << "Son下的m_B = " << s.m_B << '\n';
    cout << "Base下的m_B = " << s.Base::m_B << '\n';
    s.Base::m_B= 200000;
    cout << "Son下的m_B = " << s.m_B << '\n';
    cout << "Base下的m_B = " << s.Base::m_B << '\n';
    //继承时允许父类和子类中同时存在同名的成员，两者相互独立,互不干扰
    // 如果子类中存在同名的成员，则子类中的同名成员优先使用，想要访问父类中的同名成员需要注明作用域
    s.m_Func();
    //s.m_Func(100);//如果存在同名函数，子类中的函数会直接将父类中的函数隐藏，就算有重载也没办法调用
    s.Base::m_Func();//加上作用域就可以访问了

}
int main(){
    test01();
}
//创建子类时，先构造父，再构造子，先销毁子，再销毁父