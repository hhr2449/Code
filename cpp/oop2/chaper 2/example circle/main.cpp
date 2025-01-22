#include"circle.h"
#include"point.h"
using namespace std;


int main(){
    circle c1;
    c1.init(0,0,4);
    p p2;
    p2.init(100,0);
    c1.Judge(p2);
}