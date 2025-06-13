#pragma once
#include <list>
#include <memory>
#include <iostream>
class MyList//真实的数据储存在一个list里面，而MyList的对象储存指向对应list的指针和范围，范围为[left, right)
{
private:
	std::shared_ptr< std::list<int> > pt; // a pointer to the real container指向真实储存容器的指针
	std::list<int>::iterator left, right; // the position of slice is [left, right). 'left' is included, 'right' is excluded.

	std::list<int>::iterator forward(int pos) const{
		//返回从'left'开始，位置为'pos'的元素
		// count from 'left', find the element at position 'pos'.
		auto now = left;
		while(pos--) now++;
		return now;
	}

public:
	//构造函数，创建一个空的list，用pt指针指向新创建的list
	MyList(): pt(new std::list<int>()){

		left = pt->begin();
		right = pt->end();
		// Actually, left = right = pt->end(), because there is no element in the list.
	}

	void append(int i){
		//!本题的关键在于这里的处理，list在insert的时候会将指定的值插入到指定迭代器的前面一个，
		//!所以指定迭代器及其之后的迭代器的位置就会自动加一改变，而前面的则不会改变
		//!所以这里如果left == right，则插入之后left迭代器仍然和right迭代器相等，不会向前，因此要手动减去
		if(left == right) {
			left--;
		}
		pt->insert(right, i); //insert i just before 'right'. 'right' and 'left' will be still valid (because we use list, not vector).
		// DEBUG !! Why I can't insert i??
	}

	int& operator[](int pos) const{
		return *forward(pos); // access the element at the 'pos'
	}
	friend std::ostream& operator<<(std::ostream& out, const MyList& li);
	MyList operator()(int i, int j) {
		MyList tem;
		tem.pt = this->pt;
		tem.left = this->forward(i);
		tem.right = this->forward(j);
		return tem;
	}

};
std::ostream& operator<<(std::ostream& out, const MyList& li){
		out << "[";
		if (li.left != li.right){
			auto now = li.left;
			out << *now;
			now ++;
			for(; now != li.right; now++){
				out << "," << *now;
			}
		}
		out << "]";
		return out;
	}