#include<iostream>
using namespace std;    
int main(){//new的作用是在堆空间上分配一块内存，***其返回值是指向这块内存的指针***
    int *p=new int;//为p分配一个int大小的内存空间
    *p=5;
    cout << *p << ' ';
    int n;
    int *q=new int(n);//这里为q分配了n个int大小的内存空间，n的值允许是变量
    cin >> n;
    for(int i=0;i<n;i++){
        p[i]=i;
    }
    for(int i=0;i<n;i++){
        cout << p[i] << ' ';
    }
    cout << p[100];
}