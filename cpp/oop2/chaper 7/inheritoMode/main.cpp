//继承方式：1.公共继承 2.保护继承 3.私有继承
//public成员：类内类外均可访问，protected成员：类内可以访问，类外不可以访问，private成员：类内可访问，类外不可访问
//public继承：public和protected都不变，protected继承：都变成protected，private继承：都变成private
//继承时private属性也被继承下来，但是会被隐藏，因此无法访问
#include<iostream>
using namespace std;
class base{
    public:
    int m_A;
    protected:
    int m_B;
    private:
    int m_C;
};
class son : public base{
    public:
    int m_D;

};
void test01(){
    son s;  
    cout << sizeof(s);
}
int main(){
    test01();
}