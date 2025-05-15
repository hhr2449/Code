#include <iostream>
#include <vector>
#include <string>
#include "PalString.h"
using namespace std;
int main(){
	vector<PalString*> palstring_list;
	//一个vector，里面储存的是PalString类的指针
	int n, m;//回文串个数，操作数
	string str;
	cin >> n;
	getline(cin, str);//注意这一行，这是为了防止cin和geiline连用造成的问题，cin后遗留下来的换行符会被geiline读取，导致第一个geiline读取到的是空行
	for (int i = 0; i < n; ++i){
		getline(cin, str);//读入字符串
		PalString* palstring = new PalString{str.c_str()};//new一个PalString类的对象，并把指针push到vector中
		palstring_list.push_back(palstring);
	}
	cin >> m;
	for (int i = 0; i < m; ++i){
		int tmp, k, k2;
		cin >> tmp;
		if (tmp == 0){
			cin >> k;
			cout << palstring_list[k]->getString() <<endl;//输出第k个字符串信息，getString()返回的是一个char*，可以使用cout <<输出
		}else if (tmp == 1){
			cin >> k;
			getline(cin, str);
			getline(cin, str);
			palstring_list[k]->changeString(str.c_str());//修改字符串
		}else if (tmp == 2){
			cin >> k;
			PalString* palstring = new PalString{*palstring_list[k]};//拷贝构造
			palstring_list.push_back(palstring);
		}else{
			cin >> k;
			cout << *palstring_list[k] << endl;//直接输出（重载<<）
		}
	}
	for (int i = 0; i < palstring_list.size(); ++i){
		delete palstring_list[i];//销毁
	}
}