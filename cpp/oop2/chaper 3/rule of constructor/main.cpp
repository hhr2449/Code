// 默认（创建一个类，编译器自动提供）有三个函数：1.默认构造函数（空的），2.默认析构函数（空的），默认拷贝函数（对属性值进行拷贝）
//若是定义了有参构造函数，则不提供默认构造，但是还是提供默认拷贝
//如果定义了拷贝构造函数，则编译器不提供构造函数
#include<iostream>
using namespace std;
class Person{
    public:
    int m_Age;
    Person(){
        cout << "Person 默认构造函数" << '\n';
    }
    Person(int age){
        cout << "Person 有参构造函数" << '\n';
        m_Age=age;
    }
    Person (const Person &p){
        cout << "Perosn 的拷贝构造函数" << '\n';
        m_Age=p.m_Age;
    }
    ~Person(){
        cout << "Person 析构函数" << '\n';
    }
};
void test01(){
    Person p1(10);
    Person p2(p1);//查看输出发现p2的属性与p1相同，调用了两个析构函数，说明虽然没有写拷贝构造函数，但是编译器提供了默认的拷贝构造函数，将p1的属性值全部拷贝一份
    cout << "p2.m_Age = " << p2.m_Age << '\n';
}
void test02(){
    //Person p3;
    //!发生编译错误，提示没有可用的默认构造
}
void test03(){
    Person p3;
    Person p4(10);
}
int main(){
    test01();
}