#include <iostream>
using namespace std;
class Base//基类
{
public:
    virtual void foo() {
        cout << "Base::foo()" << endl;
    }
    virtual void foo(int) {
        cout << "Base::foo(int)" << endl;
    }//两个虚函数，发生重载
    void bar() {}
};

class Derived1 : public Base
{
public:
    void foo() {
        cout << "Derived1::foo()" << endl;
    }
    void foo(int) {
        cout << "Derived1::foo(int)" << endl;
    }//重写了两个虚函数
};

class Derived2 : public Base
{
public:
    void foo(float) {
        cout << "Derived2::foo(float)" << endl;
    } // (a)
    
};

int main()
{
    Derived1 d1;
    Derived2 d2;
    // d1.bar();  // (1)
    d2.foo(3.0);  // (2)
    Base *pb1 = &d1;
    Base *pb2 = &d2;
    pb1->foo(3);   // (3)
    pb2->foo(3.0); // (4)

    Base b1 = d1;
    b1.foo();     // (5)

    Derived2 *pd2 = &d2;
    pd2->foo(3.0); // (6)
    return 0;
}