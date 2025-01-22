#include<iostream>
using namespace std;
class location{
    private:
    int x,y;
    public:
    void init(int x_=0,int y_=0){
        x=x_,y=y_;
    }
    void value_x(int val=0){x=val;};
    int value_x(){return x;};
    void value_y(int val){y=val;};
    int value_y(){return y;};
};
int main(){
    location loc1,loc2;
    loc1.init();//这里参数缺省掉了
    loc2.init(1,2);
    //loc1.value_x();编译错误，因为参数缺省掉了分辨不出来
    loc1.value_x(3);
    cout << loc1.value_y();//这里实现了重载
}