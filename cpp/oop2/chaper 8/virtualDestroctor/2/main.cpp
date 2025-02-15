#include <iostream>
#include <string>
using namespace std;
class Animal{
    public:
        string* m_Name;
        Animal(){
            cout << "Animal构造函数调用 " << '\n';
        }
        virtual void sound() = 0;
        virtual ~Animal(){
            cout << "Animal析构函数调用 " << '\n';

        }
};
class Cat:public Animal{
    public:
        Cat(string name){
            m_Name = new string(name);
            cout << "Cat构造函数调用 " << '\n';
        }
        void sound(){
            cout << *m_Name << "在叫" <<  '\n';
        }
        ~Cat(){
            cout << "Cat析构函数调用 " << '\n';
            if(m_Name != NULL){
                delete m_Name;
                m_Name = NULL;
            }
        }
};
void test01(){
    Animal *animal = new Cat("小花");
    //这里在堆上创建了Cat的对象，先调用父类构造函数，在调用子类构造函数，返回子类对象的地址，由父类指针animal接受
    //现在的内存结构是：栈区有一个Animal类型的指针animal，它指向堆区的一个Cat类型的对象
    //在这个Cat类型的对象里面有一个string类型的指针指向堆区的另一个内存区域
    animal->sound();
    //通过多态使用父类指针调用子类的成员函数
    delete animal;
    //这里将析构函数写成虚函数，这样调用析构函数是会使用多态，先调用Cat的虚构函数，再调用Animal的析构函数
}
int main(){
    test01();
}