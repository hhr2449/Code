//拷贝构造函数的调用时机

//1.使用一个已经创建完毕的对象初始化一个新对象

//2.值传递的方式给函数参数传值

//!3.值方式返回局部对象
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
    Person(const Person& p){
        cout << "Person 拷贝构造函数" << '\n';
        m_Age=p.m_Age;
    }
    ~Person(){
        cout << "Person 析构函数" << '\n';
    }
};

//1.使用一个已经创建完毕的对象初始化一个新对象(最常用)

void test01(){
    Person p1(10);
    Person p2(p1);
    cout << "p2.m_Age = " << p2.m_Age << '\n';
}

void doWork(Person p){

}

//2.值传递的方式给函数参数传值

void test02(){
    Person p1(10);
    doWork(p1);//这里调用了拷贝构造函数
    //因为值传递的本质就是拷贝一个副本传递进入函数，这里就会调用拷贝构造函数
}

//!3.值方式返回局部对象
//!在比较新版本的编译器中，以值方式返回局部对象不会调用构造函数
// RVO 示例
// MyClass createTempObject() {
//     return MyClass();
// }

// NRVO 示例
// MyClass createNamedObject() {
//     MyClass obj;
//     return obj;
// }

//以值方式返回相当于拷贝创建一个临时对象，并将其返回
//以引用方式返回返回的是原来对象的引用


Person doWork02(){
    Person p(10);
    cout << (int*)&p << '\n';//返回局部对象的地址
    return p;
}

void test03(){
    Person p1 = doWork02();
    cout << (int*)&p1 << '\n';//返回局部对象的地址
}

int main(){
    test01();
    cout << "-------------------------" << '\n';
    test02();
    cout << "-------------------------" << '\n';
    test03();
    return 0;
}