#include <memory>
#include <iostream>
using namespace std;

int main() {
    unique_ptr<int> p1(new int(10));//创建unique_ptr
    //unique_ptr<int> p2 = p1;
    unique_ptr<int> p2 = move(p1);//!unique_ptr不能复制，只能移动
    int *p = p2.release();//使用release()释放所有权，将搜有权移交给指针p，此时p2为空
    cout << *p << endl;
    p2 = make_unique<int>(20);
    cout << p2.get() << '\n';
}