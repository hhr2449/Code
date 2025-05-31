#include <iostream>
#include <functional>
using namespace std;
template <class T>
class myGreater {
    public:
    bool operator()(const T& a, const T& b) const {
        return a > b;
    }
};
bool comp(const int& a, const int& b) {
        return a < b;
    }
//想要让函数既能够接受函数指针，又接受函数对象，可以使用模板
template<class Iterator, class Compare>
void mysort(Iterator first, Iterator last, Compare comp)
//mysort的时间复杂度为O(n^2)，std::sort的时间复杂度为O(nlogn)
{
	for (auto i = first; i != last; i++)
		for (auto j = i; j != last; j++)
			if (!comp(*i, *j)) swap(*i, *j);
}

void mysort2(int* first, int* last, function<bool(int, int)> comp)
//mysort的时间复杂度为O(n^2)，std::sort的时间复杂度为O(nlogn)
{
	for (auto i = first; i != last; i++)
		for (auto j = i; j != last; j++)
			if (!comp(*i, *j)) swap(*i, *j);
}

int main() {
    myGreater<int> g;
    //成为函数对象的要求：重载了()运算符并且是public的
    //其可以表现得和函数一样，因此被称为函数对象
    /*Duck Typing 鸭子类型
    如果一个物体，叫声像鸭子、走路像鸭子，那么它就是鸭子；
    如果一个对象，用起来像函数，那么它就是函数对象！*/
    cout << g(1, 2) << '\n';
    cout << g(2, 1) << '\n';
    int arr[5] = { 5, 2, 3, 1, 7 };
	mysort(arr, arr + 5, comp);
    for(int &i : arr){
        cout << i << ' ';
    }
    cout << '\n';
	mysort(arr, arr + 5, myGreater<int>()); 
    for(int &i : arr){
        cout << i << ' ';
    }
    cout << '\n';
    //实现自定义数据类型的排序：
    //1.重载<运算符
    //2.定义比较函数
    //3.定义函数对象
    function<bool(int, int)> func[] = {comp, myGreater<int>()};
    //function类,既可以储存函数指针，又可以储存函数对象，提供了统一接口
    mysort2(arr, arr + 5, func[0]);
    for(int &i : arr){
        cout << i << ' ';
    }
    cout << '\n';
	mysort2(arr, arr + 5, func[1]); 
    for(int &i : arr){
        cout << i << ' ';
    }
    cout << '\n';

}