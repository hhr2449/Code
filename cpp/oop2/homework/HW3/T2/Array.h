#pragma once
#include"Node.h"
using namespace std;
class Array {
    private:
        Node* node;
        int len;
    public:
        Array (int len);
        Array (const Array& other);
        Array (Array&& other);
        ~Array ();
        Array& operator= (const Array& other);
        Array& operator= (Array&& other);
        Node& operator[] (int index);
};