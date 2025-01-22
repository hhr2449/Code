//构造函数是成员函数的一种，不能有返回值，可以有参数
//作用是对对象进行初始化
//生成一个对象的时候会自动调用构造函数，如果没有人为定义构造函数，编译器会自动生成无参数构造函数（什么都不干）
//一个类可以有多个构造函数
//!一个对象应该被初始化后再使用（就像之前强调的变量应该初始化再使用），如果不初始化，里面储存着未知的值，可能会出现未知的错误
#include<iostream>
using namespace std;
class Complex{
    private:
        double real,imag;
    public:
        Complex(double r,double i=0){//这里定义了一个构造函数，参数为r,i，其中i是缺省的
            real=r,imag=i;
        }
};
int main(){
    //*Complex c1;编译错误，因为没有给构造函数的参数
    Complex c2(1.2,2.3);
    Complex c3(1);//参数缺省
    Complex *c4=new Complex(1,2);//*利用动态分配内存时也需要调用构造函数
}
