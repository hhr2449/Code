#include <stdio.h>
using namespace std;
//实现cout
class ostream {
    public:
    ostream& operator<<(const char* str) {
        printf("%s", str);
        return * this;//实现链式调用
    }
    ostream& operator<<(char c) {
        printf("%c", c);
        return * this;
    }
    //ostream类中拷贝构造函数，拷贝赋值函数都被显式删除，只保留一个全局的对象
    ostream(const ostream&) = delete;
    ostream() = default;
}cout;
//重载流运算符：
//ostream&(ostream&, const char*);参数和返回值都式ostream&而不是值，避免ostream类的复制
int main() {
    cout << "Hello" << ' ' << "world" << '\n';
    //先调用cout.operator<<("Hello"),打印Hello，返回*this（即cout）,然后再调用cout.operator<<(' '),
    //打印空格，返回*this（即cout）,然后再调用cout.operator<<('world'),打印world，返回*this（即cout）,
    //最后调用cout.operator<<('\n'),打印换行符，返回*this（即cout）
}