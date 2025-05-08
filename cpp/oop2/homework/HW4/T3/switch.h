#pragma once
#include <vector>
template <typename T>
class Case{
    public:
        T flag;
        void (*op)(int&);
        bool shouldBreak;
        int *tar;
        Case(T flag_, void (*op_)(int&), int* target, bool shouldBreak_):flag(flag_), op(op_), tar(target), shouldBreak(shouldBreak_){}
};
template <typename T>
class MySwitch{
    public:
        std::vector<Case<T>> cases;
        void addCase(T flag, void (*op_)(int &),int *target,bool shouldBreak){
            cases.push_back(Case<T>(flag, op_, target, shouldBreak));
        }
        void execute(T value){
            for(int i = 0; i < cases.size(); i++){
                if(cases[i].flag == value) {
                    cases[i].op(*cases[i].tar);
                    if(cases[i].shouldBreak){
                        break;
                    }
                }
 
            }
        }
};