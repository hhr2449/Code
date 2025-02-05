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
//Teacher和Student会分别维护一个vbptr（虚基类指针），这个指针指向的是vbtable（虚基类表）,表中会记录派生类对象到虚基类子对象的偏移量
//这样即使有多个路径继承了同一个虚基类，最终也只会有一个虚基类的实例存在，该虚基类的派生类会通过虚基类表的偏移量访问同一个虚基类子对象
//假设我创建一个Assistant对象a,a只会包含一个Person的子对象，而从Student和Teacher中继承过来的部分会分别维护一个虚基类指针，
//Student的虚基类指针会指向一个虚基类表，其中记录了Student子对象与Person子对象之间的偏移量，Teacher子对象同理





// Assistant 对象 a 的内存布局：
// +---------------------+
// | Teacher::vbptr      | -> 指向 Teacher 的 vbtable：Teacher子对象与Person子对象之间的偏移量
// +---------------------+
// | Teacher::m_id       |
// +---------------------+
// | Student::vbptr      | -> 指向 Student 的 vbtable：Student子对象与Person子对象之间的偏移量
// +---------------------+
// | Student::m_num      |
// +---------------------+
// | Person::m_name      |
// +---------------------+