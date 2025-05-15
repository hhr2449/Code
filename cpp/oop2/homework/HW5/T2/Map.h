#pragma once
#include "Pair.h"

class Map{
    Pair * data;
    int sz;
public:
    Map(int n);
    // TODO
    int num = 1;
    int search(string target);
    int search(string target) const;
    int& operator[] (string key_);
    int operator[] (string key_) const;
    int size ();
    ~Map();
};