#include"_Device.h"
class BaseLock : public Device {
    public:
    bool isUnlocked(const std::vector<Device*>& accessed) override;
    void execute() override;
    std::string getName() const override;
    Department getAllowedDepartment() const override;
};
class SecurityPanel : public Device {
    public:
    bool isUnlocked(const std::vector<Device*>& accessed) override;
    void execute() override;
    std::string getName() const override;
    Department getAllowedDepartment() const override;
};
class DataTerminal : public Device {
    public:
    int capacity;//注意要添加容量成员变量
    DataTerminal(int capa);//注意要添加构造函数
    bool isUnlocked(const std::vector<Device*>& accessed) override;
    void execute() override;
    std::string getName() const override;
    Department getAllowedDepartment() const override;
};
class OpticalTool : public Device {
    public:
    bool isUnlocked(const std::vector<Device*>& accessed) override;
    void execute() override;
    std::string getName() const override;
    Department getAllowedDepartment() const override;
};


//注意派生类中重写的函数也要在类声明中声明
//注意虚函数的重写要保持一致，包括返回值，参数列表，const属性
//注意所有纯虚函数都要重写