#pragma once
#include <iostream>

struct Node
{
private:
	static int createTimes, copyCreateTimes, moveCreateTimes, copyAssignTimes, moveAssignTimes, delTimes;
	//普通构造次数，拷贝构造次数，移动构造次数，拷贝赋值次数，移动赋值次数，析构次数
	int val;
public:	
	Node(int v = 0);
	//普通构造
	~Node();
	//析构
	Node(const Node &y);
	//拷贝构造
	Node(Node &&y);
	//移动构造
	Node& operator=(const Node &y);
	//拷贝赋值
	Node& operator=(Node &&y);
	//移动赋值
	friend std::istream& operator>>(std::istream& in, Node& x);
	friend std::ostream& operator<<(std::ostream& out, const Node& x);
	//重载输入输出
	static void outputResult();
	//输出结果
};
