#include<iostream>
#include<vector>
using namespace std;
class cup{
    public:
    int a = 8,b = 0,c = 0;
};
int note[9][6][4] = {0};//这样才是正确的全部初始化为0
vector<cup> Cup(100);
void pure(int k){
    if(Cup[k].a==4&&Cup[k].b==4){
        for(int i = 0;i<=k;i++){
            cout << '(' << Cup[i].a << ',' << Cup[i].b << ',' << Cup[i].c << ')' << '\n';
        }
        return; 
    }
    if(note[Cup[k].a][Cup[k].b][Cup[k].c]==-1){
        return;
    }
    if(Cup[k].a!=0){
        if(5-Cup[k].b>=Cup[k].a){
            Cup[k+1] = Cup[k];
            Cup[k+1].b += Cup[k].a;
            Cup[k+1].a = 0;
            if(note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c]==0){
                note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c] = 1;
                pure(k+1);
                note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c] = 0;//这里需要回溯，note的作用是防止出现死循环（同一条路径中出现相同的状态），但是不是同一条路径下出现同样的状态是允许的
            }
        }
        else{
            Cup[k+1] = Cup[k];
            Cup[k+1].a -= 5-Cup[k].b;
            Cup[k+1].b = 5;
            if(note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c]==0){
                note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c] = 1;
                pure(k+1);
                note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c] = 0;
            }
        }
    }
    if(Cup[k].b!=0){
        if(3-Cup[k].c>=Cup[k].b){
            Cup[k+1] = Cup[k];
            Cup[k+1].c += Cup[k].b;
            Cup[k+1].b = 0;
            if(note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c]==0){
                note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c] = 1;
                pure(k+1);
                note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c] = 0;
            }
        }
        else{
            Cup[k+1] = Cup[k];
            Cup[k+1].b -= 3-Cup[k].c;
            Cup[k+1].c = 3;
            if(note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c]==0){
                note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c] = 1;
                pure(k+1);
                note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c] = 0;
            }
        }
    }
    if(Cup[k].c!=0){
        if(8-Cup[k].a>=Cup[k].c){
            Cup[k+1] = Cup[k];
            Cup[k+1].a += Cup[k].c;
            Cup[k+1].c = 0;
            if(note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c]==0){
                note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c] = 1;
                pure(k+1);
                note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c] = 0;
            }
        }
        else{
            Cup[k+1] = Cup[k];
            Cup[k+1].c -= 8-Cup[k].a;
            Cup[k+1].a = 8;
            if(note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c]==0){
                note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c] = 1;
                pure(k+1);
                note[Cup[k+1].a][Cup[k+1].b][Cup[k+1].c] = 0;
            }
        }
    }
}
int main(){
    pure(0);
    return 0;
}