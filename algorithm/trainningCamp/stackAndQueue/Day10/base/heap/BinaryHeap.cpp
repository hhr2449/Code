
#include "BinaryHeap.h"
#include <iostream>
#include <string>

// 测试整数类型的堆
void testIntHeap() {
    std::cout << "=== 测试整数堆 ===" << std::endl;
    
    // 测试最大堆（默认）
    std::cout << "\n--- 最大堆测试 ---" << std::endl;
    BinaryHeap<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.push(15);
    
    std::cout << "堆元素: ";
    maxHeap.printHeap();  // 预期: 30 10 20 5 15
    std::cout << "堆大小: " << maxHeap.size() << " (预期: 5)" << std::endl;
    std::cout << "堆顶元素: " << maxHeap.top() << " (预期: 30)" << std::endl;
    
    maxHeap.pop();
    std::cout << "弹出后堆元素: ";
    maxHeap.printHeap();  // 预期: 20 10 15 5
    std::cout << "弹出后堆顶: " << maxHeap.top() << " (预期: 20)" << std::endl;
    
    // 测试最小堆
    std::cout << "\n--- 最小堆测试 ---" << std::endl;
    BinaryHeap<int> minHeap([](const int& a, const int& b) { return a > b; });
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(15);
    
    std::cout << "堆元素: ";
    minHeap.printHeap();  // 预期: 5 10 20 30 15
    std::cout << "堆顶元素: " << minHeap.top() << " (预期: 5)" << std::endl;
    
    minHeap.pop();
    std::cout << "弹出后堆元素: ";
    minHeap.printHeap();  // 预期: 10 15 20 30
    std::cout << "弹出后堆顶: " << minHeap.top() << " (预期: 10)" << std::endl;
}

// 测试字符串类型的堆
void testStringHeap() {
    std::cout << "\n\n=== 测试字符串堆 ===" << std::endl;
    
    // 字符串最大堆（按字典序）
    std::cout << "\n--- 字符串最大堆（字典序） ---" << std::endl;
    BinaryHeap<std::string> strMaxHeap;
    strMaxHeap.push("apple");
    strMaxHeap.push("banana");
    strMaxHeap.push("cherry");
    strMaxHeap.push("date");
    
    std::cout << "堆元素: ";
    strMaxHeap.printHeap();  // 预期: date cherry banana apple
    std::cout << "堆顶元素: " << strMaxHeap.top() << " (预期: date)" << std::endl;
    
    // 字符串最小堆（按长度）
    std::cout << "\n--- 字符串最小堆（按长度） ---" << std::endl;
    auto lenComp = [](const std::string& a, const std::string& b) {
        return a.length() > b.length();  // 长度小的优先级高
    };
    BinaryHeap<std::string> strMinHeap(lenComp);
    strMinHeap.push("apple");    // 5
    strMinHeap.push("pear");     // 4
    strMinHeap.push("banana");   // 6
    strMinHeap.push("grape");    // 5
    strMinHeap.push("fig");      // 3
    
    std::cout << "堆元素: ";
    strMinHeap.printHeap();  // 预期: fig pear apple grape banana
    std::cout << "堆顶元素: " << strMinHeap.top() << " (预期: fig)" << std::endl;
}

// 测试边界情况
void testEdgeCases() {
    std::cout << "\n\n=== 测试边界情况 ===" << std::endl;
    
    // 测试空堆操作
    BinaryHeap<int> emptyHeap;
    std::cout << "空堆是否为空: " << (emptyHeap.empty() ? "是" : "否") << " (预期: 是)" << std::endl;
    std::cout << "测试空堆pop: ";
    try {
        emptyHeap.pop();
        std::cout << "未抛出异常（错误）" << std::endl;
    } catch (const char* e) {
        std::cout << "捕获异常: " << e << "（正确）" << std::endl;
    }
    
    // 测试单元素堆
    emptyHeap.push(100);
    std::cout << "单元素堆顶: " << emptyHeap.top() << " (预期: 100)" << std::endl;
    emptyHeap.pop();
    std::cout << "弹出后是否为空: " << (emptyHeap.empty() ? "是" : "否") << " (预期: 是)" << std::endl;
}

int main() {
    testIntHeap();
    testStringHeap();
    testEdgeCases();
    return 0;
}
    