#include<iostream>
using namespace std;
inline int max(int a,int b){//定义了一个内联函数
    if(a>b){                //内联函数在编译的时候会直接插入到调用的地方，而不是调用函数，从而节约函数调用的时间
        return a;
    }
        return b;
}
int main(){
    int n1,n2;
    cin >> n1 >> n2;
    cout << max(n1,n2) << endl;//比如这里，编译器会直接把max(n1,n2)替换成n1>n2?n1:n2，而不是发生调用
}
//但是内联函数会增大可执行代码的体积，所以代码量大，有递归或是循环的函数不适合使用内联函数
//inline仅仅是对编译器的建议，编译器不一定会采纳