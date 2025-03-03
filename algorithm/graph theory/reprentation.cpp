#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;
struct Node{
    int v;
    double w;
    Node* next;
    Node(int v1,double w1):v(v1),w(w1),next(nullptr){}
};
int m = 0,n = 0,type1 = -1,type2 = -1;//n,m是点，边数，type1代表有无方向，type2代表有无权
bool isLoop = false;//是否有自环
bool isMultiEdge = false;//是否有重边
vector<int> a;//始点
vector<int> b;//终点
vector<int> z;//权
vector<vector<int>> adjMatrix;//邻接
vector<vector<int>> incidenceMatrix;//关联
vector<vector<int>> accessMatrix;//可达矩阵
vector<vector<int>> accessMatrix2;//可达矩阵2
vector<Node*> headList;//邻接表
//以下三个是正向表
vector<int> positiveTableA;
vector<int> positiveTableB;
vector<int> positiveTableZ;
//输入数据
void input(){
    ifstream fin("in.txt");//采用文件
    fin >> n >> m; 
    fin >> type1 >> type2;    
    a.resize(m);
    b.resize(m);
    z.resize(m);
    adjMatrix.resize(n,vector<int>(n,0));
    incidenceMatrix.resize(n,vector<int>(m,0));
    accessMatrix.resize(n,vector<int>(n,0));
    accessMatrix2.resize(n,vector<int>(n,0));
    headList.resize(n,nullptr);
    if(type2 == 1){      
        for(int i=0;i<m;i++){
            fin >> a[i] >> b[i] >> z[i];
            if(a[i]== b[i]){
                isLoop = true;
            }
        }
    }
    else{
        for(int i=0;i<m;i++){
            fin >> a[i] >> b[i];
            if(a[i]== b[i]){
                isLoop = true;
            }
        }
    }
}
void getEdgeList(){
    cout << "边列表为:" << '\n';
    cout << 'A' << ':' << '(';
    for(int i=0;i<m;i++){
        cout << a[i] << ' ';
    }
    cout << ')' << '\n';
    cout << 'B' << ':' << '(';
    for(int i=0;i<m;i++){
        cout << b[i] << ' ';
    }
    cout << ')' << '\n';
    if(type2 == 1){
        cout << 'Z' << ':' << '(';
        for(int i=0;i<m;i++){
            cout << z[i] << ' ';
        }
        cout << ')' << '\n';
    }

}
//得到邻接矩阵
void getAdjMatrix(){
    
    for(int i=0;i<m;i++){
        if(adjMatrix[a[i]-1][b[i]-1] != 0){//判断重边（输入一条边是发现原来已经有了）
            isMultiEdge = true;
        }
        if(type1==1){
            if(type2==0){
                adjMatrix[a[i]-1][b[i]-1] = 1;
            }
            else{
                adjMatrix[a[i]-1][b[i]-1] = z[i];
            }
        }
        else{
            if(type2==0){
                adjMatrix[a[i]-1][b[i]-1] = 1;
                adjMatrix[b[i]-1][a[i]-1] = 1;
            }
            else{
                adjMatrix[a[i]-1][b[i]-1] = z[i];
                adjMatrix[b[i]-1][a[i]-1] = 1;
            }
        }
    }
    if(isMultiEdge){
        cout << "有重边，表示不完全" << '\n';
    }
    cout << "邻接矩阵为:" << '\n';
    for(int i=0;i<n;i++){
        cout << '|';
        for(int j=0;j<n;j++){
            cout << adjMatrix[i][j] << ' ';
        }
        cout << '|';
        cout << '\n';
    }
}
//得到关联矩阵
void getIncidenceMatrix(){
    
    for(int i=0;i<m;i++){
        if(type1==0){
            incidenceMatrix[a[i]-1][i]=1;
            incidenceMatrix[b[i]-1][i]=1;
        }
        else{
            incidenceMatrix[a[i]-1][i]=1;
            incidenceMatrix[b[i]-1][i]=-1;
        }
    }
    cout << "关联矩阵为:" << '\n';
    for(int i=0;i<n;i++){
        cout << '|';
        for(int j=0;j<m;j++){
            cout << setw(2) << incidenceMatrix[i][j] << ' ';
        }
        cout << '|';
        cout << '\n';
    }
}
//得到邻接表
void getAdjList(){
    //Node是节点结构体
    //headList[i]代表第i个节点的邻接表
    //遍历所有的边，如果始点为a[i]，则将b[i]加入到headList[a[i]-1]对应的链表里
    //!如果已经有了邻接矩阵，也可以采用遍历邻接矩阵的方式
    for(int i=0;i<m;i++){
        //如果headList[a[i]-1]为空，则创建一个节点插入headList[a[i]-1]，这个节点是头节点（注意headList是Node*类型的指针数组，应该指向一个Node链表的头节点）
        if(headList[a[i]-1]==nullptr){
            headList[a[i]-1] = new Node(b[i],z[i]);
        }
        else{//如果有了头节点，那么就顺着头节点一直找到尾节点，将新的节点插入尾部
            Node* p = headList[a[i]-1];
            while(p->next != nullptr){
                p = p->next;
            }
            p->next = new Node(b[i],z[i]);
        }
        if(type1==0){//无向图还要反过来做一遍
            if(headList[b[i]-1]==nullptr){
                headList[b[i]-1] = new Node(a[i],z[i]);
            }
            else{
                Node* p = headList[b[i]-1];
                while(p->next != nullptr){
                    p = p->next;
                }
                p->next = new Node(a[i],z[i]);
            }
        }
    }
    cout << "邻接表为:" << '\n';
    for(int i=0;i<n;i++){
        cout << "节点" << i+1 << ':';
        Node* p = headList[i];
        while(p!=nullptr){
            cout << '(' << p->v << ',' << p->w << ')' << ' ';
            p = p->next;
        }
        cout << '\n';
    }
}
//得到正向表
void getPositiveTable(){
    positiveTableA.resize(n+1,0);
    positiveTableB.resize((2-type1)*m+1,0);//对B的索引从1开始
    positiveTableZ.resize((2-type1)*m+1,0);
    positiveTableA[n]=(2-type1)*m+1;
    //!遍历邻接矩阵
    int index = 1;//index用来指示B中下一个该放数的位置（从1开始）
    for(int i=0;i<n;i++){//开始放点i的后继节点
        positiveTableA[i] = index;//点i后继节点开始的索引
        for(int j=0;j<n;j++){
            if(adjMatrix[i][j]!=0){
                positiveTableB[index++] = j+1;//每放一个，索引加1
            }
        }
    
    }
    cout << "正向表为:" << '\n';
    cout << "A:" ;
    for(int i=0;i<n+1;i++){
        cout << positiveTableA[i] << ' ';
    }
    cout << '\n';
    cout << "B:" ;
    for(int i=1;i<(2-type1)*m+1;i++){
        cout << positiveTableB[i] << ' ';
    }
    cout << '\n';
    if(type2==1){
        for(int i=1;i<(2-type1)*m+1;i++){
            cout << positiveTableZ[i] << ' ';
        }
        cout << '\n';
    }

    
    
}
//代表两个矩阵相乘
vector<vector<int>> matrixTimes(vector<vector<int>> &Matrix1,vector<vector<int>> &Matrix2){
    vector<vector<int>> result(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                result[i][j] += Matrix1[i][k] * Matrix2[k][j];
            }
        }
    }
    return result;
}
//得到可达性矩阵(使用矩阵自乘法)
void getAccessMatrix1(){
    vector<vector<int>> tempMatrix(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tempMatrix[i][j] = adjMatrix[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(tempMatrix[i][j]!=0||accessMatrix[i][j]!=0){
                    accessMatrix[i][j] = 1;
                }
            }
        }
        tempMatrix = matrixTimes(tempMatrix,adjMatrix);
    }
    cout << "可达矩阵(矩阵相加求得)为:" << '\n';
    for(int i=0;i<n;i++){
        cout << '|';
        for(int j=0;j<n;j++){
            cout << accessMatrix[i][j] << ' ';
        }
        cout << '|';
        cout << '\n';
    }

}
//得到可达性矩阵（采用warshall算法）
void getAccessMatrix2(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            accessMatrix2[i][j] = adjMatrix[i][j];
        }
    }
    for(int i=0;i<n;i++){//先遍历中间节点，再遍历起点，再遍历终点
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(accessMatrix2[j][k]==1||(accessMatrix2[j][i]==1&&accessMatrix2[i][k]==1)){
                    accessMatrix2[j][k] = 1;
                }
            }
        }
    }
    cout << "可达矩阵(warshall算法求得)为:" << '\n';
    for(int i=0;i<n;i++){
        cout << '|';
        for(int j=0;j<n;j++){
            cout << accessMatrix2[i][j] << ' ';
        }
        cout << '|';
        cout << '\n';
    }
}

int main(){
    input(); 
    getEdgeList();
    getAdjMatrix();
    if(type2!=1&&!isLoop){
        getIncidenceMatrix();
    }
    else{
        cout << "有自环,无法表示" << '\n';
    }
    getAccessMatrix1();
    getAccessMatrix2();
    getAdjList();
    getPositiveTable();

}