#include <iostream>
using namespace std;
class Sample {
public:
	int v;
// 在此处补充你的代码
    Sample() : v(0){}
    Sample(int _v) : v(_v){}
    Sample(const Sample& s) {
        v = s.v + 2;
    } 
    void operator=(Sample s) {
        v = s.v - 2;
    }
};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
int main()
{
	Sample a(5);//有参构造函数   a.v = 5
	Sample b = a;//拷贝构造函数   b.v = 7;
	PrintAndDouble(b);//注意该函数采用值传递，所以传入的时候会调用拷贝构造函数创建一个b的副本o，此时b.v = 7,o.v = 9
	Sample c = 20;//有参构造函数   c.v = 20
	PrintAndDouble(c);//   c.v = 20,o.v = 22
	Sample d;
	d = a;//重载赋值运算符
	cout << d.v;
	return 0;
}