#include<iostream>
#include<string>
using namespace std;
class Phone{
    public:
    string m_Brand;
    Phone(string brand) 
    : m_Brand(brand)
    {
        cout << "Phone 构造函数" << '\n';
    }
    ~Phone(){
        cout << "phone 析构函数" << '\n';
    }
};
class Person{
    public:
    string m_Name;
    Phone m_Phone;
    Person(string name, string brand) 
    : m_Name(name)
    , m_Phone(brand)
    {
        cout << "Person 构造函数调用" << '\n';
    }
    ~Person(){
        cout << "Person 析构函数" << '\n';
    }
    // Person(string name, string brand) {
    //     m_Name = name;
    //     m_Phone = Phone(brand);  // 创建一个新的 Phone 对象
    // }
    //!对比两种方式：
    // 1. 使用列表法初始化是直接将属性进行初始化
    // 2. 函数体内初始化则是先通过默认构造函数创建出一个变量，然后再赋值
    // 列表初始化更加高效，并且函数体初始化再初始化成员对象时因为成员对象已经有了有参构造，所以编译器不提供默认构造，出现编译错误

};
void test01(){
    Person p("张三","iPhone X");
}
//成员对象先构造，对象本身再构造，对象本身先析构，成员对象再析构
int main(){
    test01();
}