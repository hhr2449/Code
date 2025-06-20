#include "tinyxml2.h"
#include <iostream>

using namespace tinyxml2;
using namespace std;


//!test2用于测试读取外部xml文件并且解析的功能
void parseEnterpriseConfig(const char* filename) {
    XMLDocument doc;
    XMLError result = doc.LoadFile(filename);
    if (result != XML_SUCCESS) {
        cout << "加载失败，错误码: " << result << ", 错误描述: " << doc.ErrorStr() << endl;
        return;
    }

    // 获取根节点 <config:application>
    XMLElement* root = doc.RootElement();
    if (!root) {
        cout << "未找到根元素。" << endl;
        return;
    }

    cout << "根节点名: " << root->Name() << endl;

    // 解析 <system>
    XMLElement* system = root->FirstChildElement("system");
    if (system) {
        cout << "\n[System 配置]" << endl;
        cout << "环境: " << system->Attribute("config:env") << endl;

        XMLElement* database = system->FirstChildElement("database");
        if (database) {
            cout << "数据库类型: " << database->Attribute("config:type") << endl;
            XMLElement* primary = database->FirstChildElement("primary");
            if (primary) {
                cout << "主库地址: " << primary->Attribute("host")
                     << ", 端口: " << primary->Attribute("port") << endl;
            }
        }
    }

    // 解析 <sec:security>
    XMLElement* security = root->FirstChildElement("sec:security");
    if (security) {
        cout << "\n[Security 配置]" << endl;
        cout << "加密级别: " << security->Attribute("config:encryption-level") << endl;

        XMLElement* acl = security->FirstChildElement("sec:acl");
        if (acl) {
            for (XMLElement* role = acl->FirstChildElement("role"); role; role = role->NextSiblingElement("role")) {
                cout << "角色: " << role->Attribute("name")
                     << ", 权限: " << role->Attribute("permissions") << endl;
            }
        }
    }

    // 解析 <modules>/<payment-processor>
    XMLElement* modules = root->FirstChildElement("modules");
    if (modules) {
        XMLElement* pay = modules->FirstChildElement("payment-processor");
        if (pay) {
            cout << "\n[支付配置]" << endl;
            cout << "是否启用: " << pay->Attribute("config:active") << endl;

            XMLElement* stripe = pay->FirstChildElement("providers")->FirstChildElement("provider");
            if (stripe) {
                cout << "Stripe API 版本: " << stripe->Attribute("api-version") << endl;
                XMLElement* cred = stripe->FirstChildElement("credentials");
                if (cred) {
                    cout << "公钥: " << cred->Attribute("key-public") << endl;
                }
            }
        }
    }

    // 解析 <legacy>
    XMLElement* legacy = root->FirstChildElement("legacy");
    if (legacy) {
        cout << "\n[Legacy 系统]" << endl;
        cout << "兼容模式: " << legacy->Attribute("config:compatibility-mode") << endl;

        XMLElement* soap = legacy->FirstChildElement("soap-endpoint");
        if (soap) {
            cout << "WSDL 地址: " << soap->Attribute("wsdl-url") << endl;
        }
    }

    cout << "\n配置文件解析完成。" << endl;
}

int main() {
    const char* filename = "test2.xml";
    parseEnterpriseConfig(filename);
    return 0;
}
