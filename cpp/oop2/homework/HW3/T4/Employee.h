#pragma once
#include"_Employee.h"
class MDRJunior : public Employee {
    public:
    MDRJunior (int id_);
    Employee* promote() override;
    bool accessDevice(Device* d) override;
    std::string getType() const override;
    Department getDepartment() const override;
    Employee* clone() override;
};
class MDRSenior : public Employee {
    public:
    MDRSenior (int id_);
    Employee* promote() override;
    bool accessDevice(Device* d) override;
    std::string getType() const override;
    Department getDepartment() const override;
    Employee* clone() override;
};
class OnDJunior : public Employee {
    public:
    OnDJunior (int id_);
    Employee* promote() override;
    bool accessDevice(Device* d) override;
    std::string getType() const override;
    Department getDepartment() const override;
    Employee* clone() override;
};
class OnDSenior : public Employee {
    public:
    OnDSenior (int id_);
    Employee* promote() override;
    bool accessDevice(Device* d) override;
    std::string getType() const override;
    Department getDepartment() const override;
    Employee* clone() override;
};
class SecurityProfile2 : public SecurityProfile{
    virtual bool validate(Device *d) ;//检查设备能否访问（部门，等级，依赖）
    virtual void upgradeLevel() ;//升级等级
    virtual SecurityProfile *clone() ;//克隆一份原对象，返回值是基类指针
};