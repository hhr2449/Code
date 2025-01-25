#include<iostream>
using namespace std;
class Person{
    public:
    int m_A;
    mutable int m_B;
    //加上mutable 关键字修饰的成员变量，可以在常成员函数中修改,常对象中也可以修改
    Person()
    :m_A(0)
    ,m_B(0)
    {}
    void showPerson() const{
       // this=NULL;
       //this->m_A=10;
       this->m_B=10;
    }
    //!this指针的本质 Person* const this:是一个指针常量，一定指向调用成员函数的对象，指向不可以修改
    //函数后面加上const，相当于this指针成了const Person* const this，既是常量指针，又是指针常量，因此常函数不能修改成员变量
    void func(){

    }
};
void test01(){
    const Person p;//创建了一个常对象（需要初始化）
    //p.m_A=10;常对象不能修改
    p.m_B=10;//加了mutable关键字修改的成员变量可以修改
    p.showPerson();
    //p.func();常对象只能调用常函数（调用非常函数可能出现修改成员变量的矛盾）

}
int main(){

}