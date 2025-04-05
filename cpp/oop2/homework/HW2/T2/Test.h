#pragma once

#include <iostream>

using namespace std;

class Test {
	int *buf;
	//类中维护了一个int类型的指针
public:
	//默认构造函数
	Test() {
		buf = new int(0);
		cout << "Test(): this->buf @ " << hex << buf << endl;
	}
	//有参构造函数
	Test(int val) {
		buf = new int(val);
		cout << "Test(int): this->buf @ " << hex << buf << endl;
	}
	//析构函数
	~Test() {
		cout << "~Test(): this->buf @ " << hex << buf << endl;
		//如果非空指针，则释放内存
		if (buf) delete buf;
		//最好释放完后要置空
	}
	//拷贝构造函数，在初始化列表中new一个内存，并将t的值放入内存中
	//深拷贝
	Test(const Test& t) : buf(new int(*t.buf)) {
		cout << "Test(const Test&) called. this->buf @ "
			<< hex << buf << endl;
	}
	//移动构造函数，直接将t指向的地址传给当前对象的buf，同时将t的buf置空，相当于直接抢占内存
	Test(Test&& t) : buf(t.buf) {//传的是右值
		cout << "Test(Test&&) called. this->buf @ "
			<< hex << buf << endl;
		t.buf = nullptr;
	}
	//拷贝赋值函数
	Test& operator= (const Test& right) {
		if (this != &right){//判断自指
			if(buf) delete buf;//判断空指针，同时释放内存（释放内存可以防止内存溢出）
			buf = new int(*right.buf);//new一个新的内存，将right的值放入内存中
		}
		return *this;
	}
	//移动赋值函数
	Test& operator= (Test&& right) {//注意传的是右值
		if (this != &right){
			if(buf) delete buf;
			this->buf = right.buf;//直接将right指向的地址传给当前对象的buf，同时将right的buf置空
			right.buf = nullptr;
		}
		return *this;
	}
	void print(const char *name) {
		cout << name << ".buf @ " << hex << buf << endl;
	}
};
//!指针使用要点：
//1. 空指针
//2. 自指
//3，悬垂指针
//4. 野指针
//养成习惯：1.使用指针时要判断是否为空指针
//2.涉及赋值的要判断是否自指
//3.释放指针后要置空
//4.定义时就要初始化



//如果传入一个右值，那么会调用移动
//如果传入一个左值，那么会调用拷贝
//像是：10,"string"这样的字面量，值类型的函数返回值，是右值，所以会调用移动构造函数，而不是拷贝构造函数
//变量和对象是左值，引用类型的函数返回值，是左值，所以会调用拷贝构造函数，而不是移动构造函数
//move(a)可以将原本是左值的a变成右值