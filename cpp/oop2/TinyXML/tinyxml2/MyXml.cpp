#include "MyXml.h"
using namespace MyXml;
//!---------------构造函数----------------
Xml::Xml() : XmlName(nullptr), 
             XmlContent(nullptr),
             XmlChild(nullptr),
             XmlAttri(nullptr){
            //注意我们维护的是指针，所以构造函数中应该将其初始化为nullptr

}

Xml::Xml(string name) : XmlContent(nullptr),
                   XmlChild(nullptr),
                   XmlAttri(nullptr){
    XmlName = new string(name);
    //对于传入节点名称初始化，我们采用new string()
}

Xml::Xml(char * name) : XmlContent(nullptr),
                   XmlChild(nullptr),
                   XmlAttri(nullptr){
    XmlName = new string(name);

}

Xml::Xml(const Xml & other) {
    //因为数据都是指针，所以不进行深拷贝
    XmlName = other.XmlName;
    XmlContent = other.XmlContent;
    XmlChild = other.XmlChild;
    XmlAttri = other.XmlAttri;
}
//!--------------设置与获取--------------
string Xml::getName() const {
    if(XmlName == nullptr) {
        return "";
    }
    else {
        return *XmlName;
    }
}

void Xml::setName(const string & name) {
    if(XmlName != nullptr) {
        delete XmlName;
        XmlName = nullptr;
    }
    XmlName = new string(name);
}

string Xml::getContent() const {
    if(XmlContent == nullptr) {
        return "";
    }
    else {
        return *XmlContent;
    }
}

void Xml::setContent(const string & content) {
    if(XmlContent != nullptr) {
        delete XmlContent;
        XmlContent = nullptr;
    }
    XmlContent = new string(content);
}
/*
指针使用注意：
1.创建指针是要初始化
2.解引用时要检测空指针
3.更新指针指向区域的内容时要注意是否采用先delete再new的方法
4.每次delete前要检测空指针，后要将指针置空
*/

string Xml::getAttri(const string & key) {//通过属性名获取属性值
    if(XmlAttri == nullptr) {//如果指针为空则返回空串
        return "";
    }
    return (*XmlAttri)[key];//如果不为空可以直接通过key来访问map（注意如果key不存在也会返回空串）
}
void Xml::setAttri(const string & key, const string & value) {
    if(XmlAttri == nullptr) {//如果指针为空则需要先创建
        XmlAttri = new map<string, string>();
    }
    (*XmlAttri)[key] = value;
}

void Xml::rmAttri(const string & key) {
    if(XmlAttri == nullptr) {
        return;
    }
    (*XmlAttri).erase(key);
}

/*
序列化输出Xml节点：
考虑使用sstream流来输出，将预定的内容输入进缓冲区，最后通过str()函数以string的方式返回
思考一个节点是如何构成的？
首先会有标签，标签里面会有标签名（可以直接输出），标签属性（遍历XmlAttri）
如果有子节点，则需要将子节点输出（可以通过递归调用实现）
如果由content，需要输出content(直接输出)
最后标签闭合
*/
string Xml::output() const {
    stringstream ss;
    if (XmlName == nullptr) {
        //对于一个节点，可以没有属性，子节点，内容，唯独标签名是必须有的，所以需要检查
        throw std::logic_error("element name is empty");
    }
    ss << "<" << *XmlName;
    //输出属性
    if(XmlAttri != nullptr) {
        for(auto it = XmlAttri->begin(); it != XmlAttri->end(); ++it) {
            ss << " " << it->first << "=\"" << it->second << "\"";
        }
    }
    ss << ">";
    if(XmlChild != nullptr) {
        for(auto it = XmlChild->begin(); it != XmlChild->end(); it++) {
            ss << it->output();
        }
    }
    if(XmlContent != nullptr) {
        ss << *XmlContent;
    }
    ss << "</" << *XmlName << ">";
    return ss.str();
}

void Xml::addChild(const Xml & child) {
    if(XmlChild == nullptr) {
        XmlChild = new list<Xml>();
    }
    XmlChild->push_back(child);
}

Xml & Xml::operator[](int index) {//使用下标来访问子节点
    if(XmlChild == nullptr) {
        XmlChild = new list<Xml>();
    }
    if(index < 0 || index >= XmlChild->size()) {
        throw std::logic_error("index out of range");
    }
    auto it = XmlChild->begin();
    for(int i = 0; i < index; i++) {
        it++;
    }
    return *it;
}

Xml & Xml::operator[](const string & name) { //使用名称来访问子节点
    if(XmlChild == nullptr) {//如果为空则创建
        XmlChild = new list<Xml>();
    }
    for(auto it = XmlChild->begin(); it != XmlChild->end();  it++) {
        //遍历寻找
        if(it->getName() == name) {
            return *it;
        }
    }
    //如果找不到就创建对应子节点，然后加入（有点类似map的查询功能，如果没有找到就创建并加入）
    XmlChild->push_back(Xml(name));
    return XmlChild->back();
}

Xml & Xml::operator[](const char * name) { //使用名称来访问子节点
    if(XmlChild == nullptr) {
        XmlChild = new list<Xml>();
    }
    for(auto it = XmlChild->begin(); it != XmlChild->end();  it++) {
        if(it->getName() == name) {
            return *it;
        }
    }
    XmlChild->push_back(Xml(name));
    return XmlChild->back();
}


/*
!注意：list的erase方法在删除指针的时候只会删除指针本身，不会删除指针指向的内存，
!所以必须要写一个方法来对指针指向的内存进行清除，否则会内存泄漏
*/


//!注意：如果不调用rmChild函数而是直接对子节点进行删除，那么子节点仍然会留在父节点的list里面，导致遍历父节点时出错
void Xml::clear() {//!用于删除节点，防止内存泄漏
    if(XmlName != nullptr) {
        delete XmlName;
        XmlName = nullptr;//防止悬垂指针
    }
    if(XmlContent != nullptr) {
        delete XmlContent;
        XmlContent = nullptr;
    }
    if(XmlAttri != nullptr) {
        delete XmlAttri;
        XmlAttri = nullptr;
    }
    if(XmlChild != nullptr) {
        //!注意在释放包含指针的容器时，不能够直接delete，
        //!因为这样只会释放容器本身占据的内存，不会释放容器中的指针指向的内存，应该遍历容器进行释放
        for(auto it = XmlChild->begin(); it != XmlChild->end(); it++) {
            it->clear();
        }
        delete XmlChild;
        XmlChild = nullptr;
    }
}
void Xml::rmChild(int index) {
    if(XmlChild == nullptr) {
        return;
    }
    if(index < 0 || index >= XmlChild->size()) {
        return; 
    }
    auto it = XmlChild->begin();
    for(int i = 0; i < index; i++) {
        it++;
    }
    it->clear();
    XmlChild->erase(it);
    return;
}

/*
!注意：在调用erase函数后，迭代器it会失效，这时候如果对it使用自增会发生错误
!正确做法是使用it = XmlChild->erase(it);erase函数会返回后一个迭代器
*/
void Xml::rmChild(const string & name) {
    if(XmlChild == nullptr) {
        return;
    }
    for(auto it = XmlChild->begin(); it != XmlChild->end();) {
        if(it->getName() == name) {
            it->clear();
            it = XmlChild->erase(it);
        }
        else {
            it++;
        }
    }
}
void Xml::rmChild(const char * name) {
    if(XmlChild == nullptr) {
        return;
    }
    for(auto it = XmlChild->begin(); it != XmlChild->end();) {
        if(it->getName() == name) {
            it->clear();
            it = XmlChild->erase(it);
        }
        else {
            it++;
        }
    }
}


Xml & Xml::operator=(const Xml & other) {
    clear();
    XmlName = other.XmlName;
    XmlContent = other.XmlContent;
    XmlAttri = other.XmlAttri;
    XmlChild = other.XmlChild;
    return *this;
}

list<Xml>::iterator Xml::begin() {
    return XmlChild->begin();
}

list<Xml>::iterator Xml::end() {
    return XmlChild->end();
}

list<Xml>::iterator Xml::erase(list<Xml>::iterator it) {
    it->clear();
    return XmlChild->erase(it);
}

int Xml::size() {
    return XmlChild->size();
}