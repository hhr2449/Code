//左移运算符为"<<"，通过左移运算符可以实现输出数据类型
//cout的本质：cout是ostream类中的一个对象，属于iostream库中，其成员函数重载了左移运算符，
//所以cout << a本质上应该写成cout.operator<<(a),其左移运算符函数进行了重载操作，可以实现int,char,string等数据类型的输出
//同时其返回了*this，所以可以实现链式调用，cout << a << b << c,实质上应该是cout.operator<<(a).operator<<(b).operator<<(c)
#include<iostream>
using namespace std;
class Person{
    private:
    int m_A,m_B;
    public:
    Person(int a,int b){
        m_A = a;
        m_B = b;
    }
    friend ostream& operator<<(ostream& cout,Person& p);//将其设置为友元，可以输出私有属性
};
//进行左移运算符重载，实际上就是要定义一个函数oprator<<,实现简化调用cout << p1的操作,可以展开为operator<<(cout,p1)
//!不利用成员函数进行<<运算符重载，因为那样就只能写成p1 << cout。
ostream& operator<<(ostream& cout,Person& p){//可以不写成cout，形参的名字可以任意取
    cout << "m_A = " << p.m_A << " m_B = " << p.m_B;//输出对象的属性（可以cout已经在库中定义的数据类型）
    return cout;//返回一个cout的引用
}
void test01(){
    Person p1(10,20);
    Person p2(30,40);
    cout << p1 << p2 << "你好，世界！" << ' ' << 10 << 1.11 << endl;
    //cout << p1是operator<<(cout,p1)的简化调用，其返回一个cout的引用，因此可以链式调用
} 
int main(){
    test01();
}