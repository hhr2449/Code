#include<iostream>
using namespace std;
int m=2,n=3;
int* getvalue1(){//返回了一个指针，这个指针指向m
    return &m;
}
int& getvalue2(){//返回了一个引用，这个引用指向n
    return n;
}
int main(){
    *getvalue1()=10;//这里getvalue1()相当于一个指针，指向m的地址，用*解引用，*getvalue1()就是m，所以m被赋值为10
    cout << m << ' ';
    getvalue2()=20;//这里getvalue2()是一个引用，指向n，因此n被赋值为20
    cout << n << ' ';
}