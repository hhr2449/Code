#include<iostream>
using namespace std;
class C1{
    int a;
};
struct S1{
    int a;
};
int main(){
    C1 c1;
    S1 s1;
    //c1.a=1;//!编译错误，提示不可访问
    s1.a=1;
    cout << s1.a << endl;
    return 0;
}
//!class和struct的区别:class默认权限为private,struct默认权限为public