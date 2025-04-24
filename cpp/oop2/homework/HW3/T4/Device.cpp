#include"Device.h"
bool BaseLock::isUnlocked(const std::vector<Device *> &accessed) {
    return true;
}
void BaseLock::execute() {
    std::cout << "BaseLock engaged." << '\n';
}
std::string BaseLock::getName() const {
    return "BaseLock";
}
Department BaseLock::getAllowedDepartment() const {
    return MACRODATA_REFINEMENT;
}
bool SecurityPanel::isUnlocked(const std::vector<Device *> &accessed) {
    for(int i = 0;i < accessed.size();i++) {
        if(dynamic_cast<BaseLock *>(accessed[i])) {//检查指针指向的是否是BaseLock类型或是器派生类的对象
            return true;                            //dynamic_cast是一种运行时类型检查，用于将基类指针或引用转换为派生类指针或引用，如果转换失败，返回空指针或抛出异常
        }
    }
    return false;
}
void SecurityPanel::execute() {
    std::cout << "SecurityPanel activated." << '\n';
}
std::string SecurityPanel::getName() const {
    return "SecurityPanel";
}
Department SecurityPanel::getAllowedDepartment() const {
    return MACRODATA_REFINEMENT;
}


DataTerminal::DataTerminal(int capa) : capacity(capa){}
bool DataTerminal::isUnlocked(const std::vector<Device *> &accessed) {
    for(int i = 0;i < accessed.size();i++) {
        if(dynamic_cast<SecurityPanel *>(accessed[i])) {
            return true;
        }
    }
    return false;
}
void DataTerminal::execute() {
    std::cout << "Processed 3TB data." << '\n';
}
std::string DataTerminal::getName() const {
    return "DataTerminal";
}
Department DataTerminal::getAllowedDepartment() const {
    return MACRODATA_REFINEMENT;
}

bool OpticalTool::isUnlocked(const std::vector<Device *> &accessed) {
    return true;
}
void OpticalTool::execute() {
    std::cout << "OpticalTool adjusted." << '\n';
}
std::string OpticalTool::getName() const {
    return "OpticalTool";
}
Department OpticalTool::getAllowedDepartment() const {
    return OPTICS_AND_DESIGN;
}
