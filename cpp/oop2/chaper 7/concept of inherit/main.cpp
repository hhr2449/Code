//继承是oop的三大特性之一
#include<iostream>
using namespace std;

//普通实现

//Java页面
class Java{
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
        void content(){
            cout << "Java学科视频" << '\n';

        }
};

//Python页面
class Python{
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
        void content(){
            cout << "Python学科视频" << '\n';

        }
};

//c++页面
class Cpp{
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
        void content(){
            cout << "C++学科视频" << '\n';

        }
};


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