#include <iostream>
#include "MyXml.h"
#include "Parser.h"
#include "tinyxml2.h"
#include <chrono>
using namespace std;
using namespace MyXml;
using namespace tinyxml2;
void testMyXml() { 
    Parser parser;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 10000; i++) {
        Xml root = parser.parseFromFile("test2.xml");
    }
    auto end = std::chrono::high_resolution_clock::now();
    // 计算耗时（转换为毫秒）
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "MyXml " << "Time taken: " << duration.count() << " milliseconds" << std::endl;
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
    std::cout << "tinyxml2 " << "Time taken: " << duration.count() << " milliseconds" << std::endl;
}
int main() {
    testMyXml();
    testTinyXML2();
}
