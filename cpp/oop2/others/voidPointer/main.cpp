#include <iostream>
using namespace std;
int main() {
    void* ptr;//void类型的指针可以指向任何类型的数据
    float x = 1.0;
    ptr = &x;
    cout << *((float*)ptr);//不能直接对void类型的指针进行解引用操作，必须进行显示的类型转换后再解引用
}