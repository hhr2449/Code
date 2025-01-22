#include<iostream>
using namespace std;
class CRectangle{//定义了矩形类
    public:
    double len,wid;//成员变量（属性）：长，宽
    void init(double len_,double wid_);
    double CArea();
    double CPerimeter();//
};
void CRectangle::init(double len_,double wid_){//加上classes name::表示这是一个类的成员函数
        len=len_,wid=wid_;//成员函数可以只在定义类的时候声明，之后再定义
    }

double CRectangle::CArea(){
        return len * wid;
    }

 double CRectangle::CPerimeter(){
        return 2*(len+wid);
    }

void R(CRectangle &r){
    r.init(5,6);
     cout << r.CArea() << ' ' << r.CPerimeter() << '\n';
}


int main(){
    int len,wid;
    cin >> len >> wid;
    CRectangle r1,r2;//定义了两个对象r1,r2
    r1.init(len,wid);//注意这里输入的len和wid是全局变量，全局变量和成员变量允许重名，成员函数操作的是成员变量
    cout << r1.CArea() << ' ' << r1.CPerimeter() << '\n';
//方法1：对象名.成员名
    r1.len=3;
    r2.init(3,4);
//方法2：指针->成员名
    CRectangle*rr1,*rr2;
    rr1=&r1;
    rr2=&r2;
    rr1->len=3;
    rr2->init(3,4);
//方法3：引用名.成员名
    R(r1);//同样可以用引用传递对象，函数外被引用的对象也会随之改变
    cout << r1.CArea() << ' ' << r1.CPerimeter() << '\n';

}