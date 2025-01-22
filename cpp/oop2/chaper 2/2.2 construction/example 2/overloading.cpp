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
