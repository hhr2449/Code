#include<iostream>
using namespace std;    
void print(const int a[],const char* s){//函数中将参数设成常量指针，可以防止不小心修改指针所指向地方的值
   // *s="world";会编译错误，起到保护作用
    cout << s << ' ';
    cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ';//数组其实就是指针，也可以设成常量指针
    //a[0]=5;会编译错误，起到保护作用
    cout << '\n';


}
int main(){
    const double pi=3.14159;//定义一个常量
    //pi=3.14;hui出现编译错误，常量不可改变
    const char* p="tsinghua";//定义一个指向常量的指针
    //p[0]='d';会出现编译错误，常量不可改变
    int m,n;
    const int*a=&m;//定义一个常量指针
   // *a=5;会出现编译错误，不能通过常量指针来改变指向地址的变量的值
   m=5;//但是允许直接改变其指向的变量的值
   a=&n;//也可以改变a的指向
   const int b[4]={1,2,3,4};
    print(b,p);

}