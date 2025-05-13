#include <iostream>
#include <tuple>
#include <string>
using namespace std;
//可以使用tuple作为返回值来获取多返回值
tuple<int, double> f(int a) {
    return make_tuple(a,a/2.0);
}
int main() {
    auto t = make_tuple("abc", 12, 1.3, 'a');
    //使用make_tuple来创建tuple
    cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << ' ' << get<3>(t) << '\n';
    //使用get<i>(t)来获取tuple中的元素（i不能是变量）
    string s;
    int a;
    double b;
    char c;
    tie(s,a,b,c) = t;//使用tie函数来获取整个tuple中的元素
    cout << s << ' ' << a << ' ' << b << ' ' << c << '\n';
    tie(a, b) = f(7);
    cout << a << ' ' << b;
}