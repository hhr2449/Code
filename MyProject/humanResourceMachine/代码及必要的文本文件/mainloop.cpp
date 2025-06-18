#include"fun.h"
using namespace std;


void level_init(int x, string index[]) {//这个函数用于读取关卡信息
    string inbox[150];
    string carpet[10];
    string ans[150];
    instruction input[150];
    string output[150];
    int cnt_ans, max_carpet;
    string ins_set[8];
    int ins_can_use[8] = { 0 };
    string str[30];
    str[23] = "【请注意：如果想中途退出请输入w（退出后无法回到当前状态！），想进入单步调试请输入n。输入后将在当下步执行完毕后进入对应状态。】";
    ifstream fin;
    fin.open(index[x]);//打开对应的关卡信息文件
    if (!fin) {
        cout << "没有这个关卡" << '\n';
        return;
    }
    int flag_file = 0;
    system("cls");
    cout << "玩家选择了第" << x << "关！" << '\n';
    cout << "┌-----------┤善意的提醒No.2├---------------┐" << '\n';
    cout << "|     系统检测到有可读档，是否读档游玩     |" << '\n'
        << "├------------------------------------------┤" << '\n'
        << "|        我不想读！--> 0                   |" << '\n'
        << "|        我要读！--> 1                     |" << '\n'
        << "|        实际上我自己写了文件...--> 2      |" << '\n'
        << "┕------------------------------------------┙" << '\n';
    enter_safe(flag_file, 0, 2);
    system("cls");
    for (int i = 18; i < 23; i++) {
        getline(fin, str[i]);//读取前几行关卡描述
    }
    for (int i = 1; i < 50; i++) {
        if (str[19][i] == '_') {
            str[19][i + 1] = (char)(x + '1' - 1);
            break;
        }
    }
    string temp1;
    string temp2;
    getline(fin, temp1);//整行读取进temp1
    istringstream iss1(temp1);//创建流iss，将一整行内容按空格分割为子串输入
    for (int i = 0; iss1 >> temp2; i++) {//临时变量temp2用于储存分割的字符串
        inbox[i] = temp2;//读取inbox
    }
    getline(fin, temp1);
    istringstream iss2(temp1);
    for (int i = 0; iss2 >> temp2; i++) {
        ans[i] = temp2;//读取ans
    }
    getline(fin, temp1);
    istringstream iss3(temp1);
    for (int i = 0; iss3 >> temp2; i++) {
        ins_set[i] = temp2;//读取ins_set
    }
    getline(fin, temp1);
    istringstream iss4(temp1);
    for (int i = 0; iss4 >> temp2; i++) {
        carpet[i] = temp2;//读取carpet
    }
    is_ins(ins_set, ins_can_use);//将可用指令转成整型数组
    fin >> cnt_ans;
    fin >> max_carpet;//输入答案数和最大地毯数
    fin.close();
    establish(str, 0, inbox, max_carpet, carpet, "  ");
    print(str, 0, 0, input);//方便玩家思考，在输入指令数之前就要打印地图和关卡信息
    int m;
    cout << "┌----------------------┤填写1├---------------------------┐" << '\n';
    cout << "|请输入你要输入的指令数(如果想要读档或导入文件就随便填吧)|" << '\n';
    cout << "┕--------------------------------------------------------┙" << '\n';
    enter_safe_norange(m);
    system("cls");
    level(m, cnt_ans, max_carpet, inbox, carpet, ans, input, output, ins_can_use, str, 0, flag_file, x);
}

int main() {
    int playtimes = 0;
    string index[100];
    int isimport = 0;
    int cnt_level = 0;
    int width = 150;
    int state[100] = { -1 };//储存关卡状态，0是lock,1是pass,2是可以尝试
    ifstream fin("index.txt");//这里创建了一个关卡索引index，里面储存了关卡信息所对应的文件路径，每次进入关卡时会导入进index数组
    if (!fin) {
        cout << "错误：无法打开 index 文件";
        return 0;
    }
    while (!fin.eof()) {
        fin >> index[cnt_level++];//导入索引的同时cnt_level变量获得关卡数
    }
    fin.close();
    cout << "**      **                                         *******                                                            ****     ****                   **      **                " << endl
        << "/**     /**                                        /**////**         人      力     资     源     机     器           /**/**   **/**                  /**     //                  " << endl
        << "/**     /** **   ** **********   ******   *******  /**   /**   *****   ******  ******  **   ** ******  *****   *****  /**//** ** /**  ******    ***** /**      ** *******   ***** " << endl
        << "/**********/**  /**//**//**//** //////** //**///*  /*******   **///** **////  **////**/**  /**//**//* **///** **///** /** //***  /** //////**  **///**/****** /**//**///** **///**" << endl
        << "/**//////**/**  /** /** /** /**  *******  /**  /*  /**///**  /*******//***** /**   /**/**  /** /** / /**  // /******* /**  //*   /**  ******* /**  // /**///**/** /**  /**/******" << endl
        << "/**     /**/**  /** /** /** /** **////**  /**  /*  /**  //** /**////  /////**/**   /**/**  /** /**   /**   **/**////  /**   /    /** **////** /**   **/**  /**/** /**  /**/**////" << endl
        << "/**     /**//****** *** /** /**//******** ***  /*  /**   //**//****** ****** //****** //******/***   //***** //****** /**        /**//********//***** /**  /**/** ***  /**//******" << endl
        << "//      //  ////// ///  //  //  //////// ///   //  //     //  ////// //////   //////   ////// ///     /////   //////  //         //  ////////  /////  //   // // ///   //  ////// " << endl;
    string text1 = "*欢迎来到人力资源机器的世界！请通过输入命令来探索这个世界*", text2 = "┌-------------┐", text3 = "|开始游戏 -> 1|", text4 = "|导入关卡 -> 2|", text5 = "|删除关卡 -> 3|", text6 = "┕-------------┙";
    cout << setw((width + text1.length()) / 2) << text1 << endl;
    cout << setw((width + text2.length()) / 2) << text2 << '\n';
    cout << setw((width + text3.length()) / 2 - 1) << text3 << '\n';
    cout << setw((width + text4.length()) / 2 - 1) << text4 << '\n';
    cout << setw((width + text5.length()) / 2 - 1) << text5 << '\n';
    cout << setw((width + text6.length()) / 2) << text6 << '\n';//添加导入关卡功能
    enter_safe(isimport, 1, 3);
    system("cls");
    if (isimport == 2) {
        level_import(index, cnt_level);
    }
    else if (isimport == 3) {
        level_delect(index, cnt_level);
    }
    else {
        while (1) {
            ifstream fin_state;
            for (int i = 1; i < cnt_level; i++) {
                string in_state = "state";
                in_state += to_string(i);
                in_state += ".txt";
                fin_state.open(in_state);
                fin_state >> state[i];
                fin_state.close();
            }
            int x, iscontinue = 0, ishelp = 0;
            if (playtimes == 0) {
                cout << "┌---------┤善意的提醒No.1 (1)├----------------┐" << '\n';
                cout << "| 这里有一些游戏背景和指令集，是否需要浏览一遍|" << '\n';
                cout << "├---------------------------------------------┤" << '\n';
                cout << "|  我是菜鸡，我需要 --> 1  |  我不需要 --> 2  |" << '\n';
                cout << "┕---------------------------------------------┙" << '\n';
                enter_safe(ishelp, 1, 2);
                if (ishelp == 1) {
                    get_help();
                }
            }
            else {
                cout << "┌---------┤善意的提醒No.1 (2)├------------┐" << '\n';
                cout << "|    是否继续游玩（将跳到关卡选择界面）   |" << '\n'
                    << "├-----------------------------------------┤" << '\n'
                    << "|        我突然有事，先不玩了 --> 0       |" << '\n'
                    << "|        我要继续玩          --> 1        |" << '\n'
                    << "|        我忘了规则，想要温习 --> 2       |" << '\n'
                    << "┕-----------------------------------------┙" << '\n';
                enter_safe(iscontinue, 0, 2);
                if (iscontinue == 0) {
                    cout << "【好的！See you next time】";
                    break;
                }
                if (iscontinue == 2) {
                    get_help();

                }
            }
            system("cls");
            cout << "┌--------------------------┤关卡选择├--------------------------┐" << '\n';
            cout << "|                      接下来请选择关卡吧！                    |" << '\n'
                << "├--------------------------------------------------------------┴-" << '\n'
                << "|        ";
            for (int i = 1; i < cnt_level; i++) {
                cout << "关卡" << i;
                if (state[i] == 0) {
                    cout << '(' << "Lock" << ')' << ' ';
                }
                else if (state[i] == 1) {
                    cout << '(' << "Pass" << ')' << ' ';
                }
                else {
                    cout << '(' << "Ongoing" << ')' << ' ';
                }
            }
            cout << "......" << '\n';
            cout << "┕----------------------------------------------------------------" << '\n';
            enter_safe(x, 0, cnt_level - 1);
            while (1) {
                if (state[x] == 0) {//不能玩未解锁关卡
                    system("cls");
                    cout << "┌-------------------------------------------┐" << '\n';
                    cout << "| 你还没有通过前一关卡，先通过前一关再来吧！|" << '\n';
                    cout << "┕-------------------------------------------┙" << '\n';
                    cout << "【请选择关卡】" << '\n';
                    enter_safe(x, 0, cnt_level - 1);
                    continue;
                }
                break;
            }
            level_init(x, index);
            playtimes++;
        }
    }

    return 0;
}