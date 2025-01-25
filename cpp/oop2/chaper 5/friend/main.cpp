//类中的私有成员只允许类中进行访问，如果想要其他类或者函数也能够访问私有成员，就需要设置友元
//全局函数做友元
//类做友元
//成员函数做友元
#include<string>
#include<iostream>
using namespace std;
class Building{
    private:
    string m_BedRoom = "卧室";
    public:
    string m_SittingRoom = "客厅";
    friend void goodFriend(Building*building);
    //这里将goodFriend设置为Building类的友元函数，可以访问私有属性
};
void goodFriend(Building*building){
    cout << "goodFriend在访问" << building->m_SittingRoom << '\n';
    cout << "goodFriend在访问" << building->m_BedRoom << '\n';
}
int main(){
    Building building;
    goodFriend(&building);
}