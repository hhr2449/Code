#pragma once
#include <string>

class Commander {
    std::string commanderId;//指挥官名称
public:
    Commander(std::string _commanderId) {//构造指挥官
        commanderId = _commanderId;
    };
    virtual std::string getCommanderId() {return commanderId;}//获取指挥官名称
};