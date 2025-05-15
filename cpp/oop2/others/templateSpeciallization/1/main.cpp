//模板特化：某个模板可以适应一部分数据类型，但是对于某些数据类型，模板不能适应
//此时就可以对这些不能适应的数据类型进行模板特化，即采用特殊的方法来处理这些数据类型
//比如一个比较大小的函数，对于int,double等类型，可以直接比较，将其写成模板，但是这个模板就不能处理char*类型的比较
//此时就可以写一个针对char*类型的特化模板来单独处理
//函数匹配顺序：
//1.优先匹配普通函数
//2.如果普通函数没有匹配，再匹配最恰当的模板函数（可能会有重载）
//3.如果有特化版本，则优先匹配特化版本，否则使用普通模板
#include <iostream>
#include <cstring>
using namespace std;
//compare函数模板
template <class T> 
void compare(T& a, T& b) {
    cout << "using normal template" << '\n';
    if (a > b) {
        cout << a << " is greater than " << b << '\n';
    } else {
        cout << a << " is less than " << b << '\n';

    }
}
//特化的char*类型compare函数模板
template <>
void compare(char*& a, char*& b) {//!注意除了模板参数外，其余部分要保持一致（这里的参数不能写成char* a, char* b）
    cout << "using specialization" << '\n';
    if(strcmp(a, b) > 0) {
        cout << a << " is greater than " << b << '\n';
    } else {
        cout << a << " is less than " << b << '\n';

    }
}
int main() {
    int a = 10;
    int b = 20;
    compare(a, b);
    char* c = "hello";
    char* d = "world";
    compare(c, d);
}
