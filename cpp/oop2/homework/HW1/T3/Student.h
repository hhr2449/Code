#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;


class Student{
public:
    string name;
    int preTime = 0;
    int absTime = 0;
    Student(string s_name){
        name = s_name;
    }
    
    int getAbsentTimes(){
        return absTime;
    }
    int getPresentTimes(){
        return preTime;
    }
    string getName(){
        return name;
    }
   
};
#endif