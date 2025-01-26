#include<iostream>
#include<string>
using namespace std;
class Building;
class GoodFriend{
    public:
    Building* building;
    void visit();//目标：让visit成为bulding的友元
    void visit2();
    GoodFriend();
    
};
class Building{
    public:
    Building();
    string SittingRoom;
    private:
    string BedRoom;
    friend void GoodFriend::visit();//声明该成员函数是友元（要注明作用域）
};
Building::Building(){
    SittingRoom = "客厅";
    BedRoom = "卧室";
}
GoodFriend::GoodFriend(){
    building = new Building();
}
void GoodFriend::visit(){
    cout << "GoodFriend 正在访问" << building->SittingRoom << '\n';
    cout << "GoodFriend 正在访问" << building->BedRoom << '\n';
}
void GoodFriend::visit2(){
    cout << "GoodFriend 正在访问" << building->SittingRoom << '\n';
    //cout << "GoodFriend 正在访问" << building->BedRoom << '\n';

}
void test01(){
    GoodFriend gf;
    gf.visit();
    gf.visit2();
}
int main(){
    test01();
}