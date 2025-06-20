#include "tinyxml2.h"
#include <iostream>
using namespace tinyxml2;
using namespace std;

//!test3用于测试错误处理机制
void testError(const char* filename) {
    XMLDocument doc;
    XMLError result = doc.LoadFile(filename);

    if (result != XML_SUCCESS) {
        cout << "加载失败，错误码: " << result << endl;
        cout << "错误名称: " << doc.ErrorName() << endl;
        cout << "错误描述: " << doc.ErrorStr() << endl;
        cout << "错误所在行: " << doc.ErrorLineNum() << endl;
        doc.PrintError();
        return;
    } else {
        cout << "文档加载成功。" << endl;
    }

    // 清除错误状态（如需要重试或重新加载）
    doc.ClearError();
}

int main() {
    const char* filename = "invalid_config.xml";
    testError(filename);
    return 0;
}
