#include<iostream>
using namespace std;

class Person{
    public:
    int m_Age;
    void showClassName(){//可以发现类的空指针（不指向任何一个对象）也可以调用成员函数
        cout << "Person" << '\n';
    }
    void showPersonAge(){
        if(this==NULL){
            return;
        }
        cout << "Age: " << m_Age << '\n';//但是访问成员函数会报错
        //因为输出m_Age实际上是this->m_Age，但是由于指针p为NULL，所以this为NULL，所以this->m_Age为NULL，所以输出会报错
    }
};
void test01(){
    Person *p=NULL;
    p->showClassName();
    p->showPersonAge();
}
int main(){
    test01();
}