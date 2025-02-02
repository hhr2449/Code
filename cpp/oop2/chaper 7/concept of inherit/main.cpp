//继承是oop的三大特性之一
#include<iostream>
using namespace std;

//普通实现

//Java页面
// class Java{
//     public:
//         void header(){
//             cout << "首页、公开课、登录、注册...(公共头部)" << '\n';
//         }
//         void footer(){
//             cout << "帮助中心、交流合作、站内地图...(公共底部)" << '\n';
//         }
//         void left(){
//             cout << "Java、Python、大数据...(公共左侧菜单)" << '\n';
//         }
//         void content(){
//             cout << "Java学科视频" << '\n';

//         }
// };

// //Python页面
// class Python{
//     public:
//         void header(){
//             cout << "首页、公开课、登录、注册...(公共头部)" << '\n';
//         }
//         void footer(){
//             cout << "帮助中心、交流合作、站内地图...(公共底部)" << '\n';
//         }
//         void left(){
//             cout << "Java、Python、大数据...(公共左侧菜单)" << '\n';
//         }
//         void content(){
//             cout << "Python学科视频" << '\n';

//         }
// };

// //c++页面
// class Cpp{
//     public:
//         void header(){
//             cout << "首页、公开课、登录、注册...(公共头部)" << '\n';
//         }
//         void footer(){
//             cout << "帮助中心、交流合作、站内地图...(公共底部)" << '\n';
//         }
//         void left(){
//             cout << "Java、Python、大数据...(公共左侧菜单)" << '\n';
//         }
//         void content(){
//             cout << "C++学科视频" << '\n';

//         }
// };


//发现几个类大部分代码都是重复的，应该利用继承的技术来减少代码
//将公共代码提取出来，减少重复代码

class BasePage{
    public:
        void header(){
            cout << "首页、公开课、登录、注册...(公共头部)" << '\n';
        }
        void footer(){
            cout << "帮助中心、交流合作、站内地图...(公共底部)" << '\n';
        }
        void left(){
            cout << "Java、Python、大数据...(公共左侧菜单)" << '\n';
        }

};//将公共的信息写在基类中

//Java页面

class Java : public BasePage{
    public:
        void content(){
            cout << "Java学科视频" << '\n';

        }
};

//Python页面
class Python : public BasePage{
    public:
        void content(){
            cout << "Python学科视频" << '\n';

        }
};

//c++页面
class Cpp : public BasePage{
    public:
        void content(){
            cout << "C++学科视频" << '\n';

        }
};

//将公共的代码写道基类中，其他类只要继承基类，再写自己特有的代码即可
//语法：class 子类（派生类） ：继承方式 父类（基类）
//子类中有两种成员，一种是从父类继承而来的，一种是自己特有的


void test01(){
    Java ja;
    cout << "Java页面" << '\n';
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "-------------" << '\n';
    cout << "Python页面" << '\n';
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "-------------" << '\n';
    cout << "C++页面" << '\n';
    Cpp cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();

}

int main(){
        test01();
}