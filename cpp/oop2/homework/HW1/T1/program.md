1. 在命令行提示符下，以下哪个命令可以列出当前目录下的所有文件和文件夹，包括隐藏文件和文件夹？

   **A**. `ls -a`

   B. `ls -l`

   C. `ls -r`

   D. `ls -t`

   A ：ls -a会显示所有文件

1. 这段代码运行后，输出结果是什么？

```cpp
#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b ? a : b);//返回较大值
}

int main() {
    int i = 1;// i = 1
    int j = i++;// i++是后加，应该先执行j = i,再执行i++，
    //此时j = 1,i = 2
    cout << max(++j, i++) << endl;//先执行max(2，2)，再执行i++
    return 0;
}
```

A. 1

B. 2

C. 3

D. 4

1. 【多选】你正在为一个项目编译多个C++源文件 `main.cpp`, `helper.cpp`, 和 `utility.cpp`。你需要生成一个名为 `project` 的可执行文件。下列哪些命令序列可以正确完成编译过程？

   **A**. `g++ -o project main.cpp helper.cpp utility.cpp`

   **B**. `g++ main.cpp helper.cpp utility.cpp -o project`  //-o 加在前面还是后面都可以

   **C**. `g++ -c main.cpp helper.cpp utility.cpp && g++ -o project main.o helper.o utility.o`   //先编译，后链接，可以

   D. `g++ main.cpp -o project && g++ helper.cpp -o project && g++ utility.cpp -o project`

2. 下面哪一个选项是正确的？

```cpp
#include <iostream>  
using namespace std;  
  
#define SQUARE(x) ((x) * (x))  
  
inline int square(int x) {  
    return x * x;  
}  
  
int main() {  
    int a = 5;  
    int result1 = SQUARE(a + 1); // Line X  
    int result2 = square(a + 1); // Line Y  
  
    return 0;  
}  
```

A. Line X 和 Line Y 都会产生相同的汇编代码  <font color='red'>//函数和宏在汇编层面是不一样的</font>

B. Line X 和 Line Y 的执行结果不同

C. square函数不会被编译器内联化，因为它的复杂性超出了编译器的优化能力<font color='orange'>//没有超出，一般函数很长或者采用了循环，递归等复杂结构则不会内联化</font>

**D**. 宏定义SQUARE可能会产生非预期的副作用，而内联函数square不会<font color='orange'>  //内联是简单的替换</font>

1. 【多选】假设你有一个C++源代码文件 `test.cpp`，其中包含以下内容：

```none
#include <iostream>

using namespace std;

int main() {
    int a = 123;
    cout << "The value of a is: " << a << endl;
    return 0;
}
```

下面那条命令可以正确生成可执行文件？

**A**. `g++ -o test test.cpp`

**B**. `g++ test.cpp -o test`

C. `g++ -c test.cpp -o test`  <font color='red'>  //只编译，没有链接</font>

**D**. `g++ -o test.cpp test`

1. 【多选】关于构造函数和析构函数，阅读以下代码，并选出正确的说法（所有选项之间相互独立）：

```cpp
#include <iostream>

class Test {
public:
    int data = -1;
    Test() = default; // (A)  //缺省的构造函数
    Test(int dat){ // (B)  //有参构造函数
        this->data = dat; // (C)   //this指针指向的是当前调用函数的对象
    }
    ~Test(){ // (D)
        std::cout<<data;
    }
};

int main() {
    Test* t = new Test();//初始化对象指针
    delete t;//销毁对象指针
    return 0;
}
```

**A**. 如果将注释 `(A)` 所在的行删除，则该代码**无法**通过编译，原因是 `main` 函数中调用了未定义的缺省构造函数。 <font color='red'>如果定义了有参构造函数，则不会默认提供默认构造函数</font>

B. 如果将注释 `(B)` 所在的行改为 `Test(int dat = 2023){ // (B)`，则该代码**可以**通过编译，运行输出结果为 `-1`。<font color='red'>不能编译，缺省的有参和默认构造产生歧义</font>

**C**. 如果将注释 `(A)` 和 `(C)` 所在的行删除，并将注释 `(B)` 所在的行改为 `Test(int dat = 2023):data(dat){ // (B)`，<font color='red'>使用了初始化列表</font>则该代码**可以**通过编译，运行输出结果为 `2023`。

D. 如果将注释 `(D)` 所在的行改为 `~Test(int data = 0){ // (D)`，该代码**可以**通过编译，运行输出结果为 `0`。<font color='red'>析构函数不接受参数</font>

1. 关于类的构造函数和析构函数，以下哪个描述是错误的？

   A. 析构函数用于清理对象占用的资源。

   B. 一个类可以有多个析构函数。<font color='red'>//析构函数只有一个</font>

   C. 构造函数可以被重载。

   **D**. 析构函数在对象销毁时自动调用。

2. 考虑以下C++代码片段，关于运算符重载的描述中，哪一个是正确的？

```cpp
class Complex {  
public:  
    double real;  
    double imag;  

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}  

    // 运算符重载函数  
    Complex operator+(const Complex& rhs) const {  
        return Complex(real + rhs.real, imag + rhs.imag);  
    }  

    // 其他成员函数...  
};  

int main() {  
    Complex c1(1.0, 2.0);  
    Complex c2(3.0, 4.0);  
    Complex sum = c1 + c2; // 使用重载的+运算符  
    return 0;  
}
```

A. 运算符重载函数`operator+`必须返回指向新创建的`Complex`对象的指针。

**B**. 运算符重载函数`operator+`可以作为类的非成员函数实现。

C. 在`main`函数中，`c1 + c2`表达式会调用`Complex`类的默认构造函数。<font color='red'>有有参构造，不可能调用默认构造</font>

D. 重载的`operator+`函数改变了`+`运算符原有的语义。