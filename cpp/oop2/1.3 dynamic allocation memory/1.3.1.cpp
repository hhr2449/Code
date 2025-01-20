#include<iostream>
using namespace std;    
int main(){//new的作用是在堆空间上分配一块内存，***其返回值是指向这块内存的指针***
    //T *p=new T(n);new创建一个n*sizeof(T)大小的内存空间，这个空间里面只允许存放T类型的数据，new返回一个指向这块内存空间的T*类型的指针
    int *p=new int;//为p分配一个int大小的内存空间
    *p=5;
    cout << *p << ' ';
    int n;
    cin >> n;
    int *q=new int[n];//这里为q分配了n个int大小的内存空间，n的值允许是变量
    for(int i=0;i<n;i++){
        q[i]=i;
    }
    for(int i=0;i<n;i++){
        cout << q[i] << ' ';
    }
    // cout << p[100];//这里可能会出现运行时错误，因为p[100]访问了未分配的内存空间
    int **a=new int*[n];//a是int**类型，new了一个int*类型的数组，数组的大小为n，a[i]就是一个int*类型的指针
    for(int i=0;i<n;i++){
        a[i]=new int[n];//a[i]是一个int*类型的指针，new了一个int类型的数组，数组的大小为n
    }//最终得到一个n*n的二维数组
    delete p;
    delete[] q;
    for(int i=0;i<n;i++){
        delete[] a[i];//释放一个动态数组要用delete[]
    }
    delete[] a;//用delete释放new出来的空间（不释放会导致可用空间越来越少）
    return 0;
}
