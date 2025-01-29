#include<iostream>
using namespace std;
class Person{
    public:
    string m_Name;
    int m_Age;
    Person(string name,int age){
        m_Name = name;
        m_Age = age;
    }
    bool operator==(const Person& p){
        if(m_Name == p.m_Name&&m_Age == p.m_Age){
            return true;
        }
        else{
            return false;
        }
    }
};
void test01(){
    Person p1("Tom",18);
    Person p2("Tom1",18);
    if(p1 == p2){
        cout<<"p1 == p2"<<endl;
    }
    else{
        cout<<"p1 != p2"<<endl;

    }
}
int main(){
    test01();
}