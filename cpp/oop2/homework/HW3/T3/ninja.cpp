#include"ninja.h"
Ninja::Ninja(string dragon_, string weapon_) : dragon(dragon_),weapon(weapon_)//注意这里应该是初始化两个成员对象，而不是调用构造函数
{
}
void Ninja::describe() {
        std::cout << "Ninja is coming!\n";
        std::cout << "Ninja is with " << dragon.get_name() << " and " << weapon.get_name() << '.' << '\n';
}