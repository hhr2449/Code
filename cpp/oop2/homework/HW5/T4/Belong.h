#pragma once

class Belong {//从属关系
    //有一个步兵基类的指针和一个指挥官基类的指针，代表两者之间有从属关系
    Footman* footman;
    Commander* commander;
public:
    Belong(Footman* _footman, Commander* _commander) {//构造函数
        footman = _footman;
        commander = _commander;
    }
    //获取·1指挥官指针和步兵指针
    virtual Footman* getFootman() {
        return footman;
    }
    virtual Commander* getCommander() {
        return commander;
    }
};