#pragma once
#include"dragon.h"
#include"weapon.h"
class Ninja  {

    public:
    Dragon dragon;
    Weapon weapon;//注意权限，基类中的私有不能被派生类访问
    Ninja (string dragon_, string weapon_);
    void describe();
};