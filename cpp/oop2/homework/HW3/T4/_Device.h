//这是抽象的设备基类

#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

enum Department
{
    MACRODATA_REFINEMENT,
    OPTICS_AND_DESIGN
};

class Device
{
public:
    virtual bool isUnlocked(const std::vector<Device *> &accessed) = 0;//设备依赖检查
    virtual void execute() = 0;//设备执行结果
    virtual std::string getName() const = 0;//设备名称
    virtual Department getAllowedDepartment() const = 0;//允许访问的部门
    virtual ~Device() = default;
};