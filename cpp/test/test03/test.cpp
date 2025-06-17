#include <bits/stdc++.h>
using namespace std;
int main() {
    string fileName = "test.xml";
    ifstream ifs(fileName);
    if(!ifs) {
        //如果没有打开文件，则抛出异常并且输出错误信息
        ostringstream info;
        info << "file not found!" << "fileName:" << fileName << '\n'; 
        throw runtime_error(info.str());
    }
    ostringstream buf;
    char ch;
    while(ifs.get(ch)) {
        buf << ch;
    }
    string Pstr = buf.str();
    cout << Pstr;
}