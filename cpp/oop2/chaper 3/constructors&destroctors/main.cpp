#include<iostream>
using namespace std;
class Person{
    public:
    Person(){
        cout << "Person 构造函数" << '\n';
    }
    ~Person(){
        cout << "Person 析构函数" << '\n';
    }
};
int main(){
    Person p;//创建对象，自动调用构造函数
    system("pause");//程序在这里停止，此时还没有调用析构函数
    return 0;//程序运行结束时对象销毁，调用析构函数
}