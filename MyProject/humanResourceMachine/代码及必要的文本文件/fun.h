#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include <conio.h> // 包含kbhit()和getch()函数的头文件
#include <sstream>
#include <iomanip> // 主菜单正中生成
#include <cstdlib> //清空屏幕函数
using namespace std;
struct instruction {//指令结构体，包含指令名称和操作数两部分
    string ins;
    double op_num = -1;
};
void get_help();
void is_ins(string ins_set[], int ins_can_use[]);
bool is_number(const string& s);
void read_from_keyboard(instruction input[], int m, string str[], int ptr_input, int level, int x);
void establish(string str[], int m, string inbox[], int max_carpet, string carpet[], string hand);
void level(int m, int cnt_ans, int max_carpet, string inbox[], string carpet[], string ans[], instruction input[], string output[], int ins_can_use[], string str[], int level, int flag_file, int x);
void print(string str[], int ptr_input, int m, instruction input[]);
void bot_creat(string str[], int spot_left, string hand);
void move(string str[], int left_spot_start, int left_spot_end, string hand, int ptr_input, int m, instruction input[]);
void update_inbox(string str[], int ptr_inbox, string inbox[]);
void update_outbox(int ptr_outbox, string outbox[], string str[]);
void update_carpet(int idx, string carpet[], string str[], int max_carpet);
void read_from_file(int level, instruction input[], int& m, int is_my_file, int x);
void change_input(int& m, instruction input[], string str[], int ptr_input, int level, int x);
bool IncludeChinese(const std::string& str);
void level_import(string level_import[], int cnt_level);
int judge_ans(int cnt_ans, int cnt_output, string output[], string ans[]);
void change_state(int x);
void enter_safe(int& x, int start, int end);
void enter_safe_norange(int& x);
void level_delect(string str[], int);