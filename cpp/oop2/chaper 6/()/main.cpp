#include<iostream>
using namespace std;
class MyPrint{
   public:
      void operator()(string str){
        cout << str << '\n';
      }
};
class MyAdd{
    public:
    int operator()(int a, int b){
        return a + b;
    }
};
void test01(){
    MyPrint mp;
    mp("hello world");
    MyAdd ma;
    cout << ma(10,20) << '\n';
    cout << MyAdd()(10,20) << '\n';//MyAdd()是一个匿名对象，使用匿名对象调用仿函数
}
int main(){
    test01();
}