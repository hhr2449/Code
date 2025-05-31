#include <iostream>
using namespace std;
void increase(int &x) {
    x++;
}
void decrease(int &x) {
    x--;
}
void test(void (* ptr) (int &)) {
    int x = 10;
    ptr(x);
    cout << x << '\n';
}
int main() {
    void (*ptr)(int &);// 函数指针
    int flag;
    cin >> flag;
    switch(flag) {
        case 1: ptr = increase;
            break;
        case 2: ptr = decrease;
            break;
    }
    int x = 10;
    ptr(x);//可以通过函数指针来调用其指向的函数
    cout << x << '\n';
    test(increase);//可以将函数名传入另一个函数，此时传递的就是函数指针
}