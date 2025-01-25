//静态成员函数
//1.只能访问静态成员变量
//2.所有对象共享同一个函数
#include<iostream>
using namespace std;
class Person{
    public:
    static void func(){
        cout << "static void func 函数调用" << '\n';
        m_A=100;//静态成员函数可以访问静态成员变量
        //m_B=200;  静态成员函数不可以访问非静态成员变量
        //静态成员函数是所有对象共享的，在调用的时候并不区分是哪个对象调用这个函数，所以如果访问非静态变量就不知道应该访问哪个对象的变量
        //一般的成员函数虽然每个对象都可以使用，但是p1使用和p2使用是不一样的，但是静态成员函数是所有对象共有的，p1.func()和p2.func()是一样的,也可以直接通过类名进行调用
    }

    static int m_A;
    int m_B;
    private:
    static void func2(){

    }
};

int Person::m_A = 10;

void test01(){
    Person::func();
    Person p1;
    Person p2;
    p1.func();
    p2.func();
   // Person::func2();私有的不可以在类外访问
}
int main(){
    test01();
}