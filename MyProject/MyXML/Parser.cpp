#include "Parser.h"
using namespace MyXml;
using namespace std;


//去除右端空白
void Parser::trim() {
    auto it = find_if(Pstr.rbegin(), Pstr.rend(), [](char ch) {return !isspace(ch);});
    //rbegin()返回一个反向迭代器，指向最后一个字符，rend()返回一个反向迭代器，指向第一个字符
    //[](char x){return !isspace(ch);}是一个匿名函数，传入一个字符，如果字符非空则返回true
    //find_if(it1, it2, func)会搜索迭代器it1和it2之间的元素，返回一个迭代器指向第一个满足func的元素
    Pstr.erase(it.base(), Pstr.end());
    //base函数会返回反向迭代器对应位置的下一个位置的正向迭代器
    if(Pstr.back() != '>') {//验证格式，最后一个字符必须是>
        throw runtime_error("the format of xml is wrong!we expect a '>' in the end of xml file!");
    }
}

//输入文件名来读取xml文件
void Parser::readFromFile(const string & fileName) {
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
    Pstr = buf.str();
    Pidx = 0;
    trim();
}

//输入字符串来读取XML文件
void Parser::readFromString(const string & content) {
    Pstr = content;
    Pidx = 0;
    trim();
}

//将构造Parser对象，读取文件，解析并返回封装在一起，最后使用的时候直接调用这个函数即可
Xml Parser::parseFromFile(const string & fileName) { 
    Parser parser;//构造parser对象
    parser.readFromFile(fileName);//读取xml文件
    for(int i = 39; i < 45; i++) {
        cout << Pstr[i];
    }
    return parser.parse();//解析并返回xml对象
}

Xml Parser::parseFromString(const string & content) { 
    Parser parser;//构造parser对象
    parser.readFromString(content);//读取xml字符串
    return parser.parse();//解析并返回xml对象
}

char Parser::getNextToken() {//!获取下一个非空字符,注意如果当前字符非空则不变
    //如果当前Pidx指向的字符是空格并且没有超过范围，则继续获取下一个字符
    while (Pidx < Pstr.size()&&isspace(Pstr[Pidx])) {
        Pidx++;
    }
    if(Pidx >= Pstr.size()) {//超出范围之后报错
        throw "Parser error! the Pidx is out of range!";
    }
    return Pstr[Pidx];//返回当前字符
}

//parse()函数是解析的主流程，会将Parser对象中Pstr字符串中的xml字符串解析成xml对象
//该函数的功能是将当前Pidx的下一个头标签到尾标签的内容进行解析，返回这个完整的xml对象
Xml Parser::parse() {
    while(true) {
        char token = getNextToken();//获取下一个非空字符
        if(token != '<') {//注意获取到的下一个字符一定是'<',因为这个函数是解析完整节点的
            throw "Error: xml head tag expected";
        }
        if(Pidx + 4 < Pstr.size() && Pstr.compare(Pidx, 5, "<?xml") == 0) {//处理遇到头声明的情况
            parseXmlDeclaration();
        }
        else if(Pidx + 3 < Pstr.size() && Pstr.compare(Pidx, 4 ,"<!--") == 0) {//处理注释的情况
            parseXmlComment();
        }
        else if(Pidx + 1 < Pstr.size() && (isalpha(Pstr[Pidx + 1]) || Pstr[Pidx + 1] == '_')) {
            //处理遇到的是一个头标签的情况，这时候下一个字符应该是一个字母或者下划线
            //如果遇到的是一个标签，那么应该开始解析并且返回xml对象
            return parseXmlElement();//调用函数从当前遇到的头标签到其对应的尾标签之间的内容，并且返回该节点的Xml对象
        }
        else {//其余情况直接抛出错误
            throw "Error: Xml format error!";
        }
    }
}

//处理文件头声明
//不用处理，跳过即可
void Parser::parseXmlDeclaration() {
    auto it = Pstr.find("?>", Pidx);
    //str.find(sub, start, end)，该函数会返回目标子串在字符串中第一次出现的位置下标，而不是迭代器
    //从当前位置开始查找头声明的结束位置，以"?>"为结束标志
    if( it == string::npos) {//如果没有找到结束位置，则抛出错误
        throw "Error: xml declaration expecte end";
    }
    //找到结束位置，则将Pidx移动到结束位置的下一个位置
    Pidx = it + 2;
}

//处理文件注释
//同样跳过
void Parser::parseXmlComment() {
    auto it = Pstr.find("-->", Pidx);
    if( it == string::npos) {
        throw "Error: xml comment expect end";
    }
    Pidx = it + 3;
}

//处理当前遇到的节点
Xml Parser::parseXmlElement() {
    //以一个完整的节点作为单位进行解析，在开始标签处(以<+name为标志)创建element，
    //在结束处（以结束标签为标志）返回得到的element，如果有子节点就递归调用，并且push_back进XmlChild
    //重点理解一下关键点：
    //1.递归处理：xml是一个树状结构，所以当遇到子节点时要再次调用函数递归处理，类似深度优先
    //2.递归边界：当遇到结束标签时，返回当前节点，并结束递归
    Xml xml;
    //先将节点名保存下来
    Pidx++;//此时指向name的第一个字符
    int prepos = Pidx;//保存此时的位置，然后接下来将Pidx移动到name的末尾，这样两者之间就是name
    if(!(Pstr[Pidx] == '_' || (isalpha(Pstr[Pidx])))) {//检查节点名首字母是否符合要求
        throw "Invalid XML name";
    }
    Pidx++;
    //之后移动Pidx直到name的后一个字符
    while(Pidx < Pstr.size() && (Pstr[Pidx] == '_' ||
         (isalnum(Pstr[Pidx])) || Pstr[Pidx] == '-' || \
         Pstr[Pidx] == ':' || Pstr[Pidx] == '.' )) {
            
        Pidx++;
    }
    if(Pidx >= Pstr.size()) {
        throw "Invalid XML format";
    }
    xml.setName(Pstr.substr(prepos, Pidx - prepos)); 

    //!注意不能只考虑解析完name之后Pidx的情况
    //!<name >,<name>会使token指向 >
    //!<name/>会使token指向 /
    //!<name  Attribute=""> 会使token指向属性
    //!在循环过程中，解析完content后会将token指向 <
    while(Pidx < Pstr.size()) {
        char token = getNextToken();
        //!1.单标签
        if(token == '/') {
            if(Pidx >= Pstr.size() || Pstr[Pidx+1] != '>') {//检查格式
                throw "format error";
            }
            Pidx += 2;
            return xml;//当前节点全部解析完成，返回xml对象
        }
        else if(token == '<') {//!2. '<'
            //之后可能是注释，结束标签，子节点
            //!2.1处理结束标签
            if(Pstr[Pidx+1] == '/') {
                //需要检验结束标签的节点名与当前xml对象的节点名完全一致
                if(Pstr.compare(Pidx+2, xml.getName().size(), xml.getName()) != 0) {
                    throw "format error";
                }
                Pidx += xml.getName().size() + 2;//理想情况下应该指向 >
                if(Pstr[Pidx] != '>') {
                    throw "format error";
                }
                Pidx++;
                return xml;
            }
            else if(Pidx + 3 < Pstr.size() && Pstr.compare(Pidx + 1, 3, "!--") == 0) {//!2.2是注释的情况
                parseXmlComment();
            }
            else {//!2.3是子节点的情况
                xml.addChild(parse());//递归调用parse函数，返回子节点对象并且添加到xml对象中
                //注意递归中的getNextToken()函数不会改变Pidx，因为当前的字符是非空的
            }

        }
        else if(token == '>') {//!3. '>'
            //之后可能为内容，标签，注释
            //只需要处理内容，对于标签和注释可以直接continue到上一个情况处理
            Pidx++;//注意要先移动Pidx，否则直接调用getNextToken()Pidx不会移动
            token = getNextToken();
            if(token == '<') {//此时Pidx指向的是<，可以直接使用上面的分支
                continue;
            }
            //接下来获取content
            int pos = Pstr.find('<', Pidx); 
            if(pos == string::npos) {
                throw "error";
            }
            xml.setContent(Pstr.substr(Pidx, pos - Pidx));
            Pidx = pos;
            continue;

        }
        else{//是属性的情况
            auto key = getAttrKey();
            char x = getNextToken();
            if(key == "" || x != '=') {
                throw "attribute parse error";
            }
            Pidx++;
            auto value = getAttriValue();
            xml.setAttri(key, value);
            //只需要处理一个属性，然后将Pidx置于"的下一个字符，如果还有属性，可以在循环中继续处理
        }
    }
    throw "parse error";//正常情况下，一定可以在while循环中的结束标签处return，所以如果没有return就说明出错
}

string Parser::getAttrKey() {
    char token = getNextToken();
    int pos = Pidx;
    if(isalpha(token)||token == '_') {
        while(Pidx < Pstr.size() && 
        (isalnum(Pstr[Pidx]) || Pstr[Pidx] == '_'
        || Pstr[Pidx] == '-' || Pstr[Pidx] == '.' || Pstr[Pidx] == ':')
        && Pstr[Pidx] != '=') {

            Pidx++;
        }
        //正确情况下，Pidx应该停留在=位置
        return Pstr.substr(pos, Pidx - pos);
    }
    throw "Invalid attribute key";
}

string Parser::getAttriValue() {
    char token = getNextToken();
    if(token != '"') {
        throw "Invalid attribute value";
    }
    Pidx++;
    int pos = Pstr.find('"', Pidx);
    if(pos == string::npos) {
        throw "Invalid attribute value";
    }
    int startPos = Pidx;
    Pidx = pos + 1;
    return Pstr.substr(startPos, pos - startPos);
     
}