#include "operator.h"
#include "switch.h"

template <class T>
void runForIt();

int main(int argc, char const *argv[])
{
    string master_type;
    cin >> master_type;//输入待比较的数据类型
    if (master_type == "int")//根据数据类型选择不同的模板函数，从而创建出不同类型的类对象
        runForIt<int>();
    else if (master_type == "char")
        runForIt<char>();
    return 0;
}

template <class T>
void runForIt(){//创建对象并且执行
    MySwitch<T> mySwitch;
    int target, m, n;//target是操作对象（如果符合则对target进行操作），m是检验分支数，n是待比较的数值
    cin >> target >> m;

    void (*operators[6])(int&) = {guard, increment, decrement, doublew, neg, halve};
    //函数指针数组，用于存放函数指针 

    fori0n(i, m) {
        T flag; int op; bool shouldBreak;//添加分支：flag是待比较的数值，op是操作符，shouldBreak是是否跳出循环
        cin >> flag >> op >> shouldBreak;
        mySwitch.addCase(flag, operators[op], &target, shouldBreak);
    }

    cin >> n;
    fori0n(i, n) {
        T value;
        cin >> value;//输入数值
        mySwitch.execute(value);//执行switch操作
        cout << target << endl;//输出每次执行完后的target
    }
}

