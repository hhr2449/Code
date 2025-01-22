// class name{
//     private:
//     私有属性和函数：只能在成员函数内进行访问
//     pubilc：
//     公有属性和函数：可以在任何地方进行访问
//     protected:
//     保护属性和函数:只能在成员函数内访问//!区别：私有权限不可以被子继承，保护权限可以被子继承
// };
//如果写成员变量和函数时没有指定，则缺省的认为是私有
//在类的成员函数内，可以访问当前对象和同类其他对象的所有成员函数和成员变量
//在类的成员函数之外的地方只能访问共有成员
//*将属性和行为放在不同的权限下加以管理
#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

class CEmployee{
    private:
    char szname[30];//私有属性：名称
    void getsalary(){
        cout << salary;
    }
    public:
    int salary;//公有属性：工资
    void setname(char *name);//公有函数：设置姓名
    void getname(char *name);//公有函数：获取姓名
    void averagesalary(CEmployee e1,CEmployee e2);
};

void CEmployee::setname(char *name){
    strcpy(szname,name);//成员函数可以访问私有对象
}
void CEmployee::getname(char *name){
    strcpy(name,szname);
}

void CEmployee::averagesalary(CEmployee e1,CEmployee e2){
    salary=(e1.salary+e2.salary)/2;//同样可以访问同一类中的不同对象
}

class Person{
    public:
    string m_Name;
    protected:
    string m_Car;
    private:
    int m_Password;
    private:
    void Set(){
        m_Name="张三";
        m_Car="拖拉机";
        m_Password=123455;
    }
};

int main(){
    CEmployee e;
    //strcpy(e,tom1234);发生编译错误，因为szname是类的私有属性，不能再main函数中访问
    e.setname("tom1234");//但是可以调用成员函数来访问类的私有属性
    e.salary=10000;//公有属性可以直接访问
    //e.getsalary();编译错误，提示不可访问，因为这个函数是类的私有函数

    Person p1;
    p1.m_Name="李四";
    // p1.m_Car="本茨";//!编译错误，保护权限不可访问
    // p1.m_Password=12;//!编译错误，私有权限不可访问
    //p1.Set();//!编译错误，该函数是私有成员函数，不可访问


    return 0;
}
//!设置私有变量称为“隐藏”，目的是强制要求对成员变量的访问一定通过成员函数进行，这样一旦成员变量属性发生改变就只需要修改成员函数即可
//举例：比如想要改短szname的长度，如果设为公有成员的话就需要寻找所有访问的函数进行修改，可是设成私有的话只需要修改setname函数，加上一个验证即可