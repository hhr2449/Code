#include <iostream>
using namespace std;

//构造函数的分类：
    //1.按参数分类：有参数和无参数
    //2.按照类型分类：普通构造函数和拷贝构造函数
    //拷贝：将另一个对象拷贝到另一个对象上

class Person{
    private:
    int age;
    string name;
    public:
    Person(){
        cout << "Person 无参构造函数" << endl;
    }
    Person(int age_,string name_){
        age=age_;
        name=name_;//在有参构造函数中，对属性进行初始化
        cout << "person 有参构造函数" << endl;
    }
    Person(const Person &p){//*拷贝构造函数：在创建新对象时，将已有对象的内容拷贝到新对象中，参数以常引用进行传递
                            //*（以引用进行传递成本比值传递更低（只传指针），同时防止传入对象发生改变故用常引用）
        cout << "Person 拷贝构造函数" << endl;
        age=p.age;
        name=p.name;//将属性进行拷贝

    }
    ~Person(){
        cout << "Person 析构函数" << endl;
    }
    void show(){
        cout << "age: " << age << ", name: " << name << endl;
    }
};
void test01(){
    //调用：
    //1.括号法
    Person p1;//默认构造
    Person p2(18,"张三");//传入了一个参数，调用有参构造函数
    Person p3(p2);//拷贝构造函数，将p2拷贝到p3中
    p2.show();
    p3.show();//输出p3，发现与p2相同
    //!注意 Person p();这行代码是在声明一个Person类型的函数，不是在创建一个对象，不要将缺省构造函数或者默认构造函数写成这样
    
    //3. 隐式转换法
}
void test02(){
//2. 显式转换法
    Person p4=Person(19,"李四");//有参构造
    Person p5=Person(p4); //拷贝构造
}
int main() {

    test01();
    cout << "-------------" << endl;
    test02();
    cout << "-------------" << endl;
    Person(10,"王五");//这是一个匿名对象，会马上创建马上销毁
    Person(p2);
    system("pause");
    return 0;

}