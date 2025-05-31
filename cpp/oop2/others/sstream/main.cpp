#include <sstream>
#include <iostream>
using namespace std;
int main() {
    stringstream ss;
    //stringstream会维护一个buffer，使用<<将字符写入buffer（可以读入空格）,使用>>从buffer中读取字符（读到空格）
    ss << "10";
    ss << "0 200";
    ss << " 10";
    ss << ".1";
    int a, b;
    ss >> a >> b;//可以实现类型的转换
    cout << a << '\n';
    cout << b << '\n';
    double c;
    ss >> c;
    cout << c << '\n';
    cout << ss.str() << '\n';//ss.str()可以读取buffer中的所有内容
    //注意 >> 操作符不会使数据从buffer中删除，而是使buffer中的tail指针移动
}