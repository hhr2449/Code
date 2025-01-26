#include <iostream>
using namespace std;
class Person{
    public:
        int m_A;
        Person operator+(const Person& p);//将函数名改为operator+即可实现加号运算符重载
};
Person Person::operator+(const Person& p){
    Person temp;   
    temp.m_A = this->m_A + p.m_A;                            
    return temp;
 }
void test01(){
    Person p1;
    p1.m_A = 10;
    Person p2;
    p2.m_A = 20;
    Person p3 = p1 + p2;//实质是p1.operator+(p2)
    cout << p3.m_A << endl;
}
int main (){
    test01();
}