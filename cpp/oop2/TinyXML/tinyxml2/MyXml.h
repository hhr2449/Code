#pragma once
#include <string>
#include <map>
#include <list>
#include <sstream>
#include <exception>
#include <iostream>
#include <algorithm>
using namespace std;
namespace MyXml{
    class Xml{//设计类：XML（就是XML中的节点）
        public:
            Xml();
            Xml(string name);
            Xml(char * name);
            Xml(const Xml & other);

            string getName() const;//获取节点的名称（注意不能够修改原数据，所以应该是常函数）
            void setName(const string & name);//设置节点的名称
            string getContent() const;
            void setContent(const string & content);

            string getAttri(const string & key); //获取节点的属性，输入属性名，获取属性值
            void setAttri(const string & key, const string & value);//设置属性
            void rmAttri(const string & key);//删除某一条属性

            string output() const; //序列化输出节点

            void addChild(const Xml & child);//添加子节点

            Xml & operator[](int index);//通过下标来访问子节点（注意返回引用，因为不希望产生复制）
            Xml & operator[](const string & name);//使用名称来访问子节点
            Xml & operator[](const char * name);//使用名称来访问子节点

            void rmChild(int index);
            void rmChild(const string & name);
            void rmChild(const char * name);//删除子节点

            Xml & operator=(const Xml & other);

            list<Xml>::iterator begin();//实现对子节点的相关操作(方便使用)
            list<Xml>::iterator end();
            list<Xml>::iterator erase(list<Xml>::iterator it);
            int size();
        private:
            string * XmlName;//节点名
            string * XmlContent;//节点的内容
            std::map<string, string> * XmlAttri;
            //节点的属性（注意节点的属性包含两个部分：属性名，属性值，
            //具有一一映射的关系，为了方便我们通过属性名来获取属性值，可以使用map来维护）
            std::list<Xml> * XmlChild;
            //XML中的数据储存具有树状结构，可能存在子节点，所以维护一个list来储存子节点
            //为了提高运行效率，避免复制时产生的开销，所以使用指针来维护成员数据
            //!使用指针时，记得考虑空指针，悬垂指针，内存泄漏等问题
            void clear();//用于释放节点的内存
            //!clear函数涉及内存的释放，如果操作不当，比如：
            //1.如果不调用rmChild函数而是直接对子节点进行删除，那么子节点仍然会留在父节点的list里面，导致遍历父节点时出错
            //所以考虑将clear函数设计为private，避免错误使用（初步）
    };
}