#include <iostream>
#include <memory>
using namespace std;
class myClass {
    public:
    ~myClass() {
        cout << "myClass destroyed\n";
    }
};
void test(shared_ptr<myClass>& p) {
    shared_ptr<myClass> p2 = p;//另一个shared_ptr指向p指向的对象同一个
    cout << p2.use_count() << '\n';//2
}
int main() {
    shared_ptr<myClass> p(new myClass);
    //创建一个shared_ptr，指向一个新创建的myClass对象
    cout << p.use_count() << '\n';//1
    test(p);
    //出作用域后，p2销毁了，但是其指向的对象还没销毁
    cout << p.use_count() << '\n';
    //直到p也销毁了，才真正销毁了myClass对象
}
//shared_ptr适用于解决多个指针指向同一个对象的问题
//只有当指向这个对象的指针全部销毁（引用计数归0），才会真正销毁这个对象
//机制：引入辅助指针u_ptr，这个u_ptr才是真正指向对象的指针
//使用智能指针指向对象，实际上是指向这根辅助指针
//其维护一个成员变量count，记录有多少根智能指针指向辅助指针，只有count归0，才会销毁对象