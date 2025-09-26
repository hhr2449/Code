#include <iostream>

template <typename T>
class Vector {
private:
    T* _elem;
    int _size;

public:
    // 构造函数
    Vector(int size) : _size(size) {
        _elem = new T[size];
        for (int i = 0; i < size; ++i) {
            _elem[i] = T(); // 初始化为默认值
        }
    }

    // 析构函数
    ~Vector() {
        delete[] _elem;
    }

    // 1. 非 const 版本的重载
    //    返回一个可修改的引用
    T& operator[](int r) {
        std::cout << "调用了非 const 的 operator[]" << std::endl;
        return _elem[r];
    }

    // 2. const 版本的重载
    //    返回一个只读的引用
    const T& operator[](int r) const {
        std::cout << "调用了 const 的 operator[]" << std::endl;
        return _elem[r];
    }

    int size() const { return _size; }
};

// 一个接受 const Vector& 的函数
void print_vector(const Vector<int>& vec) {
    std::cout << "打印向量内容: ";
    for (int i = 0; i < vec.size(); ++i) {
        // 在这里，vec 是 const 对象，所以会调用 const 版本的 []
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // 1. 创建一个普通的（非 const）Vector 对象
    Vector<int> v1(3);

    // 对 v1 的操作
    std::cout << "--- 操作非 const 对象 v1 ---" << std::endl;
    v1[0] = 10; // OK! 调用非 const 版本，返回 int&，可以被赋值
    int value = v1[0]; // OK! 调用非 const 版本，返回 int&，可以被读取
    std::cout << "v1[0] 的值是: " << value << std::endl;


    // 2. 创建一个 const Vector 对象
    const Vector<int> v2(3);

    std::cout << "\n--- 操作 const 对象 v2 ---" << std::endl;
    // v2[0] = 20; // 编译错误！
    // 因为 v2 是 const 对象，只能调用 const 成员函数。
    // const 版本的 [] 返回 const int&，不能被赋值。

    int value2 = v2[0]; // OK! 调用 const 版本，返回 const int&，可以被读取
    std::cout << "v2[0] 的值是: " << value2 << std::endl;


    // 3. 在函数调用中
    std::cout << "\n--- 在函数中传递 const 对象 ---" << std::endl;
    print_vector(v1); // v1 虽然不是 const，但传递给一个接受 const& 的函数时，
                      // 在函数内部它会被当作 const 对象处理。
                      // 因此，在 print_vector 内部调用的是 const 版本的 []。

    return 0;
}