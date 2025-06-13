#include "Animal.h"
#pragma once
class Fish : public Animal{
    public:
        string color;
        Fish(int color_) {
            if(color_ == 0) {
                color = "Red";
            }
            else {
                color = "Blue";
            }
        }
        void sing() {
            cout << "Fish can not sing." << '\n';
        }
        void swim() {
            cout << color << " fish is swimming." << '\n';
        }
        ~Fish() {
            cout << color << " fish is gone." << '\n';
        }
};