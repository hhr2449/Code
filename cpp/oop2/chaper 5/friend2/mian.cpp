//用类做友元

#include<iostream>
#include<string>
using namespace std;
class Building;//先声明Building类，因为后面GoodFriend类中需要维护一个Building类的指针
class GoodFriend{
    public:
    GoodFriend();
    void visit();
    Building* building;//维护一个Building类指针，是想要通过这个指针来访问Building类的成员变量（其实在visit中初始化一个Building类对象也行）
};

class Building{
    public:
    Building();
    string SittingRoom;
    private:
    string BedRoom;
    friend class GoodFriend;//声明GoodFriend类为本类的友元
};
Building::Building()
:SittingRoom("客厅")
,BedRoom("卧室")
{}
GoodFriend::GoodFriend(){
    building = new Building;//初始化该指针，此时会调用Building的构造函数来创建一个Building对象
}
void GoodFriend::visit(){
    cout << "GoodFriend正在访问" << building->SittingRoom << '\n';
    cout << "GoodFriend正在访问" << building->BedRoom << '\n';
}
void test01(){
    GoodFriend gf;
    gf.visit();
}
int main(){
    test01();
}
