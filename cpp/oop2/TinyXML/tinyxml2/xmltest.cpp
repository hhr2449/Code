#include <iostream>
#include "tinyxml2.h"
#include <chrono>
using namespace std;
using namespace tinyxml2;


void test3() { 
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 10000; i++) {
        XMLDocument xmlDoc;
  		xmlDoc.LoadFile("test2.xml");
		XMLElement* root = xmlDoc.RootElement();
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
    //解析test2.xml 一万次大约用时2450ms.
}