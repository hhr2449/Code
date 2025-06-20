#include <iostream>
#include "MyXml.h"
#include "Parser.h"
#include "tinyxml2.h"
#include <chrono>
using namespace std;
using namespace MyXml;
using namespace tinyxml2;

//测试Xml类
void test1() {
    cout << "------------测试构造函数,设置获取name,content,attri等操作-------------" << endl;
    MyXml::Xml root("students");
    std::cout << root.getName() << std::endl;
    root.setName("DaMing");
    root.setContent("大明是日本的大名");
    std::cout << root.getName() << ' ' << root.getContent() << std::endl;
    root.setAttri("name", "DaMing");
    root.setAttri("age", "18");
    std::cout << root.getAttri("name") << ' ' << root.getAttri("age") << std::endl;
    cout << "------------测试序列化输出节点功能-------------" << endl;
    std::cout << root.output() << std::endl;
    cout << "------------测试添加子节点功能-------------" << endl;
    MyXml::Xml child("xiaoming");
    child.setContent("小明是大明的儿子");
    child.setAttri("name", "xiaoming");
    child.setAttri("age", "10");
    MyXml::Xml child2("xiaohong");
    child2.setContent("小红是大明的女儿");
    child2.setAttri("name", "xiaohong");
    child2.setAttri("age", "8");
    root.addChild(child);
    root.addChild(child2);
    MyXml::Xml grandChild("xiaomingchild");
    grandChild.setContent("小明是小明大明");
    grandChild.setAttri("name", "xiaomingchild");
    root[0].addChild(grandChild);//!注意XmlChild里面储存的是对象而非指针，所以这里修改child不会影响根节点（改变成储存指针是否更好？？？）
    std::cout << root.output() << std::endl;
    cout << "-------------测试通过下标访问节点----------------" << endl;
    std::cout << root[0].output() << std::endl;
    cout << "-----------------------------" << endl;
    std::cout << root["xiaoming"].output() << endl;
    cout << "---------------测试通过节点名访问节点--------------" <<endl;
    std::cout << root["xiaofang"].output() << endl; 
    cout << "-----------------------------" << endl;
    cout << root.output() << endl;
    cout << "--------------测试通过节点名移除节点---------------" << endl;
    root.rmChild("xiaofang");
    cout << root.output() << endl;
    cout << "--------------测试通过迭代器遍历节点---------------" << endl;
    for(auto it = root.begin(); it != root.end(); it++) {
        cout << it->output() << endl;
    }
    cout << "--------------测试通过下标遍历节点---------------" << endl;
    for(int i = 0; i < root.size(); i++) {
        cout << root[i].output() << endl;
    }
    cout << "-----------------------------" << endl;
}

//测试Parser(简单)
void test2() {
    Parser parser;
    Xml root = parser.parseFromFile("test1.xml");
    cout << root.output() << endl;
}
//测试Parser(复杂),同时获取用时
void test3() { 
    Parser parser;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 10000; i++) {
        Xml root = parser.parseFromFile("test2.xml");
    }
    auto end = std::chrono::high_resolution_clock::now();
    // 计算耗时（转换为毫秒）
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;
}
void testTinyXML2() {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i) {
        XMLDocument doc;
        doc.LoadFile("test2.xml"); // 解析 XML 文件
    }
    auto end = std::chrono::high_resolution_clock::now();
    // 计算耗时（转换为毫秒）
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;
}
int main() {
    //test1();
    //test2();
    test3();
    testTinyXML2();
    //解析test2.xml 一万次大约用时2450ms.
}
