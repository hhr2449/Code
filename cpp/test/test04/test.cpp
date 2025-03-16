#include<iostream>
using namespace std;
class Complex {  
	public:  
		double real;  
		double imag;  
	
		Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {
			cout << "Complex()" << endl;
		}  
	
		// 运算符重载函数  
		Complex operator+(const Complex& rhs) const {  
			return Complex(real + rhs.real, imag + rhs.imag);  
		}  
	
		// 其他成员函数...  
	};  
	
	int main() {  
		Complex c1(1.0, 2.0);  
		Complex c2(3.0, 4.0);  
		cout << "c1 = " << c1.real << " + " << c1.imag << "i" << endl;
		c1 + c2; // 使用重载的+运算符  
		return 0;  
	}