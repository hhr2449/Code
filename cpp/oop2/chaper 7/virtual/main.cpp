//使用虚基类和虚继承解决菱形继承问题（最好的解决方式是不要使用）
#include<iostream>
#include<string>
using namespace std;
class Person{
    public:
    string m_name;
};
class Teacher:public virtual Person{//类名前加上virtual关键字，变为虚继承，Person成为虚基类
    public:
    int m_id;
};
class Student:public virtual Person{
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
    a.func();
    a.Student::m_name = "lisi";
    a.func();
}