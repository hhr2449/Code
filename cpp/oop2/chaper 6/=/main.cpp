//编译器会默认提供operator=，将所有属性值进行拷贝
//但是会引发深浅拷贝问题
#include<iostream>
using namespace std;
class Person{
    private:
        int* m_Age;
    public:
    Person(int age){
        m_Age = new int(age);
    }
    friend void test01();
    ~Person(){
        //释放堆区数据的规范
        if(m_Age != NULL){//确定不是空指针
            delete m_Age;//释放内存，防止内存泄漏
            m_Age = NULL;//防止野指针
        }
    }
    Person& operator= (const Person& p){
        if(this != &p){//防止自赋值(如果自赋值，下面会出现空指针解引用)
            if(m_Age != NULL){//如果指针非空，那么先释放内存，然后将指针置空
                delete m_Age;//这样做更规范，因为可能出现原本的m_Age指向的堆区内存无法容纳新的数据造成内存溢出。如果确认可以容纳，也可以直接覆盖旧的内存块
                m_Age= NULL;
             }
            m_Age = new int(*p.m_Age);
        }
        return *this;
    }
    
};
void test01(){
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p1 = p1;
    p1 = p2 = p3;//注意连等是右结合的
    //编译器默认提供=的重载//这个只是浅拷贝，两根指针指向同一个内存地址，会出现重复delete的错误
    //需要进行深拷贝
    cout << "p1的年龄为：" << *p1.m_Age << endl;
    cout << "p2的年龄为：" << *p2.m_Age << endl;
    cout << "p3的年龄为：" << *p3.m_Age << endl;
}
int main(){
    test01();
}