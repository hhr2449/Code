#include <iostream>
#include <string>

class myClass {
    public:
        int x, y;
        myClass(int x_, int y_) : x(x_), y(y_) {}
        bool operator <(const myClass &c) const {
            return x*x + y*y < c.x*c.x + c.y*c.y;
        }
        friend std::ostream& operator <<(std::ostream& out, const myClass &c);
};
std::ostream& operator<<(std::ostream& out, const myClass &c) {
    out << "(" << c.x << "," << c.y << ")" << ' ';
    return out;

}
int main() {
    //pair由两个元素组成，即pair类中有first,second两个成员变量
    std::pair<std::string, int> p1("pair1", 1);
    std::cout << p1.first << ' ' << p1.second << '\n';
    auto p2 = std::make_pair("pair2", 2);
    //make_pair()创建的是一个匿名对象，然后使用p2来接受这个匿名对象
    //使用make_pair创建pair对象，此时可以使用auto关键字来实现自动类型推导
    std::cout << p2.first << ' ' << p2.second << '\n';
    //std::cout << (p1 > p2) << '\n';   //pair重载了>运算符，可以进行比较，会首先比较first成员，如果first相等，则比较second成员
    //但是要求pair的成员变量支持比较运算符
    std::pair<myClass, int> p3(myClass(1, 2),3);
    auto p4 = std::make_pair(myClass(1, 2), 4);
    std::cout << p3.first << ' ' << p3.second << '\n';
    std::cout << p4.first << ' ' << p4.second << '\n';
    std::cout << (p3 < p4) << '\n';
}