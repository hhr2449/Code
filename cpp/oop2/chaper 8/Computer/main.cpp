#include<iostream>
using namespace std;
//三个零件的抽象类，作为调用接口
class CPU{
    public:
    virtual void calculate() = 0;
};
class videoCard{
    public:
    virtual void display() = 0;
};
class memory{
    public:
    virtual void store() = 0;
};

//派生出具体厂商的零件
class IntelCPU : public CPU{
    void calculate() override{
        cout << "IntelCPU calculate" << endl;
    }
};
class AMDCPU : public CPU{
    void calculate() override{
        cout << "AMDCPU calculate" << endl;
    }
};
class NvidiaVideoCard : public videoCard{
    void display() override{
        cout << "NvidiaVideoCard display" << endl;
    }
};
class ATIVideoCard : public videoCard{
    void display() override{
        cout << "ATIVideoCard display" << endl;
    }
};
class IntelMemory : public memory{
    void store() override{
        cout << "IntelMemory store" << endl;
    }
};
class KingstonMemory : public memory{
    void store() override{
        cout << "KingstonMemory store" << endl;
    }
};

class Computer{//具体的电脑类
    private:
    videoCard* m_vc;
    CPU* m_cpu;
    memory* m_mem;
    //使用的硬件是电脑的属性，通过抽象类的指针进行调用，使用构造函数来绑定具体的派生类
    public:
    Computer(videoCard* vc,CPU* cpu,memory* mem){
        m_vc = vc;
        m_cpu = cpu;
        m_mem = mem;
    }
    void work(){
        m_cpu->calculate();
        m_vc->display();
        m_mem->store();
    }
    ~Computer(){
        if(m_vc){
            delete m_vc;
            m_vc = nullptr;
        }
        if(m_cpu){
            delete m_cpu;
            m_cpu = nullptr;
        }
        if(m_mem){
            delete m_mem;
            m_mem = nullptr;
        }
    }
};
void test01(){
    IntelCPU* icpu = new IntelCPU();
    NvidiaVideoCard* avc = new NvidiaVideoCard();
    IntelMemory* amem = new IntelMemory();
    Computer* com = new Computer(avc,icpu,amem);
    com->work();  
    delete com;
}
int main(){
    test01();
}