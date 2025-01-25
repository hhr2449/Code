//在成员变量和成员函数前加上关键字static都用同一份数据，表示是一个静态成员
//静态成员变量：1.所有对象共享同一个内存（）
              //2.编译阶段就分配内存
              //3.类内声明，类外初始化
#include<iostream>
using namespace std;
class Person{
    public:
    static int m_A;//类内声明静态成员变量
    private:
    static int m_B;//私有静态成员无法在类外访问
};

int Person::m_A = 100;//类外对成员变量进行初始化
//语法类似类外定义成员函数，要加上Perosn::表示是类内的
int Person::m_B = 200;

void test01(){
    Person p1;
    cout << "p1.m_A = " << p1.m_A << endl;
    Person p2;
    p2.m_A = 200;//所有对象的静态成员变量共享同一份数据，因此p1也随之改变
    cout << "p1.m_A = " << p1.m_A << endl;
}

void test02(){
    //静态成员变量不属于某一个成员，而是由该类下的所有成员共享
    //因此访问静态成员变有两种方式：
    //1.利用类名进行访问
    //2.利用对象进行访问

    Person::m_A = 300;
    cout << "Person::m_A = " << Person::m_A << '\n';
}

int main(){
    test01();
    cout << "-------------------------" << '\n';
    test02();
    return 0;
}