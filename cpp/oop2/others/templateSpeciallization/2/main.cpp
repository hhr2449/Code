#include <iostream>
using namespace std;

template<class T, class A>
T sum(const A& val1, const A& val2)
{
    cout << "using template" << endl;
    return T(val1 + val2);
}

template<class A>
int sum(const A& val1, const A& val2)
{   //不是部分特化，而是重载函数
    cout << "overload" << endl;
    return int(val1 + val2);
}
int main()
{
    float y = sum<float, float>(1.4, 2.4);
    cout << y << endl;
    int x = sum(1, 2);
    cout << x << endl;
    return 0;
}
