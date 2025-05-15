#include <iostream>
using namespace std;
class A {
    public:
    void func() const {
        cout << "func const" << '\n';
    }
    void func() {
        cout << "func normal" << '\n';
    }
};
int main() {
    A a;
    a.func();
    const A b;
    b.func();
}
//类中存在同一函数的常量与非常量重载
//对于常量对象，只能使用常量函数
//对于非常量对象，编译器会优先调用非常量版本的函数
//可以利用这一特性来实现非常量对象与常量对象的不同行为