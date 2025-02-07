#include <iostream>
using namespace std;

// 基类 Animal
class Animal {
public:
    // 虚函数 sound，为不同的动物发声提供接口
    virtual void sound() const {
        cout << "Animal makes a sound" << endl;
    }
    
    // 虚析构函数确保子类对象被正确析构
     ~Animal() { 
        cout << "Animal destroyed" << endl; 
    }
};

// 派生类 Dog，继承自 Animal
class Dog : public Animal {
public:
    // 重写 sound 方法
    void sound() const override {
        cout << "Dog barks" << endl;
    }
    
    ~Dog() {
        cout << "Dog destroyed" << endl;
    }
};

// 派生类 Cat，继承自 Animal
class Cat : public Animal {
public:
    // 重写 sound 方法
    void sound() const override {
        cout << "Cat meows" << endl;
    }
    
    ~Cat() {
        cout << "Cat destroyed" << endl;
    }
};


void test02(){
    cout << "sizeof(Animal): " << sizeof(Animal) << endl;
    //输出类占用内存数，发现不写虚函数时只占一个字节，写了虚函数就占了8个字节
    //这个8个字节是由虚函数指针（vfptr）占用的
    //vfptr指向vftable（虚函数表），表内记录虚函数的地址
    //每一个包含虚函数的类都会有一个对应的vftable，vftable是一个储存虚函数地址的数组
    //每一个包含虚函数的对象都会有一个指向其vftable的指针vfptr

    //创建Animal对象时，布局为
// +-------------------+
// | vptr              |  -->  +-------------------+
// +-------------------+       | vtable for Animal |
//                             +-------------------+
//                             | 0: Animal::sound()|
//                             +-------------------+
    //派生类定义时，会先将Animal类中的虚函数表完全继承下来
    //在类的内部对虚函数进行重写，重写后的虚函数表会覆盖掉Animal类中的虚函数表

    //创建一个对象时，对象内的vfptr会指向该类对应的虚函数表
    //当通过基类指针或者引用来调用虚函数时，编译器会根据对象的vfptr查找虚函数表，并根据表中的地址调用函数

}
int main() {
    test02();

    return 0;
}