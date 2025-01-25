//只有非静态的成员变量才是单独存储在对象的内存中
//对象占用的内存空间几位非静态成员变量占用的内存空间之和，如果没有非静态成员变量，那么就是1
#include<iostream>
using namespace std;
class Person{
    public:
    int m_A;
    static int m_B;
    void func(){

    }
};
void test01(){
    Person p;
    cout << "sizeof(Person) = " << sizeof(Person) << endl; // 1
    cout << "sizeof(p) = " << sizeof(p) << endl; // 1
    //空对象占用内存为1
    //分配1个字节的内存是为了区分空对象占内存的位置（创建了对象需要占用一定的内存来表示这个对象）
}
void test02(){
    Person p2;
    cout << "sizeof(p2) = " << sizeof(p2) << endl; // 现在占用4个字节，即为int m_A 所占的内存
}
void test03(){
    Person p3;
    cout << "sizeof(p3) = " << sizeof(p3) << endl; //仍然是4个字节，静态成员不占用对象的内存（是所有对象共有的）
}
void test04(){
    Person p4;
    cout << "sizeof(p4) " << sizeof(p4) << endl;
}
int main(){
    //test01();
    //test02();
    //test03();
    test04();
    return 0;
}