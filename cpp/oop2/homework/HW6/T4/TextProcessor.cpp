#include "TextProcessor.h"

    TextProcessor::TextProcessor(){}
    TextProcessor::TextProcessor(const std::string& text){
        text_ = text;
    }
    // 设置和获取文本
    void TextProcessor::setText(const std::string& text) {
        text_ = text;
    }
    std::string TextProcessor::getText() const {
        return text_;
    }
    
    // 基础字符串操作
    std::string TextProcessor::removeSpaces()                    // 移除文本里所有的空格，并返回移除空格后的字符串
    {
        std::string tem = text_;
        tem.erase(std::remove(tem.begin(), tem.end(), ' '), tem.end());
        //删除特定字符的惯用方法：str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
        //remove函数将给定范围内的特定字符放在范围的末尾，并返回处理完后的字符串的尾迭代器，之后再将尾迭代器到字符串末尾的搜友特定字符用erase删除
        return tem;
    }
    std::string TextProcessor::toLowerCase()                 // 将字符串里所有字符均转为小写，并返回转换后的字符串
    {
        std::string tem = text_;
        for(int i = 0; i < tem.size(); i++) {
            if(tem[i] >='A'&&tem[i] <= 'Z') {
                tem[i] += 'a' - 'A';
            }
        }
        return tem;
    }
    std::string TextProcessor::toUpperCase()                    // 将字符串里所有字符均转为大写，并返回转换后的字符串
    {
        std::string tem = text_;
        for(int i = 0; i < tem.size(); i++) {
            if(tem[i] >='a'&&tem[i] <= 'z') {
                tem[i] += 'A' - 'a';
            }
        }
        return tem;
    }
    std::string TextProcessor::reverse()                         // 将字符串反转，并返回反转后的字符串
    {
        std::string tem = text_;
        std::reverse(tem.begin(), tem.end());
        return tem;
    }
    
    // 字符串查找和替换
    int TextProcessor::countOccurrences(const std::string& substr)        // 返回子串substr在字符串中出现的次数，如果从未出现则返回0
    {
        //str.find(substr, pos);函数会从str中的pos位置开始查找substr，如果找到则返回子串首字符在str中的下标，如果没有找到返回string::nops
        std::string tem = text_;
        int cnt = 0;
        int pos = tem.find(substr);
        while(pos != std::string::npos) {
            cnt++;
            pos = tem.find(substr, pos + 1);
        }
        return cnt;
    }
    std::vector<int> TextProcessor::findPositions(const std::string& substr) // 返回子串`substr`的首字母在字符串中的所有位置，如果不含该子串则返回空数组
    {
        std::vector<int> v;
        std::string tem = text_;
        int pos = tem.find(substr);
        while(pos != std::string::npos) {
                v.push_back(pos);
            pos = tem.find(substr, pos + 1);
        }
        return v;
    }
std::string TextProcessor::replaceAll(const std::string& from, const std::string& to)
{
    if (from.empty()) return text_; // 防止死循环
    std::string tem = text_;
    size_t pos = 0;
    while ((pos = tem.find(from, pos)) != std::string::npos) {
        tem.replace(pos, from.length(), to);
        pos += to.length(); // 防止重复替换
    }
    return tem;
}
    // 字符串分割
std::vector<std::string> TextProcessor::split(char delimiter)
{
    std::vector<std::string> res;
    std::stringstream ss(text_);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        res.push_back(token);
    }
    return res;
}
    
    // 字符和单词统计
    int TextProcessor::getCharCount()                           // 统计字符数（包含空格）
    {
        return text_.size();


    }
    int TextProcessor::getCharCountNoSpaces()                // 统计字符数（不含空格）
    {
        std::string tem = removeSpaces();
        return tem.size();
    }
    int TextProcessor::getLineCount()                           // 统计行数（最少有一行）
    {
        return countOccurrences("\n") + 1;
    }
    
    // 字符串验证
    bool TextProcessor::isPalindrome() {
    // 应该忽略空格和大小写进行比较
    std::string noSpace = removeSpaces();
    std::string lower = noSpace;
    for (char& c : lower) {
        if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';
        }
    }
    std::string reversed = lower;
    std::reverse(reversed.begin(), reversed.end());
    return lower == reversed;
}
bool TextProcessor::isNumeric()
{
    std::string s = text_;
    if (s.empty()) return false;

    int i = 0;
    if (s[i] == '+' || s[i] == '-') i++;
    bool has_digit = false;
    bool has_dot = false;

    for (; i < s.size(); ++i) {
        if (isDigit(s[i])) {
            has_digit = true;
        } else if (s[i] == '.') {
            if (has_dot) return false;
            has_dot = true;
        } else {
            return false;
        }
    }
    return has_digit;
}
  bool TextProcessor::containsOnly(const std::string& charset)
{
    for (char c : text_) {
        if (charset.find(c) == std::string::npos)
            return false;
    }
    return true;
}

    
    // 格式化功能
    std::string TextProcessor::centerAlign(int width, char fillChar ) // 使用fillChar进行填充（默认为空格），将字符串以居中对齐的方式扩充为宽度为width的新字符串，如果本身字符串就比width宽，则返回原本的字符串
    {
        int len = (width-text_.size())/2;
        if(text_.size() > width)
        {
            return text_;
        }
        std::string tem(len, fillChar);
        std::string tem2(width-text_.size() - len, fillChar);
        return tem + text_ + tem2;
    }
    std::string TextProcessor::leftAlign(int width, char fillChar )   // 使用fillChar进行填充（默认为空格），将字符串以左对齐的方式扩充为宽度为width的新字符串，如果本身字符串就比width宽，则返回原本的字符串
    {
        if(text_.size() > width)
        {
            return text_;
        }
        int len = width - text_.size();
        std::string tem(len, fillChar);
        return text_ + tem;
    }
    std::string TextProcessor::rightAlign(int width, char fillChar )  // 使用fillChar进行填充（默认为空格），将字符串以右对齐的方式扩充为宽度为width的新字符串，如果本身字符串就比width宽，则返回原本的字符串
    {
        if(text_.size() > width)
        {
            return text_;
        }
        int len = width - text_.size();
        std::string tem(len, fillChar);
        return tem + text_;
    }
