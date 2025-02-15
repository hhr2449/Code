//如果使用基类指针在堆区上开辟对象，那么在堆区销毁对象时会调用基类的析构函数而不是派生类的析构函数
//所以要将基类的析构函数写成虚函数或者纯虚函数
#include <iostream>
#include <string>
using namespace std;
class Animal{
    public:
        string* m_Name;
        Animal(){
            cout << "Animal构造函数调用 " << '\n';
        }
        //构造函数不能写成虚函数，因为选虚函数的实现依赖与vfptr和vftable，对象没有创建出来，自然没有这两个东西
        virtual void sound() = 0;
        ~Animal(){
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
            //因为m_Name指向堆区上的内存
            if(m_Name != NULL){//确认不是空指针
                delete m_Name;//delete
                m_Name = NULL;//置空，防止野指针
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
    //这里要delete掉堆上创建的对象，由于这个是Animal类型的指针，并且析构函数没有使用多态
    //所以这里delete的时候只会调用Animal的析构函数，而Cat的析构函数没有被调用
    //结果就是animal指向的Cat对象被释放掉了，但是Cat内的指针m_Name指向的内存空间没有被释放掉，导致内存泄漏
}
int main(){
    test01();
}