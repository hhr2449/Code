#include <iostream>
using namespace std;
class Person{
    public:
        int m_A;
       
};
Person operator+(const Person& p,const Person& p2){
    Person temp;   
    temp.m_A = p2.m_A + p.m_A;                            
    return temp;
 }
Person operator+(const Person& p,int num){//运算符重载也可以发生函数重载
    Person temp;   
    temp.m_A = p.m_A + num;                            
    return temp;
 }
void test01(){
    Person p1;
    p1.m_A = 10;

    Person p3 = p1 + 20;//实质是operator+(p1,20),实现了一个Person类型的对象与整型的相加
    cout << p3.m_A << endl;
}
int main (){
    test01();
}