#pragma once

#include "Footman.h"
#include "Commander.h"
#include "Belong.h"
#include "Casern.h"

class HumanFootman :  public Footman {
    std::string footmanId;
public:
    //TODO
    HumanFootman(std::string _footmanId) :Footman(_footmanId) {//构造步兵
        footmanId = _footmanId;
    };
    std::string getFootmanId() {return footmanId;}
};

class OrcFootman :  public Footman {
    std::string footmanId;
public:
    OrcFootman(std::string _footmanId) : Footman(_footmanId) {//构造步兵
        footmanId = _footmanId;
    };
    std::string getFootmanId() {return footmanId;}
    //TODO
};

class HumanCommander :  public Commander {
    std::string commanderId;
public:
    HumanCommander(std::string _commanderId) : Commander(_commanderId) {//构造指挥官
        commanderId = _commanderId;
    };
    std::string getCommanderId() {return commanderId;}//获取指挥官名称
    //TODO
};

class OrcCommander :  public Commander {
    std::string commanderId;
public:
    OrcCommander(std::string _commanderId) : Commander(_commanderId) {//构造指挥官
        commanderId = _commanderId;
    };
    std::string getCommanderId() {return commanderId;}//获取指挥官名称
    //TODO
};

class HumanBelong :  public Belong {
    Commander* commander;
    Footman* footman;
public:
    HumanBelong(Footman* _footman, Commander* _commander) :Belong(_footman, _commander) {//构造函数
        footman = _footman;
        commander = _commander;
    }
    //获取指挥官指针和步兵指针
    Footman* getFootman() {
        return footman;
    }
    Commander* getCommander() {
        return commander;
    }
    //TODO
};

class OrcBelong :  public Belong {
    Commander* commander;
    Footman* footman;
public:
    OrcBelong(Footman* _footman, Commander* _commander) : Belong(_footman, _commander) {//构造函数
        footman = _footman;
        commander = _commander;
    }
    //获取指挥官指针和步兵指针
    Footman* getFootman() {
        return footman;
    }
    Commander* getCommander() {
        return commander;
    }
    //TODO
};

class HumanCasern : public Casern {
    std::vector<Commander*> commander;
    std::vector<Footman*> footman;
    std::vector<Belong*> belong;
public:
    void addCommander(Commander* _commander) {
        commander.push_back (_commander);
    }
    void addFootman(Footman* _footman) {
        footman.push_back (_footman);
    }
    void addBelong(Belong* _belong) {
        belong.push_back (_belong);
    }
    Footman* getFootmanbyIndex(int index) {
        return footman[index];
    }
    Commander* getCommanderbyIndex(int index) {
        return commander[index];
    }
    Belong* getBelongbyIndex(int index) {
        return belong[index];
    }
    std::string getKind() {
        return "HumanCasern";
    }
    //TODO
};

class OrcCasern : public Casern {
    std::vector<Commander*> commander;
    std::vector<Footman*> footman;
    std::vector<Belong*> belong;
public:
    void addCommander(Commander* _commander) {
        commander.push_back (_commander);
    }
    void addFootman(Footman* _footman) {
        footman.push_back (_footman);
    }
    void addBelong(Belong* _belong) {
        belong.push_back (_belong);
    }
    Footman* getFootmanbyIndex(int index) {
        return footman[index];
    }
    Commander* getCommanderbyIndex(int index) {
        return commander[index];
    }
    Belong* getBelongbyIndex(int index) {
        return belong[index];
    }
    std::string getKind() {
        return "OrcCasern";
    }
	//TODO
};
