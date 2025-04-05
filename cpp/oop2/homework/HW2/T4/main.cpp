#include <cstdio>
#include <vector>
#include "weapon_slot.hpp"

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<WeaponSlot> slots(n);
    //创建类对象和创建类指针的区别
    //创建类对象必须调用类的构造函数，而创建类指针则不需要调用构造函数，只有使用new运算符在栈上开辟内存时才会调用构造函数
    //!这里创建向量slots时，如果WeaponSlot类中直接维护一个Weapon对象，那么就需要调用构造函数，会编译错误，所以这里应该选择在WeaponSlot类中维护一个类指针
    //一个类中需要使用另一个类对象时，可以不直接创建类对象，而是使用类指针，这样将两个类的创建解耦，方便维护和使用

    while (m--) {
        int op, i, j, a, d, p;
        scanf("%d", &op);
        if (op == 0) {
            scanf("%d%d", &i, &p);
            slots[i].create_weapon(p);
        } else if (op == 1) {
            scanf("%d%d", &i, &a);
            slots[i].add_spell(a);
        } else if (op == 2) {
            scanf("%d%d", &i, &j);
            slots[j] = std::move(slots[i]);
        } else if (op == 3) {
            scanf("%d%d", &i, &j);
            slots[j] = slots[i];
        } else if (op == 4) {
            scanf("%d%d", &i, &d);
            printf("%d\n", slots[i].calc_damage_typeA(d));
        } else if (op == 5) {
            scanf("%d", &i);
            printf("%d\n", slots[i].calc_damage_typeB());
        } else if (op == 6) {
            scanf("%d", &i);
            printf("%d\n", slots[i].calc_damage_typeC());
        }
    }
    return 0;
}