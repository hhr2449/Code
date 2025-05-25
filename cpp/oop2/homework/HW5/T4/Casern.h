#pragma once
#include "Footman.h"
#include "Commander.h"
#include "Belong.h"
#include <vector>


class Casern {
    //TODO
    std::vector<Commander*> commander;
    std::vector<Footman*> footman;
    std::vector<Belong*> belong;//!基类中声明私有数据成员是不好的，不可以访问
public:
    virtual std::string getKind() = 0;
    virtual void addCommander(Commander* _commander) = 0;
    virtual void addFootman(Footman* _footman) = 0;
    virtual void addBelong(Belong* _belong) = 0;
    virtual Footman* getFootmanbyIndex(int index) = 0;
    virtual Commander* getCommanderbyIndex(int index) = 0;
    virtual Belong* getBelongbyIndex(int index) = 0;
	//TODO
};