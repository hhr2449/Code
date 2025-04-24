#include"Employee.h"

bool SecurityProfile2::validate(Device *d) {//检查设备能否访问（部门，等级，依赖）
    if(d->getAllowedDepartment() == this->department && d->isUnlocked(this->accessed) ){//检查部门权限和依赖关系
        if(this->level == 2) {//检查等级
            return true;
        }
        else {
            if(d->getName() == "BaseLock" || d->getName() == "SecurityPanel"){
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;//如果部门权限或依赖关系不满足，返回false
}
void SecurityProfile2::upgradeLevel() {
    this->level = 2;
}
SecurityProfile *SecurityProfile2::clone() {
    SecurityProfile* p = new SecurityProfile2;//基类指针指向派生类对象，最终返回值是基类指针
    p->level = this->level;
    p->department = this->department;
    for(int i = 0; i < this->accessed.size();i++) {
        p->accessed.push_back(this->accessed[i]); 
    }
    return p;
}

Employee::Employee (int id_) : id(id_) {}
MDRJunior::MDRJunior (int id_) : Employee(id_) {
    profile = new SecurityProfile2;
    profile->level = 1;
    profile->department = MACRODATA_REFINEMENT;
}
MDRSenior::MDRSenior (int id_) : Employee(id_) {
    profile = new SecurityProfile2;
    profile->level = 2;
    profile->department = MACRODATA_REFINEMENT;
}
OnDJunior::OnDJunior (int id_) : Employee(id_) {
    profile = new SecurityProfile2;
    profile->level = 1;
    profile->department = OPTICS_AND_DESIGN;
}
OnDSenior::OnDSenior (int id_) : Employee(id_) {
    profile = new SecurityProfile2;
    profile->level = 2;
    profile->department = OPTICS_AND_DESIGN;
}

Employee *MDRJunior::promote(){
    Employee *e = new MDRSenior(id);//改变对象类型
    e->profile = profile->clone();//克隆一份profile
    e->profile->upgradeLevel();//升级等级
    return e;
}
std::string MDRJunior::getType() const{
    return "MDR-Junior";
}
Department MDRJunior::getDepartment() const{
    return MACRODATA_REFINEMENT;
}
Employee *MDRSenior::promote(){
    return this;
}
std::string MDRSenior::getType() const{
    return "MDR-Senior"; 
}
Department MDRSenior::getDepartment() const{
    return MACRODATA_REFINEMENT; 
}
Employee *OnDJunior::promote(){
    Employee *e = new OnDSenior(id);
    e->profile = profile->clone();//克隆一份profile
    e->profile->upgradeLevel();//升级等级
    return e;
}
std::string OnDJunior::getType() const{
    return "O&D-Junior"; 
}
Department OnDJunior::getDepartment() const{
    return OPTICS_AND_DESIGN; 
}
Employee *OnDSenior::promote(){
    return this; 
}
std::string OnDSenior::getType() const{
    return "O&D-Senior"; 
}
Department OnDSenior::getDepartment() const{
    return OPTICS_AND_DESIGN; 
}
// 添加基类析构函数实现
Employee::~Employee() {
    delete profile;  // 释放SecurityProfile资源
}

// 实现MDRJunior的accessDevice方法
bool MDRJunior::accessDevice(Device* d) {
    if (!profile->validate(d)) {
        // 优先检查部门权限
        if (d->getAllowedDepartment() != MACRODATA_REFINEMENT) {
            std::cout << "No permission. ACCESS DENIED.\n";
        }
        // 检查安全等级
        else if (profile->level < 2 && d->getName() == "DataTerminal") {
            std::cout << "No permission. ACCESS DENIED.\n";
        }
        // 检查依赖链
        else if (!d->isUnlocked(profile->accessed)) {
            std::cout << "Dependency not met. ACCESS DENIED.\n";
        }
        return false;
    }
    
    d->execute();
    profile->accessed.push_back(d);
    return true;
}

// 实现MDRJunior的clone方法
Employee* MDRJunior::clone() {
    auto* newEmp = new MDRJunior(*this);
    newEmp->profile = this->profile->clone();  // 深拷贝profile
    return newEmp;
}

// 其他派生类实现模板（以OnDSenior为例）
bool OnDSenior::accessDevice(Device* d) {
    if (!profile->validate(d)) {
        if (d->getAllowedDepartment() != OPTICS_AND_DESIGN) {
            std::cout << "No permission. ACCESS DENIED.\n";
        }
        else if (!d->isUnlocked(profile->accessed)) {
            std::cout << "Dependency not met. ACCESS DENIED.\n";
        }
        return false;
    }
    
    d->execute();
    profile->accessed.push_back(d);
    return true;
}

Employee* OnDSenior::clone() {
    auto* newEmp = new OnDSenior(*this);
    newEmp->profile = this->profile->clone();
    return newEmp;
}
// MDRSenior的accessDevice方法
bool MDRSenior::accessDevice(Device* d) {
    if (!profile->validate(d)) {
        if (d->getAllowedDepartment() != MACRODATA_REFINEMENT) {
            std::cout << "No permission. ACCESS DENIED.\n";
        }
        else if (!d->isUnlocked(profile->accessed)) {
            std::cout << "Dependency not met. ACCESS DENIED.\n";
        }
        return false;
    }
    
    d->execute();
    profile->accessed.push_back(d);
    return true;
}

// MDRSenior的clone方法
Employee* MDRSenior::clone() {
    auto* newEmp = new MDRSenior(*this);
    newEmp->profile = this->profile->clone();
    return newEmp;
}

// OnDJunior的accessDevice方法
bool OnDJunior::accessDevice(Device* d) {
    //判断是否能访问设备，能访问则执行设备，不能访问则返回false
    if (!profile->validate(d)) {
        if (d->getAllowedDepartment() != OPTICS_AND_DESIGN) {
            std::cout << "No permission. ACCESS DENIED.\n";
        }
        else if (profile->level < 2 && d->getName() == "OpticalTool") {
            std::cout << "No permission. ACCESS DENIED.\n";
        }
        else if (!d->isUnlocked(profile->accessed)) {
            std::cout << "Dependency not met. ACCESS DENIED.\n";
        }
        return false;
    }
    //执行操作
    d->execute();
    //将这杯加入设备列表
    profile->accessed.push_back(d);
    return true;
}

// OnDJunior的clone方法
Employee* OnDJunior::clone() {
    auto* newEmp = new OnDJunior(*this);
    newEmp->profile = this->profile->clone();
    //创建一个新的SecurityProfile对象，将原对象的属性复制到新对象中，然后返回新对象的指针
    return newEmp;
}
