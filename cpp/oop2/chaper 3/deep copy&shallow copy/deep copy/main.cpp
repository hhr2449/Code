//深拷贝：重新申请一块堆空间的内存进行拷贝
#include<iostream>
using namespace std;
class Person{
    public:
    int m_Age;
    int *m_Height;
    Person (){
        cout << "Person 默认构造函数" << '\n';
    }
    Person(int age, int height){
        cout << "Person 有参构造函数" << '\n';
        m_Age=age;
        m_Height=new int(height);//这里在堆区申请了一块内存空间，并且放入height数据
        
    }
    Person(const Person &p){
        cout << "Person 的拷贝构造函数" <<'\n';
        m_Age=p.m_Age;
        m_Height=new int (*p.m_Height); //*深拷贝，重新申请一块内存空间进行拷贝，此时指针指向不一样，但是指向的内存空间中存的值一样
    }
    ~Person(){
        cout << "Person 析构函数" << '\n';
        if(m_Height!=NULL){//析构函数的作用：若是在堆区申请了内存需要释放（若只是在栈区使用内存，则写不写析构函数都一样）
            delete m_Height;//删除内存，防止内存泄漏
            m_Height=NULL;//防止野指针
            //规范：申请内存后，不用时应该将其销毁，并将指针指向NULL
        }
    }
};
void test01(){
    Person p1(10,180);//利用有参构造函数创建一个对象，里面含有一个int类型数据和一个int*类型数据
    Person p2(p1);//通过深拷贝创建p2，此时p2.m_Height中的地址值和p1.m_Height中的地址值不一样，但是存的值一样
}
int main(){
    test01();
}