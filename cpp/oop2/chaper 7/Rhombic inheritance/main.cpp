//结构：b和c都继承了a，然后d有同时继承了b和c，形成了菱形的结构
//包括b继承了a，c同时继承了a和b也成为菱形继承
//此时a的成员在d中就会有两份，而且由于是分别从b和c继承过来的，两份成员地址不一样，相互独立
//冗余性：a中的成员只需要一份，现在却有两份，出现了浪费
//二义性：可能有一些属性是具有唯一性的（比如Person的id，name)，菱形继承中d就会具有两个，出现二义性
//不要设计出菱形继承，尽量不要使用多继承
#include<iostream>
#include<string>
using namespace std;
class Person{
    public:
    string m_name;
};
class Teacher:public Person{
    public:
    int m_id;
};
class Student:public Person{
    public:
    int m_num;
};
class Assistant:public Teacher,public Student{
    public:
    void func(){
        cout << "my name is " << Teacher::m_name << endl;
        cout << "my name is " << Student::m_name << endl;
    }
};
int main(){
    Assistant a;
    a.Teacher::m_name = "zhangsan";
    a.Student::m_name = "lisi";//名字数据应该是唯一的，菱形继承导致数据有两份，出现二义性
    a.func();
}