### 继承与组合中构造函数的写法
```cpp
#include <iostream>

class B {
public:
    B(int val) : b_val(val) {
        std::cout << "B constructed with " << val << std::endl;
    }
private:
    int b_val;
};

class C {
public:
    C(int val) : c_val(val) {
        std::cout << "C constructed with " << val << std::endl;
    }
private:
    int c_val;
};

class D {
public:
    D(int val) : d_val(val) {
        std::cout << "D constructed with " << val << std::endl;
    }
private:
    int d_val;
};

class E {
public:
    E(int val) : e_val(val) {
        std::cout << "E constructed with " << val << std::endl;
    }
private:
    int e_val;
};

class A : public B, public C {
public:
    // A的构造函数：先初始化基类B和C，再初始化成员D和E
    A(int b_val, int c_val, int d_val, int e_val) 
        : B(b_val), C(c_val), d(d_val), e(e_val) {
        std::cout << "A constructed" << std::endl;
    }

private:
    D d;
    E e;
};

int main() {
    A a(1, 2, 3, 4); // 构造顺序：B → C → D → E → A
    return 0;
}
```
派生类A要写自己的构造函数，同时在其构造函数的初始化列表中按照先后顺序来调用基类构造函数和成员对象的构造函数(如果派生类没有显式调用基类的构造函数，则默认调用基类的默认构造函数，如果基类没有默认构造函数，同时没有显示调用有参构造，则会出错)