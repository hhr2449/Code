#include <iostream>
using namespace std;

int main()
{


    int * a[] = {//a[]是一个int*类型的数组，里面存的是指针
        nullptr, nullptr, new int, new int[10], new int
    };//new的返回值是T*，所以可以用于初始化指针数组
    
    *a[2] = 123;//a[2]解引用，说明a[2]指向一个int类型变量
    a[3][5] = 456;//a[3]是一个int类型数组
    if(!a[0]) {//nullptr相当于0
        cout << *a[2] << "," << a[3][5];
    }
    return 0;
}