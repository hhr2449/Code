#include"fire_ninja.h"
FireNinja::FireNinja(string dragon_, string weapon_): Ninja(dragon_, weapon_) {//注意这里应该调用基类的构造函数，而不是直接初始化基类的成员变量
    
}
void FireNinja::describe() {
    std::cout << "Fire ninja is coming!\n";
    std::cout << "Fire ninja is with " << dragon.get_name() << " and " << weapon.get_name() << '.' << '\n';
}
void FireNinja:: fire_power() {
    std::cout << "I will burn the night!" << '\n';
}