#include <iostream>
using namespace std;

class Base {
public:
    virtual void print() {
        cout << "Base class" << endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        cout << "Derived class" << endl;
    }
};

int main() {
    Base* base = new Base();
    Derived* derived = new Derived();

    Base* bp = dynamic_cast<Base*>(derived);
    //将derived转换为Base*类型，即向上类型转换
    Derived* dp = static_cast<Derived*>(base);
   //将base转换为Derived*类型，即向下类型转换
    bp->print();
    dp->print();

    delete base;
    delete derived;

    return 0;
}