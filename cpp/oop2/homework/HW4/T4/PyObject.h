#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <variant>
using namespace std;

class Simple;
class Test;

class PyObject {
public:
    union{
        int vari;
        char varc;
        double vard;
        void *ptr = nullptr;
    };
    bool isOwn = false;
    //使用void类型的指针，储存任意类型的数据

    // 类型转换运算符
    operator int() const { 
        return vari; 
    }


    operator char() const { 
        return varc;
     }


    operator double() const { 
        return vard;
     }


    template <typename T>
    operator T&() const {
        //将ptr转换为指定类型的指针，再解引用返回
        return *static_cast<T*>(ptr);//注意要使用static_cast，因为自定义的数据类型是不能通过编译器自动转换的
    }



    //!处理基本数据类型，此时接受输入数据的赋值版本，并对应储存
    void operator= (int vari) {
        cout << "PyObject got a value" << '\n';
        if (isOwn && ptr) {
            destroyObject<Test>(ptr);
        }
        ptr = nullptr;
        this->vari = vari;
    }


    void operator= (char varc) {
        cout << "PyObject got a value" << '\n';
        if (isOwn && ptr) {
            destroyObject<Test>(ptr);
        }
        ptr = nullptr;
        this->varc = varc;
    }



    void operator= (double vard) {
        cout << "PyObject got a value" << '\n';
        if (isOwn && ptr) {
            destroyObject<Test>(ptr);
        }
        ptr = nullptr;
        this->vard = vard;
    }

    //!储存自定义的数据类型，此时接受的是地址
    template <typename T>
    //重载赋值运算符，使用函数模板，将赋值号右边的变量的值放入ptr指向的空间
    PyObject& operator= (T *vart) {//直接接受指针
        isOwn = false;
        cout << "PyObject got a value" << '\n';
        cout << "Borrowing" << '\n';//!左值仅获得引用
        ptr = vart;//让ptr直接指向该对象的地址
        return *this;
    }
    template<typename T>
    PyObject& operator=(T& vart) {//直接将等号右边的对象的引用传入
        isOwn = false;
        cout << "PyObject got a value" << '\n';
        cout << "Borrowing" << '\n';//!左值仅获得引用
        ptr = &vart;//让ptr直接指向该对象的地址，实现直接保存对象的引用
        return *this;
    }



    template <typename T>
    PyObject& operator=(T&& vart) {
        if (isOwn && ptr) {
            destroyObject<T>(ptr);
        }
        cout << "PyObject got a value" << '\n';
        ptr = new T(std::move(vart));
        isOwn = true;
        cout << "Owning" << '\n';//!右值获得所有权
        return *this;
    }

    

    // PyObject相关赋值
    PyObject& operator=(PyObject* p) { 
        ptr = p->ptr;
        isOwn = false;
        cout << "PyObject got a value" << '\n';
        cout << "Borrowing" << '\n';
        return *this;
    }
    PyObject& operator=(PyObject& p) { 
        ptr = p.ptr;
        isOwn = false;
        cout << "PyObject got a value" << '\n';
        cout << "Borrowing" << '\n';
        return *this;
    }

    // 工具函数和析构
    template <typename T>
    void destroyObject(void* ptr) {
        delete static_cast<T*>(ptr);
    }
    ~PyObject() {
        if (isOwn && ptr) {
            destroyObject<Test>(ptr);
        }
    }
};