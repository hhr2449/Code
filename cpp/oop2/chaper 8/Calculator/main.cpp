#include<iostream>
using namespace std;
class AbstractCalculator{
        
    public:
        int num1,num2;
        virtual void GetNum(){
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
        }
        //Getnum函数是通用的，在基类中就写
        virtual int Calculate() = 0;
        //将Calculator函数设置为纯虚函数
        virtual ~AbstractCalculator(){
            
        }

};
//写一个抽象的计算器类，用作调用计算器的接口

class AddCalculator:public AbstractCalculator{
    public:
        int Calculate(){
            return num1 + num2;
        }
};
class SubCalculator:public AbstractCalculator{
    public:
        int Calculate(){
            return num1 - num2;
        }
};
class mutiCalculator:public AbstractCalculator{
    public:
        int Calculate(){
            return num1 * num2;
        }
};
class DivideCalculator:public AbstractCalculator{
    public:
        int Calculate(){
            if(num2 == 0){
                cout << "Divide by zero error" << '\n';
                return 0;
            }
            return num1 / num2;
        }
};
//派生出4个具体的计算器类，只需要重写Calculate函数

void test01(){
     int choice;
    AbstractCalculator *calculator;
    //通过基类指针来实现多态调用
    cout << "1.Add\n2.Sub\n3.Muti\n4.Divide\nEnter your choice: " << '\n';
    cin >> choice;
    switch(choice){
        case 1:
            calculator = new AddCalculator();
            calculator->GetNum();
            cout << "Addition: " << calculator->Calculate() << '\n';
            delete calculator;//需要虚析构函数才能通过基类指针删除派生类对象
            break;
        case 2:
            calculator = new SubCalculator();
            calculator->GetNum();
            cout << "Subtraction: " << calculator->Calculate() << '\n';
            delete calculator;
            break;
        case 3:
            calculator = new mutiCalculator();
            calculator->GetNum();
            cout << "Multiplication: " << calculator->Calculate() << '\n';
            delete calculator;
            break;
        case 4:
            calculator = new DivideCalculator();
            calculator->GetNum();
            cout << "Division: " << calculator->Calculate() << '\n';
            delete calculator;
            break;
    }
}



int main(){
   
    test01();
}