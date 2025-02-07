//静态多态：函数重载，运算符重载
//静态多态地址早绑定，编译时就可以确定函数调用的地址
//动态多态：派生类和虚函数实现运行时多态
//动态多态地址晚绑定，运行时才确定函数的地址

//基类指针或者引用是可以指向（引用）派生类的对象的
//虚函数可以实现动态绑定，也就是可以在子类中对虚函数进行重写，通过基类的指针或者引用来调用子类的虚函数
//这样在运行的时候就会根据对象的具体类型来调用对应的函数
//这样就使程序更具有拓展性，可以先定义抽象的基类作为接口，派生类来实现具体的功能

// 定义一个函数为虚函数，不代表函数为不被实现的函数。
// 定义他为虚函数是为了允许用基类的指针来调用子类的这个函数。
// 定义一个函数为纯虚函数，才代表函数没有被实现。
// 定义纯虚函数是为了实现一个接口，起到一个规范的作用，规范继承这个类的程序员必须实现这个函数。

// 使用多态的优势：
// 代码复用：通过基类指针或引用，可以操作不同类型的派生类对象，实现代码的复用。
// 扩展性：新增派生类时，不需要修改依赖于基类的代码，只需要确保新类正确重写了虚函数。
// 解耦：多态允许程序设计更加模块化，降低类之间的耦合度。


#include <iostream>
using namespace std;
class Pet{
    public:
        virtual void Sound(){
            cout << "宠物在叫" << '\n';
        }
        //设置了一个宠物基类，将叫声函数设置为虚函数
    virtual ~Pet(){
        cout << "销毁你的宠物" << '\n';
    }
    //析构函数设置为虚函数
    //! 析构函数无法写成虚函数
};
class Dog : public Pet{
    public:
        void Sound()override{//override表示重写基类的函数，保护性编程
            cout << "狗在叫" << '\n';
        }
        ~Dog()override{
            cout << "销毁你的狗" << '\n';

        }
};
class Cat : public Pet{
    public:
        void Sound()override{
            cout << "猫在叫" << '\n';
        }
        ~Cat()override{
            cout << "销毁你的猫" << '\n';

        }
};
class Pig : public Pet{
    public:
        void Sound()override{
            cout << "猪在叫" << '\n';
        }
        ~Pig()override{
            cout << "销毁你的猪" << '\n';

        }
};
//派生出三种具体的宠物类，将成员函数重写
// void test01(){
//     cout << "请选择你的宠物  1:狗  2:猫  3:猪" << '\n';
//     int choice;
//     cin >> choice;
//     switch (choice){
//         case 1:{
//             Dog dog;
//             dog.Sound();
//             break;
//         }
//         case 2:{
//             Cat cat;
//             cat.Sound();
//             break;
//         }
//         case 3:{
//             Pig pig;
//             pig.Sound();
//             break;
//         }        
//         default:{
//             cout << "请输入正确的数字" << '\n';
//             break;
//         }
//     }
// }
void test02(){
    cout << "请选择你的宠物  1:狗  2:猫  3:猪" << '\n';
    int choice;
    cin >> choice;
    Pet* petPtr;
    switch (choice){
        case 1:{
           petPtr = new Dog;
            break;
        }
        case 2:{
           petPtr = new Cat;
            break;
        }
        case 3:{
            petPtr = new Pig;
            break;
        }        
        default:{
            cout << "请输入正确的数字" << '\n';
            break;
        }
    }
    petPtr->Sound();
    delete petPtr;
}
//test02采用了动态多态的方法，采用基类的指针来调用派生类的成员函数，这样调用的过程只用写一份代码
//如果不用多态而是分开写三个独立的类，则调用的方式类似于test01，
//一方面需要些三个独立的调用代码，在行为简单的情况下差异不大，但是当行为更加复杂时，会使代码复杂度大大增加
//另一方面，如果以后需要增加一种新的宠物，则需要修改test01中的代码，而test02则只需要修改一个地方，即switch中的case语句。
int main(){
    //test01();
    test02();
}