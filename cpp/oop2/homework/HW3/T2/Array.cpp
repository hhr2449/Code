#include "Array.h"
Array::Array (int len_) : len(len_) {
    node = new Node[len_];
}
Array::Array (const Array& other) {
    node = new Node[other.len];
    for(int i=0; i<other.len; i++){
        node[i] = other.node[i];
    }
}
Array::Array (Array&& other) {
    node = other.node;
    other.node = nullptr;
}
Array::~Array () {
    delete[] node;
}
Array& Array::operator= (const Array& other) {
    if(this == &other) {
        return *this;
    }
    if(this->node != nullptr){
        delete[] this->node;
    }
    node = new Node[other.len];
    for(int i = 0; i<other.len;i++){
        node[i] = other.node[i];
    }
    return *this;
}
Array& Array::operator= (Array&& other) {
    if(this == &other) {//防止自赋值
        return *this;
    }
    if(this->node != nullptr) {//防止内存泄漏
        delete[] node;
    }
    node = other.node;//直接将other中指针指向的地址赋值给当前的对象
    other.node = nullptr;//防止悬垂指针
    return *this;
}
Node& Array::operator[] (int index) {
    return this->node[index];
}
