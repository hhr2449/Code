//重载递增运算符
//比较前置递增和后置递增的底层实现：
//前置递增是直接对原数据进行操作，返回原数据的引用，因此可以实现链式调用
//后置递增是设置一个临时变量记录原数据的值，对原数据进行操作，返回临时变量的值，因此不能进行链式调用
//前置递增的性能更好一点
#include<iostream>
using namespace std;
class MyInteger{
    private:
    int MyInt;
    public:
    MyInteger(){
        MyInt = 0;
    }
    //重载前置++
    MyInteger& operator++(){
        ++MyInt;
        return *this;//返回对原对象的引用
    }
    //重载后置++
    MyInteger operator++(int){
        MyInteger temp = *this;
        ++MyInt;
        return temp;//返回临时变量的值
    }

    friend ostream& operator<<(ostream& out ,const MyInteger& mi);//如果形参是MyInteger& mi，那么只能接受引用，不能接受值（一般的引用只能接受变量），改成常引用就可以接受值

};
ostream& operator<<(ostream& out ,const MyInteger& mi){
    out << "MyInt = " << mi.MyInt;
    return out;
}
void test01(){
    MyInteger mi;
    cout << mi << endl;
    cout << ++mi << endl;
    cout << mi++ << endl;
    cout << mi << endl;
}
int main(){
  test01();
}

//左值：可以取地址的对象是左值，如变量名，解引用的指针，一般可以进行赋值（在式子左边），const修饰后不可以赋值但是可以取地址
//右值：不可以取地址的对象是右值，如字面常量（10），临时变量

