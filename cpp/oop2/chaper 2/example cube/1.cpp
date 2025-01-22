//1.创建立方体类
//2.设置立方体属性
//3.设计行为，获取面积体积
//4.分别用全局函数和成员函数判断相等

#include<iostream>
using namespace std;
class Cube{
    public:
    Cube(int len_=0,int wid_=0,int high_=0){len=len_,wid=wid_,high=high_;}//构造函数
    private:
    int len,wid,high;//将数据作为私有属性隐藏起来，再设计函数作为借口设置和获取数据
    public:
    void SetLen(int len_){len=len_;}
    void SetWid(int wid_){wid=wid_;}
    void SetHigh(int high_){high=high_;}
    int GetLen(){return len;}
    int GetWid(){return wid;}
    int GetHigh(){return high;}//上面就是设置长宽高的函数接口
    //获取面积
    int CalculateS(){
        return 2*wid*len+2*len*high+2*wid*high;
    }
    int CalculateV(){
        return len*wid*high;
    }
    bool IsSame(Cube &c){//利用成员函数判断，只用将另外一个对象作为参数传入就行了
        if(len==c.GetLen()&&wid==c.GetWid()&&high==c.GetHigh())return true;//判断是否相等
        else return false;
    }
};
int main(){
    //Cube c1();//!一个错误：缺省不能把所有参数都缺省掉，这样编译器会把这个语句理解为一个函数的声明
    Cube c1(0);
    c1.SetLen(10);
    c1.SetWid(10);
    c1.SetHigh(10);//设置长宽高
    cout << "c1的面积为" << c1.CalculateS() << '\n';//获取面积
    cout << "c1的体积为" << c1.CalculateV() << '\n';
    Cube c2;
    c2.SetLen(10);
    c2.SetWid(10);
    c2.SetHigh(10);
    bool ret=c1.IsSame(c2);//判断c2是否和c1相等
    if(ret){
        cout << "c1和c2相等" << '\n';
    }
    else{
        cout << "c1和c2不相等" << '\n';
    }

    
    return 0;
}
