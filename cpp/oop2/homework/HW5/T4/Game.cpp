#include "Game.h"

Casern* Game::createGame(AbstractFactory& factory) {//传入一个抽象工厂的引用，根据实际引用的对象来决定使用哪个工厂
    Casern* casern = factory.createCasern();//创建兵营
    Footman* f1 = factory.createFootman("shou");//创建步兵
    Footman* f2 = factory.createFootman("shox");//创建步兵
    Commander* c1 = factory.createCommander("qmcc");//创建指挥官
    Belong* b1 = factory.createBelong(f1, c1);        //创建从属关系
    //兵营应该组合步兵，指挥官，从属关系（考虑使用指针vector来维护这些子对象），并通过函数来添加
    casern->addFootman(f1);
    casern->addFootman(f2);
    casern->addCommander(c1);
    casern->addBelong(b1);

    return casern;       
}