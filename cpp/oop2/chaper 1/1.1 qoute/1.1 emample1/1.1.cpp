#include<iostream>
using namespace std;
void swap(int& a,int& b){//函数中的引用参数
    int t=a;
    a=b;
    b=t;
}
int main(){
    int n=7;
    cout << n << ' ';
    int& r=n;//定义r为n的引用，r的类型为int&;r是n的别名
    cout << r << ' ' << '\n';
    n=4;
    cout << r << ' ';
    r=2;
    cout << n << ' ';//n与r是完全等价的

    //引用的实质是指针常量，即int *const p = &n;，是一个指针类型的常量，其指向不可变
    //int& r2;//错误，引用必须初始化
    //引用确定后不能再改变，因为引用是一个常量（这里对r的操作被认为是通过r来间接改变n）
    //只能引用一个变量
    //之前函数利用引用传递参数实质上就是传递了一个指针常量进去

}