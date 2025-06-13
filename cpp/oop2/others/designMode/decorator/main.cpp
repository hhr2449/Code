#include <iostream>
using namespace std;

//所有View的基类
class Component {
public:
	virtual ~Component() { }
	virtual void show() = 0;
};//!这是最初始的基类

//一个基本的TextView类
class Monitor: public Component {
public:
	void show() {
		cout << "Monitor show." << endl;
	}
};//!创建了一个可以实现部分功能的类
//装饰器的核心内涵在于用装饰器类整体包裹改动之前的类，以保留原来的全部接口
//在原来接口保留的基础上进行新功能扩充
//!-------------------------接下来希望通过装饰器来增加一些功能------------------------------
class Decorator : public Component {
   //这里一个基类指针可以让Decorator能够以递归的形式不断增加新功能
   //!每个装饰器有两个部分，一个是自己新增的功能，用虚函数addon()表示，另一部分是基类的指针，用于将已经有的部分给包裹进去
   Component* _component; 
public:
   Decorator(Component* component):
		_component(component){}
   virtual void addon() = 0;
   void show() {//!调用show()方法时，会调用本层装饰器的新增功能，然后通过指针来递归调用内层装饰器的show()方法
		addon();
		_component -> show();
   }
};
//包裹原Component并扩充边框
class Border : public Decorator {
public:
	Border(Component* component) : Decorator(component) { }//包裹原有部分
	void addon() { cout << "Bordered "; } //本层新增功能
};

//包裹原Component并扩充水平滚动条
class HScroll : public Decorator {
public:
	HScroll(Component* component): Decorator(component) { }
	void addon() { cout << "HScrolled "; }
};

//包裹原Component并扩充垂直滚动条
class VScroll : public Decorator {
public:
	VScroll(Component* component): Decorator(component) { }
	void addon() { cout << "VScrolled "; } 
};
int main(int argc, char** argv) {
	//基础的monitor
	Monitor monitor;
	//在基础textView上增加滚动条
	VScroll vs_Monitor(&monitor);
	//在增加垂直滚动条的基础上增加滚动横条
	HScroll hs_vs_Monitor(&vs_Monitor);
	//在增加水平与垂直滚动条之后增加边框
	Border b_hs_vs_Monitor(&hs_vs_Monitor);
	b_hs_vs_Monitor.show();
	return 0;
}
