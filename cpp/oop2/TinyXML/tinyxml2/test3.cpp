#include "tinyxml2.h"
#include <iostream>
using namespace tinyxml2;
using namespace std;

// 递归遍历所有节点（包括注释、元素等）
void traverseXML(const XMLNode* node, int depth = 0) {
    if (!node) return;

    // 缩进表示层级
    for (int i = 0; i < depth; ++i) cout << "  ";

    // 处理不同类型节点
    if (auto element = node->ToElement()) {
        cout << "Element: <" << element->Name() << ">\n";

        // 打印属性
        const XMLAttribute* attr = element->FirstAttribute();
        while (attr) {
            for (int i = 0; i < depth + 1; ++i) cout << "  ";
            cout << "[Attribute] " << attr->Name() << " = " << attr->Value() << "\n";
            attr = attr->Next();
        }

        // 如果有文本节点
        if (const char* text = element->GetText()) {
            for (int i = 0; i < depth + 1; ++i) cout << "  ";
            cout << "[Text] " << text << "\n";
        }
    }
    else if (auto comment = node->ToComment()) {
        cout << "Comment: " << comment->Value() << "\n";
    }
    else if (auto decl = node->ToDeclaration()) {
        cout << "Declaration: " << decl->Value() << "\n";
    }
    else {
        cout << "Other Node Type: " << node->Value() << "\n";
    }

    // 递归访问子节点
    traverseXML(node->FirstChild(), depth + 1);
    // 继续访问兄弟节点（平级）
    traverseXML(node->NextSibling(), depth);
    //类似深度优先搜索
}

int main() {
    XMLDocument doc;
    XMLError result = doc.LoadFile("test3.xml"); 

    if (result != XML_SUCCESS) {
        cout << "Failed to load XML: " << doc.ErrorStr() << "\n";
        return -1;
    }

    cout << "=== XML Traversal Output ===\n";
    traverseXML(doc.RootElement());

    return 0;
}
