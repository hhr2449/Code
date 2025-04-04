#ifndef CLASSSYSTEM_H
#define CLASSSYSTEM_H
#include<string>
#include<vector>
class Student;//使用前置声明，因为在ClassSystem类的设计中使用到了Student类
class ClassSystem{
    public:
    vector<Student> stuList;//上这节课的学生名单
    int stuNum = 0;//上这节课的学生数
    int classNum = 0;//上课的次数（在后面addClassNumber函数中更新）
    ClassSystem(){

    }
    ~ClassSystem(){

    }
    void addClassNumber(){//每次上课都要更新上课次数（这是为了获得缺勤次数（通过课时数减去出勤次数））
        classNum++;
    }
    void addStudent(Student stu){//添加学生名单
        stuList.push_back(stu);
        stuNum++;
    }
    void signIn(string s_name){//进行签到
        getStudentByName(s_name).preTime++;
    }
    //!无论是通过id获得学生还是通过名字获得学生都需要更新缺勤次数
    Student& getStudentById(int s_id){
        stuList[s_id].absTime = classNum - stuList[s_id].preTime;
        return stuList[s_id];
    }
    //!注意Student类型的函数返回的是临时的Student对象，不能进行修改，应该返回引用
    Student& getStudentByName(string s_name){
        for(int i = 0;i < stuNum;i++){
            if(stuList[i].getName() == s_name){
                stuList[i].absTime = classNum - stuList[i].preTime;
                return stuList[i];
            }
        }
    }
  
};
#endif
