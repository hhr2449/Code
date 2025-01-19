#include<iostream>
using namespace std;
int main(){
    int n=3;
    const int& r=n;//定义r为n的常量引用，r的类型为const int&;r是n的别名
    cout << r << ' ';
    n=4;
    cout << r << ' ';
   // r=2;会出现编译错误，const int&相当于既是常量指针又是指针常量，不能通过常量指针来间接改变
   int &m=n;
   const int &a1=m;
   const int &a2=n;
   const int &a3=9;//const int&类型可以通过常量，变量，引用类型进行初始化
   cout << a1 << ' ' << a2 << ' ' << a3 << ' ';


}