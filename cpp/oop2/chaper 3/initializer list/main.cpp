#include<iostream>
using namespace std;
class Person{
    public:
    int m_A,m_B,m_C;
    Person() :m_A(10),m_B(20),m_C(30)//直接利用列表初始化属性
    {
        cout << "Person 默认构造函数" << '\n';
        cout << "m_A = " << m_A << ", m_B = " << m_B << ", m_C = " << m_C << '\n';
    }
    Person(int a,int b,int c):m_A(a),m_B(b),m_C(c)//也可以传参数
    {
        cout << "Person 重载有参构造函数" << '\n';
        cout << "m_A = " << m_A << ", m_B = " << m_B << ", m_C = " << m_C << '\n';
    }
};
void test01(){
    Person p1;
    Person p2(30,20,10);

}
int main(){
    test01();
}