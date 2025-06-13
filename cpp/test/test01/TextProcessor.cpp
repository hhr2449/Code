#include "TextProcessor.h"
#include <bits/stdc++.h>

    
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
    std::string TextProcessor::replaceAll(const std::string& from, const std::string& to) // 将字符串中的from字符串全部替换为to字符串
    {
        std::string tem = text_;
        std::regex re(from);
        tem = regex_replace(tem, re, to);//使用regex_replace，将tem字符串中的re正则表达式替换为to字符串
        return tem;
    }
    
    // 字符串分割
    std::vector<std::string> TextProcessor::split(char delimiter)        // 按字符delimiter分割
    {
        std::vector<std::string> res;
        std::string tem = text_;
        std::regex re(std::string(1, delimiter));//创建正则表达式，注意要将字符转换为字符串
        std::sregex_token_iterator it(tem.begin(), tem.end(), re, -1);//表示按照re的规则提取re分割出来的剩余字符串（-1代表剩余的）
        std::sregex_token_iterator end;//默认对象，相当于end()
        while(it != end) {
            res.push_back(it->str());//获取it提取出来的所有字符串
            it++;
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
    bool TextProcessor::isPalindrome()                          // 是否为回文字符串
    {
        return text_ == reverse();
    }
    bool TextProcessor::isNumeric()                             // 是否为数字（允许开头有正负号，允许是小数）
    {
        if(text_[0] != '-' &&  text_[0] != '+' && ((text_[0] < '0') || (text_[0] > '9'))) {
            return false;
        }
        if(countOccurrences(".") > 1) {
            return false;
        }
        for(int i = 1; i < text_.size(); i++) {
            if(((text_[i] < '0') || (text_[i] > '9'))&&(text_[i] != '.')) {
                return false;
            }
        }
        return true;
    }
    bool TextProcessor::containsOnly(const std::string& charset) // 是否只包含指定字符charset
    {
        std::string tem = text_;
        for(int i = 0; i < charset.size(); i++) {
            tem.erase(std::remove(tem.begin(), tem.end(), charset[i]), tem.end());
        }
        return tem.empty();
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
