//栈区：由编译器自动分配管理，用于存放函数的参数，局部变量等
//注意：函数调用结束时，栈区的数据会自动释放，所以不要返回局部变量的地址
#include <iostream>
using namespace std;
int* func(int b){//函数的参数同样也是放在栈区中
    int a = 10;//局部变量（在函数里面创建的变量）存放在栈区中
    return &b;
}
int main(){
    int* p = func(1);
    cout << *p << '\n';//栈区的数据在函数调用结束时自动释放，所以会报错
}