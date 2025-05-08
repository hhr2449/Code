#include <iostream>
#include "Alice.h"
#include "Bob.h"
#include "Part.h"

int main() {

    Alice* alice[100];
    Bob* bob[100];//储存A类和B类的指针

    int ma = 0;//A类数量
    std::cin >> ma;
    for (int i = 0; i < ma; ++i) {
        int k = 0;
        std::cin >> k;
        alice[i] = new Alice(k);//alice[i]指向一个A类对象，调用构造函数，输入参数k，代表需要的零件数量
    }

    int mb = 0;
    std::cin >> mb;
    for (int i = 0; i < mb; ++i) {
        int k = 0;
        std::cin >> k;
        bob[i] = new Bob(k);
    }

    int m = 0;
    std::cin >> m;//总零件数
    int a_i = 0;
    int b_i = 0;//表示当前A类和B类对象的下标（制造到哪个机器人了）
    for (int i = 0; i < m; ++i) {
        int p = 0, id = 0;//p代表零件分配给哪个机器人，id代表零件储存的数字
        std::cin >> p >> id;
        if (p == 0) {
            alice[a_i]->add_part(Part(id));//添加零件
            if (alice[a_i]->is_full()) {//判断是否完成
                std::cout << *(alice[a_i]) << " run: " << alice[a_i]->run() << std::endl;//输出结果
                a_i++;//开始制造下一个机器人
            }
        }
        else {
            bob[b_i]->add_part(Part(id));
            if (bob[b_i]->is_full()) {
                std::cout << *(bob[b_i]) << " run: " << bob[b_i]->run() << std::endl;
                b_i++;
            }
        }
    }

    for (int i = 0; i < ma; ++i) {
        delete alice[i];
    }
    for (int i = 0; i < mb; ++i) {
        delete bob[i];
    }

    return 0;
}