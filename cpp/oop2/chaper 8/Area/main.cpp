#include<iostream>
class Shape{
    protected:
        int width,height;
    public:
        Shape(int a,int b){
            width=a;
            height=b;
        }
        virtual int Area() = 0;
        
};
class Rectangle:public Shape{
    public:
        Rectangle(int a,int b):Shape(a,b){}//使用列表法初始化
        int Area()override{
            std::cout << "矩形的面积为 " ;
            return width*height;
        }
};
class Triangle:public Shape{
    public:
        Triangle(int a,int b):Shape(a,b){}
        int Area()override{
            std::cout << "三角形的面积为 " ;
            return width*height/2;
        }
};

int main(){
    Shape *shape;
    Rectangle rec(4,5);
    Triangle tri(4,5);
    shape=&rec;
    std::cout << shape->Area() << std::endl;
    shape=&tri;
    std::cout << shape->Area() << std::endl;
}