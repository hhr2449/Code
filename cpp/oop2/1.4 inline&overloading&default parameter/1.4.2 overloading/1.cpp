#include<iostream>
using namespace std;
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int max(double a,double b){
    if(a>b){
        return a;
    }
    return b;
}
int max(int a,int b,int c){
    return max(max(a,b),c);
}
//重载函数：函数名字相同，但是参数表不同，编译器会根据输入的参数来区分


// double max(double a,double b){
//     if(a>b){
//         return a;
//     }
//     return b;
// }注意不能出现名字和参数表相同，返回值不同的情况
int main(){
    max(1,2);
    max(1.1,2.2);
    max(1,2,3);//虽然函数名称相同，但是可以通过函数参数来区分
    //max(1,2.2)像这样有多种重载情况无法区分的就不行
    double a=1;
    double b=2;
    max(a,b);//或者可以用变量的类型来区分
}