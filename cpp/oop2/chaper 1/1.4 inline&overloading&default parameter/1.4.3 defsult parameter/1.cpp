#include<iostream>
using namespace std;
void func(int a,int b=1,int c=2){//定义函数的时候可以让右边连续几个参数有缺省值，这样在没有传入参数的时候就会以缺省值替代

}
//void func2(int a=1,int b,int c=2);//注意一定是右边连续几个参数
int main(){
    func(1,2,3);
    func(1);
    func(1,2);
   // func(1,,2);传入参数的时候也只能省略右边连续的几个
}
//应用：已经写完函数并且调用了，想要增加新功能，需要多传几个参数，就可以声明为缺省，这样之前没有用到新参数的函数调用就不需要修改了