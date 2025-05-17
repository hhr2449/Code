#pragma once
#include <string>

class Footman {
    std::string footmanId;//步兵名称
public:
    Footman(std::string _footmanId) {//构造步兵
        footmanId = _footmanId;
    };

    virtual std::string getFootmanId() {return footmanId;}//获取步兵名称
};