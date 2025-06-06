#include<iostream>
using namespace std;

class Person{
    public:
    int m_Age;
    void showClassName(){//可以发现类的空指针（不指向任何一个对象）也可以调用成员函数
        cout << "Person" << '\n';
    }
    //显示Person的年龄
    void showPersonAge(){
        //防御性编程：当有可能通过指针调用成员函数时，一定要检验this指针是否为NULL
        if(this==NULL){
            return;
        }
        //输出年龄信息
        cout << "Age: " << m_Age << '\n';
        //注释解释：这里实际上存在一个潜在的问题，如果this为NULL，那么访问m_Age时会引发解引用空指针的错误
        //但是访问成员函数会报错
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