#ifndef __COMPLEX__//防卫式声明一般这样写：__(2个下划线，不是1个)+头文件名的大写（不包括.h）+__(2个下划线，不是1个)，例如头文件为head.h时，就使用__HEAD__，这是为了防止重复。
#define __COMPLEX__//如果没有定义过complex，就定义一个complex，如果定义过了，就不再定义，防止重复包含
// class complex;

//0.前置声明




//1.类声明
class complex{//class head
              //class body  //body部分要思考类中应该有什么数据（成员变量），可能会用到什么函数（成员函数）




};




//2.类定义



// class complex;
#endif//防卫式编程，防止头文件重复包含