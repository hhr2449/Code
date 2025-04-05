#include <iostream>
#include "Test.h" 
#include "func.h" 

using namespace std;

int main()
{
	cout << "------entering main------" << endl;
	Test a;
	Test b;
	//创建对象a,b，调用默认构造函数，输出this->buf的地址
	cout << "------before call f1------" << endl;
	
	cout << "f1():" << endl;
	Test A = f1(a);
	//f1接受一个Test对象，返回一个Test对象

	//1.调用拷贝构造函数（传参）
	//2.print(a)
	//3.使用移动构造函数创建一个新对象
	//4.销毁两个对象（一个是传入的a的拷贝，一个是f1中的临时对象）
	
	cout << "------after f1 return------" << endl;
	
	cout << "------before call f2------" << endl;
	
	cout << "f2():" << endl;
	Test& B = f2(b);
	
	cout << "------after f2 return------" << endl;
	
	cout << "------before call f3------" << endl;
	
	cout << "f3():" << endl;
	f3(a, b);
	
	cout << "------after f3 return------" << endl;
	
	cout << "------exiting main------" << endl;
	system("pause");
	return 0;
}

