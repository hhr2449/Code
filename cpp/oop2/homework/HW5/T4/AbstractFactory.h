#pragma once
#include <string>

class AbstractFactory {
public: 
    //均为纯虚函数
    virtual Casern* createCasern() = 0;
    virtual Footman* createFootman(std::string _footmanId) = 0;
    virtual Commander* createCommander(std::string _commanderId) = 0;
    virtual Belong* createBelong(Footman* _footman, Commander* _commander) = 0;
};


//                |----具体工厂：人类工厂  ：创建产品族：人类步兵，人类指挥官，人类从属关系，人类兵营
//抽象的工厂基类----
//                |----具体工厂：兽人工厂  ：创建产品族：兽人步兵，兽人指挥官，兽人从属关系，兽人兵营