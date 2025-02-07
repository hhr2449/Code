//堆区：由程序员控制其分配与释放，如果没有释放，则在程序运行结束时由操作系统自动释放
#include <iostream>
using namespace std;
// Function to allocate memory on the heap and return its address
int* func(){
    int *p = new int(10);
    //使用new关键字在堆区申请了一块内存，将数据10存放进去，返回该内存的地址，由p接受
    return p;
}
int main(){
    int *p = func();
    cout << *p << '\n';//由于是在堆区上面开辟的，所以函数结束后不会销毁
    delete p;
}