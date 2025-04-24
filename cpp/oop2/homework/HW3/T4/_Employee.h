
//这是抽象的员工基类
#pragma once
#include "_Device.h"
#include <vector>
#include <memory>
#include <string>

class SecurityProfile//虚基类，需要具体实现
{
public:
    int level;//等级
    Department department;//部门
    std::vector<Device *> accessed;//访问过的设备
    virtual bool validate(Device *d) = 0;//检查设备能否访问（部门，等级，依赖）
    virtual void upgradeLevel() = 0;//升级等级
    virtual SecurityProfile *clone() = 0;//克隆一份当前对象
    virtual ~SecurityProfile() = default;
};

class Employee
{
protected:
    int id;

public:
    SecurityProfile *profile;
    Employee(int id);
    virtual Employee *promote() = 0; // 返回晋升后的新对象
    virtual bool accessDevice(Device *d) = 0;// 访问设q
    virtual std::string getType() const = 0;//获取员工类型
    virtual Department getDepartment() const = 0;//获取员工部门
    virtual Employee *clone() = 0;//克隆员工
    virtual ~Employee();
    int getID() const { return id; }//获取id
};