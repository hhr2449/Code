#pragma once
#include "weapon.hpp"

class WeaponSlot {
    Weapon* weapon;
    public:
        WeaponSlot(){
        }
        ~WeaponSlot(){
            delete weapon;
        }
        void create_weapon(int p){
            weapon = new Weapon(p);
        }
        void add_spell(int a){
            weapon->spells.push_back(a);
        }
        WeaponSlot& operator=(WeaponSlot&& other){
            if(this != &other){
                if(weapon) delete weapon;
                this->weapon = other.weapon;
                other.weapon = nullptr;
            }
            return *this;
        }
        WeaponSlot& operator=(const WeaponSlot& other){
            if(this != &other){
                if(weapon) delete weapon;
                this->weapon = new Weapon(other.weapon->penetration);
                for(int i=0;i<other.weapon->spells.size();i++){
                    if(other.weapon->spells[i]%2==0){
                        this->weapon->spells.push_back(other.weapon->spells[i]);
                    }
                }
            }
            return *this;
        }
        int calc_damage_typeA(int d){
            d-=weapon->penetration;
            if(d<0){
                d = 0;
            }
            int res = 0;
            int dam = 0;
            for(int i=0;i<weapon->spells.size();i++){
                dam = weapon->spells[i]-d;
                if(dam>0){
                    res+=dam;
                }
            }
            return res;
        }
        int calc_damage_typeB(){
            int d = 0;
            int d_i = 0;
            int res = 0;
            int dam = 0;
            for(int i=0;i<weapon->spells.size();i++){
                d_i = d - weapon->penetration;
                if(d_i<0){
                    d_i = 0;
                }
                dam = weapon->spells[i] - d_i;
                if(dam>0){
                    res+=dam;
                }
                d++;
            }
            return res;
        }
        int calc_damage_typeC(){
            int d = 0;
            int d_i = 0;
            int res = 0;
            int dam = 0;
            for(int i=0;i<weapon->spells.size();i++){
                d_i = d - weapon->penetration;
                if(d_i<0){
                    d_i = 0;
                }
                dam = weapon->spells[i] - d_i;
                if(dam>0){
                    if(dam%2==0){
                        res+=dam/2;
                    }
                    else{
                        res+=dam;
                        d++;
                    }
                }
            }
            return res;
        }
};