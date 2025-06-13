#include "Animal.h"
#pragma once
class Bird : public Animal{
    public:
        string color;
        Bird(int color_) {
            if(color_ == 0) {
                color = "Red";
            }
            else {
                color = "Blue";
            }
        }
        void swim() {
            cout << "Bird can not swim." << '\n';
        }
        void sing() {
            cout << color << " bird is singing." << '\n';
        }
        ~Bird() {
            cout << color << " bird is gone." << '\n';
        }
};