//this指针是隐含与每一个非静态成员函数内的指针，哪个对象调用了该成员函数,this指针就指向该对象的首地址，this指针的类型是当前类的指针类型
//1.解决形参和成员变量命名冲突问题
//2.利用return *this 返回当前对象本身
#include<iostream>
#include<string>
using namespace std;
class Person{
    public:
    int age;
    string m_Name;

    Person(int age){
        this->age=age; //成员变量age和形参重名，此时可以用this->age来访问成员变量（最好成员变量命名为m_Age）
    }
    Person& setName(string name){
        m_Name=name;
        return *this; //函数的类型是Person&，返回一个引用，*this就是当前调用成员函数的对象，即返回当前对象的引用
    }
    Person& addAge(const Person &p){
        this->age+=p.age;//当前对象加上p的年龄
        return *this; //函数的类型是Person&，返回一个引用，*this就是当前调用成员函数的对象，即返回当前对象的引用
    }
    Person addAge2(const Person &p){
        this->age+=p.age;
        return *this; 
    }

};
void test01(){
    Person p(10);
    cout << "p.age = " << p.age << endl;
}
void test02(){
    Person p1(10);
    Person p2(20);
    p1.setName("tom").addAge(p2).addAge(p2).addAge(p2);//链式调用
    //p1.setName("tom")返回p1的引用，该引用再去调用addAge函数，返回p1的引用，再去调用addAge函数，返回p1的引用...
    cout << p1.m_Name << "的年龄为" << p1.age << '\n';
}
void test03(){
    Person p1(10);
    Person p2(20);
    p1.setName("tom").addAge2(p2).addAge2(p2).addAge2(p2);
    //此时p1.setName("tom").addAge2(p2)返回的是p1的副本，后续是在副本上进行相加而不是原来的p1
    cout << p1.m_Name << "的年龄为" << p1.age << '\n';
}

int main(){
    test01();
    test02();
    test03();
    return 0;
}