#include"fun.h"
void is_ins(string ins_set[], int ins_can_use[]) {
    for (int i = 0; i < 8; i++) {
        if (ins_set[i] == "inbox") {//将ins_set的内容一一对应
            ins_can_use[0] = 1;
        }
        else if (ins_set[i] == "copyfrom") {
            ins_can_use[1] = 1;
        }
        else if (ins_set[i] == "copyto") {
            ins_can_use[2] = 1;
        }
        else if (ins_set[i] == "jump") {
            ins_can_use[3] = 1;
        }
        else if (ins_set[i] == "jumpifzero") {
            ins_can_use[4] = 1;
        }
        else if (ins_set[i] == "add") {
            ins_can_use[5] = 1;
        }
        else if (ins_set[i] == "sub") {
            ins_can_use[6] = 1;
        }
        else if (ins_set[i] == "outbox") {
            ins_can_use[7] = 1;
        }
    }

}
bool IncludeChinese(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        // 检查字符是否为多字节字符的起始字节
        if ((static_cast<unsigned char>(str[i]) & 0xC0) == 0xC0) {
            // 检查是否是有效的 UTF-8 编码
            if ((i + 1 < str.length()) && ((static_cast<unsigned char>(str[i + 1]) & 0xC0) == 0x80)) {
                return true;
            }
        }
    }
    return false;
}

bool is_number(const string& s) {//用来判断一个字符串是否是数字
    for (char const& ch : s) {
        if (!isdigit(ch) && ch != '-') // 如果字符不是数字，则返回false//注意'-'
            return false;
    }
    return true; // 所有字符都是数字，返回true
}

void enter_safe_norange(int& x) {
    while (1) {
        string x_temp;
        cin >> x_temp;//打个补丁,先输入进字符串
        if (IncludeChinese(x_temp)) {//处理是中文的情况
            cout << "错误！你的输入是非法的" << '\n';
            continue;
        }
        if (!is_number(x_temp)) {//处理是字母或浮点数或其他单字符的情况
            cout << "错误！你的输入是非法的" << '\n';
            continue;
        }
        x = stoi(x_temp);
        break;
    }
}

void enter_safe(int& x, int start, int end) {
    while (1) {
        string x_temp;
        cin >> x_temp;//打个补丁,先输入进字符串
        if (IncludeChinese(x_temp)) {//处理是中文的情况
            cout << "错误！你的输入是非法的" << '\n';
            continue;
        }
        if (!is_number(x_temp)) {//处理是字母或浮点数或其他单字符的情况
            cout << "错误！你的输入是非法的" << '\n';
            continue;
        }
        x = stoi(x_temp);
        int feifa = 1;
        for (int i = start; i <= end; i++) {//验证是否是非法输入
            if (x == i) {
                feifa = 0;
            }
        }
        if (feifa == 1) {
            cout << "错误！没有这个选项" << '\n';
            continue;
        }
        break;
    }
}

void read_from_keyboard(instruction input[], int m, string str[], int ptr_input, int level, int x) {//输入指令
    int i = 0;
    string temp_open_file = "memory";
    temp_open_file += to_string(x);
    temp_open_file += ".txt";//为了得到对应关卡存档文件名
    ofstream fout(temp_open_file);
    if (!fout.is_open()) {
        cout << "错误！文件打开失败" << '\n';
        // 处理文件打开失败的情况
        return;
    }
    while (i < m) {
        cin >> input[i].ins;
        if (input[i].ins == "add" || input[i].ins == "sub" || input[i].ins == "copyto" || input[i].ins == "copyfrom" || input[i].ins == "jump" || input[i].ins == "jumpifzero")
        {
            string temp_op_num;
            cin >> temp_op_num;
            if (IncludeChinese(temp_op_num)) {//处理是中文的情况
                cout << "错误！你的输入指令非法" << '\n';
                continue;
            }
            if (!is_number(temp_op_num)) {//处理是字母或浮点数或其他单字符的情况
                cout << "错误！你的输入指令非法" << '\n';
                continue;
            }
            input[i].op_num = stoi(temp_op_num);//有操作数的指令要输入操作数
            fout << input[i].ins << ' ' << input[i].op_num << ' ';//在输入的过程中顺便存档
            i++;
        }
        else if (input[i].ins == "inbox" || input[i].ins == "outbox") {
            fout << input[i].ins << ' ';//在输入的过程中顺便存档
            i++;
        }
        else {
            cout << "错误！你的输入指令非法" << '\n';
            continue;//当且仅当输入的指令和操作数同时正确是才会进入下一条指令输入，否则就要重新输入
        }
        system("cls");
        print(str, ptr_input, m, input);//可以实时看到输入的指令
    }
    fout.close();
}

void read_from_file(int level, instruction input[], int& m, int is_my_file, int x) {//is_my_file是用于判断是自己的文件（2）还是读档（1）
    ifstream fin;
    while (1) {
        if (is_my_file == 2) {//自己输入文件
            cout << "" << '\n';
            cout << "┌------------------┐" << '\n';
            cout << "|请输入你的文件路径|" << '\n';
            cout << "└------------------┘" << '\n';
            string file_path;
            cin >> file_path;
            ifstream test(file_path);
            fin.open(file_path);
        }
        else {//读档
            string temp_open_file = "memory";
            temp_open_file += to_string(x);
            temp_open_file += ".txt";
            fin.open(temp_open_file);//为了得到对应关卡存档文件名
        }

        if (!fin) {
            // 处理文件打开失败的情况
            cout << "错误！文件打开失败" << '\n';
            continue;
        }
        break;
    }
    for (int i = 0; !fin.eof(); i++) {//遍历读入指令
        fin >> input[i].ins;
        if (input[i].ins == "add" || input[i].ins == "sub" || input[i].ins == "copyto" || input[i].ins == "copyfrom" || input[i].ins == "jump" || input[i].ins == "jumpifzero")
        {
            fin >> input[i].op_num;
        }
        m = i;//这里的m引用传入，得到指令的总个数
    }
}

void change_input(int& m, instruction input[], string str[], int ptr_input, int level, int x) {//修改指令的函数
    int is_change = 0, change_ins = 0, num_ins = 0, temp_op_num = -1, is_write = 0;
    string temp_ins;
    cout << "┌-----┤指令确认├------------┐" << '\n';
    cout << "|    是否确认指令           |" << '\n';
    cout << "├---------------------------┤" << '\n'
        << "|就这样 -> 0 | 我要修改 -> 1|" << '\n'
        << "└---------------------------┘" << '\n';
    enter_safe(is_change, 0, 1);
    if (is_change == 1) {
        while (1) {
            system("cls");
            print(str, ptr_input, m, input);
            cout << "┌-----┤指令更改├-------┐" << '\n';
            cout << "|    请进行相应更改    |" << '\n';
            cout << "├----------------------┤" << '\n'
                << "|   我要删除指令 -> 1  |" << '\n'
                << "|   我要添加指令 -> 2  |" << '\n'
                << "|   就这样！ -> 3      |" << '\n'
                << "└----------------------┘" << '\n';
            enter_safe(change_ins, 1, 3);
            switch (change_ins) {
            case 1: {//删除指令
                cout << "-----┤指令删除├-----" << '\n';
                cout << "输入要删除的指令号数" << '\n';
                cout << "----------------------" << '\n';
                enter_safe_norange(num_ins);
                if (num_ins > m) {
                    num_ins = m;
                }
                for (int i = num_ins; i < m; i++) {//直接将input从改变的那一条指令开始向前推一格
                    input[i - 1] = input[i];
                }
                m--;//此时m被设定为引用传入，每删除一条减1
                system("cls");
                print(str, ptr_input, m, input);//更新界面
                break;
            }
            case 2: {//添加指令
                cout << "-----┤指令添加├-----" << '\n';
                cout << "例：指令号数为2" << '\n' << "则添加指令为新指令的第2条" << '\n';
                cout << "请输入要添加的指令号数" << '\n';
                cout << "----------------------" << '\n';
                enter_safe_norange(num_ins);
                if (num_ins > m) {
                    num_ins = m + 1;
                }
                for (int i = m; i > num_ins - 1; i--) {
                    input[i] = input[i - 1];//从加入的位置开始全部向后推一格，腾出一个空间
                }
                cout << "----------------------" << '\n';
                cout << "请输入要添加的指令内容" << '\n';
                cout << "----------------------" << '\n';
                cin >> temp_ins;//将指令填入空出的空间
                input[num_ins - 1].ins = temp_ins;
                if (temp_ins == "add" || temp_ins == "sub" || temp_ins == "copyto" || temp_ins == "copyfrom" || temp_ins == "jump" || temp_ins == "jumpifzero") {
                    enter_safe_norange(temp_op_num);
                    input[num_ins - 1].op_num = temp_op_num;//要填入操作数
                }
                else {
                    input[num_ins - 1].op_num = -1;//不需要操作数的指令令为-1
                }
                m++;//指令数加1
                system("cls");
                print(str, ptr_input, m, input);//更新界面
                break;
            }
            case 3: {//退出
                cout << "┌-----┤保存更改├-------┐" << '\n';
                cout << "|    是否保存更改？    |" << '\n';
                cout << "├----------------------┤" << '\n'
                    << "|   我要保存 -> 1      |" << '\n'
                    << "|   不用保存 -> 0      |" << '\n'
                    << "└----------------------┘" << '\n';//询问是否保存更改到存档
                cin >> is_write;
                if (is_write == 1) {
                    string temp_open_file = "memory";
                    temp_open_file += to_string(x);
                    temp_open_file += ".txt";
                    ofstream fout(temp_open_file);//为了得到对应关卡存档文件名
                    if (!fout.is_open()) {
                        // 处理文件打开失败的情况
                        cout << "错误！文件打开失败" << '\n';
                        return;
                    }
                    for (int i = 0; i < m; i++) {//遍历，将指令输入
                        fout << input[i].ins << ' ';
                        if (input[i].ins == "add" || input[i].ins == "sub" || input[i].ins == "copyto" || input[i].ins == "copyfrom" || input[i].ins == "jump" || input[i].ins == "jumpifzero")
                        {
                            fout << input[i].op_num << ' ';
                        }
                    }
                }
                return;
            }
            default:
                cout << "错误！不合法指令" << '\n';
            }
        }
    }
}

