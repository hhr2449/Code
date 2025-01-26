#include <iostream>
using namespace std;
class Person{
    public:
        int m_A;
       
};
Person operator+(const Person& p,const Person& p2){//使用全局函数进行运算符重载
    Person temp;   
    temp.m_A = p2.m_A + p.m_A;                            
    return temp;
 }
void test01(){
    Person p1;
    p1.m_A = 10;
    Person p2;
    p2.m_A = 20;
    Person p3 = p1 + p2;//实质是operator+(p1,p2)
    cout << p3.m_A << endl;
}
int main (){
    test01();
}