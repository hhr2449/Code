#include"ninja.h"
class IceNinja : public Ninja {
    public:
    IceNinja(string dragon_, string weapon_);
    void describe();
    void ice_power();
};