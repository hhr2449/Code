#include"ice_ninja.h"

IceNinja::IceNinja(string dragon_, string weapon_) : Ninja(dragon_, weapon_) { }
void IceNinja::describe() {
    std::cout << "Ice ninja is coming!\n";
    std::cout << "Ice ninja is with " << dragon.get_name() << " and " << weapon.get_name() << '.' << '\n';
}
void IceNinja:: ice_power() {
    std::cout << "You will be the dust of frozen bones!" << '\n';
}