//!想要根据不同的make命令来决定主函数的执行，可以在make命令编译的时候加入一个宏定义，然后在主函数中根据宏定义来决定执行哪些函数。

#include<iostream>
#include"functions.h"
using namespace std;
int main(){
    int a , b;
    cin >> a >> b;
    #ifdef SUM     //!使用宏定义，如果定义了宏SUM，则执行下面的语句
    cout << custom_sum(a,b) << endl;
    #endif
    #ifdef DEBUG
    cout << custom_sum(a,b) << endl;
    #endif
    #ifdef MINUS
    cout << custom_sum(a,b) << endl;
    cout << custom_minus(a,b) << endl;
    #endif
    #ifdef PRODUCT
    cout << custom_sum(a,b) << endl;
    cout << custom_product(a,b) << endl;
    #endif
    #ifdef DIVIDE
    cout << custom_sum(a,b) << endl;
    cout << custom_divide(a,b) << endl;
    #endif

}