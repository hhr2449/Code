//运算符重载：对已有的运算符进行重新定义，赋予其另一种功能，以适应不同的数据类型
//对内置的数据类型，编译器知道如何进行运算，如int a = 1,int b = 2,a + b=3;
//但是对于自定义的数据类型，编译器不知道如何进行运算，如一个类Person，定义两个对象Person p1,Person p2,现在Person p3 = p1 + p2编译器不知道如何运算
#include <iostream>
using namespace std;
class Person{
    public:
        int m_A;
        Person personAddPerson(const Person& p);
};
Person Person::personAddPerson(const Person& p){//虽然不能直接用+实现两个对象的相加，但是可以定义一个成员函数得到相加的结果
    Person temp;                                //运算符重载实际上就是简化了这个函数的调用过程 Person p3 = p1.personAddPerson(p2);直接写成p1 + p2，即加运算符进行了重载
    temp.m_A = this->m_A + p.m_A;
    return temp;
 }
void test01(){
    Person p1;
    p1.m_A = 10;
    Person p2;
    p2.m_A = 20;
    Person p3 = p1.personAddPerson(p2);
    cout << p3.m_A << endl;
}
int main (){
    test01();
}