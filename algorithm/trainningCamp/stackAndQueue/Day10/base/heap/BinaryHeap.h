#pragma once
#include <vector>
#include <functional>
#include <iostream>
using namespace std;
template<typename T>
class BinaryHeap {
    private:
        //储存堆的容器
        vector<T> heap;
        //比较函数
        //这里使用function,可以传入函数指针，函数对象等
        function<bool(const T&, const T&)> compare;

        //这里使用数组来作为底层容器，有索引之间有关系：左儿子的索引为2*index + 1，右儿子索引为2*index + 2
        //返回节点的父节点索引
        int getParent(int index) {return (index - 1)/2;} 
        //返回左儿子节点的索引
        int getLeftChild(int index) {return 2*index + 1;}
        //返回右儿子节点的索引
        int getRightChlid(int index) {return 2*index + 2;}
        //交换元素
        void swap(int index1, int index2) {
            T temp = heap[index1];
            heap[index1] = heap[index2];
            heap[index2] = temp;
        }
        //上浮操作：将元素向上调整以符合堆特性
        //注意排序原则：compare函数是严格弱序的，排序的结果是优先级升序的
        void bubbleUp(int index) {
            //不断与父亲节点交换，直到index节点为根节点或是父亲节点的优先级比他高
            while(index > 0) {
                int father = (index - 1)/2;
                //如果父亲节点的优先级低于index节点，则交换
                if(compare(heap[father], heap[index])) {
                    swap(father, index);
                    index = father;  
                }
                else {
                    break;
                }
            }
        }
        //下沉操作
        //将元素向下调整以维持堆特性
        //寻找index节点和其儿子节点中的最大值，如果index就是最大值，结束下沉，否则将index节点和最大的节点交换
        //当index下沉到堆底时结束下沉
        void bubbleDown(int index) {
            int size = heap.size();
            int leftSon = getLeftChild(index);
            int rightSon = getRightChlid(index);
            //当左儿子索引超过堆大小时，说明当前index在底部
            while(leftSon < size) {
                //获取最大节点的索引
                int largest = index;
                if(compare(heap[index], heap[leftSon])) {
                    largest = leftSon;
                }
                if(compare(heap[largest], heap[rightSon])) {
                    largest = rightSon;
                }
                //如果index就是最大节点，那么下沉完成，结束循环
                if(largest == index) {
                    break;
                }
                //如果不是，则进行交换，更新index节点的值，继续下沉
                else {
                    //注意交换函数的参数是索引
                    swap(index, largest); 
                    index = largest;
                    //注意每次循环都要更新左右儿子
                    leftSon = getLeftChild(index);
                    rightSon = getRightChlid(index);
                }
            }
        }
    public:
        //对外提供的接口
        //应该实现构造函数，获取size，插入元素，删除元素，获取堆顶元素，判断堆是否为空

        //默认构造大根堆
        BinaryHeap() {
            //使用lambda表达式，这里定义的比较规则是大的优先级高
            //lambda表达式：[捕获列表](parameter) -> type {body}
            //捕获列表代表函数中可以使用的外部变量，比如说外部定义了int x = 10，那么在捕获列表中加上x，就可以在函数中使用x
            //-> type 表示返回值类型，在返回值类型明确的时候可以不加
            compare = [](const T& a, const T& b) {
                return a < b;
            };
        }
        BinaryHeap(function<bool(const T&, const T&)> compare_) : compare(compare_) {}
        //获取size
        int size() const {
            return heap.size();
        }
        //判断是否为空
        bool empty() const {
            return heap.empty();
        }
        //获取堆顶元素
        T top() const {
            if(heap.empty()) {
                throw "heap is empty";
            }
            return heap[0];
        }
        //加入元素
        //加入元素应该将其加到堆得末尾，然后上浮
        void push(const T& x) {
            heap.push_back(x);
            bubbleUp(heap.size() - 1);
        }
        //删除元素
        //删除元素应该将堆得末尾元素放到堆顶，然后下沉
        void pop() {
            if(heap.empty()) {
                throw "heap is empty";
            }
            //将末尾元素放到堆顶
            heap[0] = heap[heap.size() - 1];
            //删除末尾元素
            heap.pop_back();
            bubbleDown(0);
        }
            //打印堆
        void printHeap() const {
            for(int i = 0; i < heap.size(); i++) {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
};