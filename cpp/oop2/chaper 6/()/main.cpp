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
    cout << MyAdd()(10,20) << '\n';
}
int main(){
    test01();
}