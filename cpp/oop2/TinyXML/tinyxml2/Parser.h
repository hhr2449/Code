#pragma once
#include "MyXml.h"
#include <fstream>
namespace MyXml {
    class Parser {
        private:
            string Pstr;
            int Pidx;
        public:
            //读取数据
            void readFromString(const string & content);
            void readFromFile(const string & fileName);
            //去除右边的空白字符(左边的可以不用删除，因为解析的时候会有getNextToken函数来获取第一个非空字符)
            //但是右边的空白字符会影响解析结果，如果有空白则会导致结束位置错误，所以要删除
            void trim();
            //将读取，解析的流程封装为一个方法，最后调用的时候用的就是者两个函数，解析xml文件并且返回一个Xml对象
            Xml parseFromString(const string & content);
            Xml parseFromFile(const string & fileName);
            char getNextToken();//获取下一个非空字符
            Xml parse();

            void parseXmlDeclaration();//处理当前Pidx指向的位置是一个头声明的情况
            void parseXmlComment();//处理当前Pidx指向的位置是一个注释的情况
            Xml parseXmlElement();//处理当前Pidx指向的位置是一个元素节点的情况 
            string getAttrKey();
            string getAttriValue();
    };
}