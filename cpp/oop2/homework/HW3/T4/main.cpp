#include <iostream>
#include <vector>
#include <unordered_map>
#include "_Employee.h"
#include "_Device.h"
#include "Employee.h"
#include "Device.h"

Device *createDevice(int type)//创建一个设备对象（派生类的），根据type创建，统一用基类指针来接收
{
    switch (type)
    {
    case 0:
        return new BaseLock();
    case 1:
        return new SecurityPanel();
    case 2:
        return new DataTerminal(3); // DataTerminal 默认容量3TB
    case 3:
        return new OpticalTool();
    default:
        throw std::invalid_argument("Invalid device type");
    }
}

Employee *createEmployee(int dept, int id)//创建一个员工对象（派生类的），根据部门和id创建，统一用基类指针来接收
{
    switch (dept)
    {
    case 0:
        return new MDRJunior(id);
    case 1:
        return new MDRSenior(id);
    case 2:
        return new OnDJunior(id);
    case 3:
        return new OnDSenior(id);
    default:
        throw std::invalid_argument("Invalid department");
    }
}

int main()
{
    // 第一阶段：创建员工
    int n;
    std::cin >> n;//员工数量
    std::unordered_map<int, Employee *> employees;//键值对，通过id来索引员工对象
    for (int i = 0; i < n; ++i)
    {
        int id, dept;
        //输入指令
        std::cin >> id >> dept;
        //创建员工对象
        employees[id] = createEmployee(dept, id);
    }

    // 第二阶段：处理操作
    int m;
    std::cin >> m;
    std::vector<Device *> devices = {createDevice(0), createDevice(1), createDevice(2), createDevice(3)};//对应四种设备

    for (int i = 0; i < m; ++i)
    {
        int id, op, deviceType;//员工id，操作类型，设备类型
        std::cin >> id >> op >> deviceType;

        if (employees.find(id) == employees.end())//检查是否超出范围
        {
            std::cerr << "Error: Employee " << id << " does not exist.\n";
            continue;
        }

        Employee *emp = employees[id];//临时指针
        if (op == 1)
        { // 晋升操作
            //每一个员工id对应一个基类指针，指针具体指向派生类对象，所以要晋升只需要改变指针指向的派生类对象
            Employee *promotedEmp = emp->promote();
            if (promotedEmp != emp)//没有到最高级
            { // 返回新对象
                std::cout << emp->getType() << "(" << id << "): Promoted to " << promotedEmp->getType() << ".\n";
                delete emp; // 删除旧对象
                employees[id] = promotedEmp;//将员工键值对中的值改为新对象
            }
            else
            {
                std::cout << emp->getType() << "(" << id << "): Already at the highest level.\n";
            }
        }
        else
        { // 访问设备
            if (deviceType < 0 || deviceType >= devices.size())//检查是否超出索引
            {
                std::cerr << "Error: Invalid device type.\n";
                continue;
            }
            Device *target = devices[deviceType];//目标设备
            std::cout << emp->getType() << "(" << id << "): ";
            emp->accessDevice(target);//访问设备
        }
    }

    // 清理内存
    for (auto &[id, emp] : employees)//遍历键值对，释放内存
        delete emp;
    for (auto d : devices)
        delete d;
    return 0;
}