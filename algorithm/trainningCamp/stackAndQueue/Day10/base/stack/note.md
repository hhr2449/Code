stack称为栈，特点是先进后出
包含的操作有出栈，入栈，判断栈空，查看栈顶元素，理论上不允许中部和底部的操作
在STL中，stack并不是一个容器，而是一个容器适配器，也就是对容器进行一定的封装和适配的操作，实现栈的功能
包含两个参数，T是栈中的元素类型，同时也是底层容器的元素类型；container<T>就是底层容器，默认为deque，使用vector,list同样可以实现
包含操作：empty(),back(),push_back(),pop_back()
对应的接口：push(),pop(),top(),empty(),size()
