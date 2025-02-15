#include <iostream>
using namespace std;
class MakingBeverage{
    public:
        virtual void boil() = 0;
        virtual void brew() = 0;
        virtual void pourInCup() = 0;
        virtual void addSth() = 0;
        //四个纯虚函数分别表现制作饮品的四个抽象步骤
        void Make(){//这个函数用于展现制作的全过程
            boil();
            brew();
            pourInCup();
            addSth();
        }
    virtual ~MakingBeverage(){
        
    }
};
class Coffee:public MakingBeverage{
    public:
        void boil(){
            cout<<"把水煮沸"<<endl;
        }
        void brew(){
            cout<<"用沸水冲泡咖啡"<<endl;
        }
        void pourInCup(){
            cout<<"把咖啡倒进杯子"<<endl;
        }
        void addSth(){
            cout<<"加糖和牛奶"<<endl;
        }
        //对于四个步骤进行重写
};
class Tea:public MakingBeverage{
    public:
        void boil(){
            cout<<"把水煮沸"<<endl;
        }
        void brew(){
            cout<<"用沸水冲泡茶叶"<<endl;
        }
        void pourInCup(){
            cout<<"把茶倒进杯子"<<endl;
        }
        void addSth(){
            cout<<"加柠檬"<<endl;
        }
};
void doWork(MakingBeverage* a){
    a->Make();
}
//将调用类的方法的过程单独封装在一个函数中，简化调用的流程，并且在调用流程需要修改或者扩展时更加方便
int main(){
    MakingBeverage* a;
    a = new Coffee();
    doWork(a);
    a = new Tea();
    doWork(a);
    delete a;
}