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
        int vi;
        char vc;
        double vd;
        void *optr = nullptr;
    };
    bool own_f = false;

    operator int() const { return vi; }
    operator char() const { return vc; }
    operator double() const { return vd; }

    void operator= (int u_vi) {
        cout << "PyObject got a value" << endl;
        if (own_f && optr) {
            destroyObject<Test>(optr);
        }
        optr = nullptr;
        vi = u_vi;
    }

    void operator= (char u_vc) {
        cout << "PyObject got a value" << endl;
        if (own_f && optr) {
            destroyObject<Test>(optr);
        }
        optr = nullptr;
        vc = u_vc;
    }

    void operator= (double u_vd) {
        cout << "PyObject got a value" << endl;
        if (own_f && optr) {
            destroyObject<Test>(optr);
        }
        optr = nullptr;
        vd = u_vd;
    }

    template <typename T>
    PyObject& operator= (T *obj) {
        own_f = false;
        cout << "PyObject got a value" << endl;
        cout << "Borrowing" << endl;
        optr = obj;
        return *this;
    }

    template<typename T>
    PyObject& operator=(T& obj) {
        own_f = false;
        cout << "PyObject got a value" << endl;
        cout << "Borrowing" << endl;
        optr = &obj;
        return *this;
    }

    template <typename T>
    operator T&() const {
        return *static_cast<T*>(optr);  // 返回引用
    }
    
    
    template <typename T>
    void destroyObject(void* ptr) {
        delete static_cast<T*>(ptr);  // 删除对应类型的对象
    }

    template <typename T>
    PyObject& operator=(T&& obj) {
        if (own_f && optr) {  // 如果拥有对象，释放旧的
            destroyObject<T>(optr);
        }
        cout << "PyObject got a value" << endl;
        optr = new T(std::move(obj));  // 移动构造
        own_f = true;
        
        cout << "Owning" << endl;
        return *this;
    }
    
    ~PyObject() {
        if (own_f && optr) {
            destroyObject<Test>(optr);
        }
    }

    PyObject& operator=(PyObject* obj) { 
        optr = obj->optr;
        own_f = false;
        cout << "PyObject got a value" << endl;
        cout << "Borrowing" << endl;
        return *this;
    }
    PyObject& operator=(PyObject& obj) { 
        optr = obj.optr;
        own_f = false;
        cout << "PyObject got a value" << endl;
        cout << "Borrowing" << endl;
        return *this;
    }
};