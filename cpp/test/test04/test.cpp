 #include <iostream>
 using namespace std;
 class A{
    int value;
 public:
     A(int value) : value(value) {}
     int getValue() { return value; }
 };

 void swap(A& x, A& y) {
    A temp = x;
    x = y;
    y = temp;
 }

 int main() {    
   cout << "hello world" << '\n';
    return 0;
 }