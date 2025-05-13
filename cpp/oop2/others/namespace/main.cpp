#include <iostream>
//命名空间中可以定义变量，类，函数，不同命名空间的变量，函数，类互相独立
namespace n1{
    int i = 1;
    void func () {
        std::cout << "func in n1" << '\n';
    }
    class classN1 {
        public:
        classN1() {
            std::cout << "construct object in n1" << '\n';
        }
    };
}

namespace n2{
    int i = 2;
    void func () {
        std::cout << "func in n2" << '\n';
    }
    class classN2 {
        public:
        classN2() {
            std::cout << "construct object in n2" << '\n';
        }
    };
}
//同一个工程中可以同时存在多个名字相同的命名空间，最后编译器会将其合成为同一个命名空间
namespace n3{
    int i = 3;
}

namespace n3{
    void func () {
        std::cout << "func in n3" << '\n';
    }
    class classN3 {
        public:
        classN3() {
            std::cout << "construct object in n3" << '\n';
        }
    };

    namespace n31{//命名空间中可以嵌套命名空间
        int i = 31;
    }

}

namespace n4{
    int j = 4;
}


int main() {
    //调用方法1：命名空间::变量名
    std::cout << n1::i << '\n';
    n1::func();
    n1::classN1 obj1;
    std::cout << n2::i << '\n';
    n2::func();
    n2::classN2 obj2;
    //调用方法2：using namespace 命名空间名,这代表着将命名空间中的所有变量，类，函数都引入当前程序  
    //！！！（有风险，如果使用using来解放出了同名的变量/函数/类，就会造成混淆）
    using namespace n4;
    std::cout << j << '\n';
    //调用方法3：using namespace 命名空间名::要释放的变量/函数/类
    using namespace n3::n31;
    //using namespace n3::i;//如果这里将n3中的变量i给释放出来，则会导致冲突
    std::cout << i;
}
