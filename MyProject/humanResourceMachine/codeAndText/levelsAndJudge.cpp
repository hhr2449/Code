#include"fun.h"
int judge_ans(int cnt_ans, int cnt_output, string output[], string ans[]) {
    //判断是否完成
    int flag = 1;
    if (cnt_ans != cnt_output) {//先比较输出数量
        flag = 0;
        cout << "┌--------------------------------------┐" << '\n';
        cout << "|    我们想要" << cnt_ans << "个输出，你却送进了" << cnt_output << "个    |" << '\n';//数量不一样直接报错
        cout << "└--------------------------------------┘" << '\n';
    }
    if (flag == 1) {
        for (int i = 0; i < cnt_ans; ++i) {//再一个个比较输出的内容
            if (output[i] != ans[i]) {
                flag = 0;
                cout << "┌--------------------------------------┤" << '\n';
                cout << "|    第" << i + 1 << "个输出有错误    " << '\n';
                cout << "|    我们想要" << ans[i] << "你却送进了" << output[i] << "    " << '\n';
                cout << "└--------------------------------------┤" << '\n';
                break;
            }
        }
    }
    cout << '\n' << (flag ? "【!SUCCESS!】" : "【FAIL...】") << '\n';
    return flag;
}

void change_state(int x) {
    string change_state = "state";//改变关卡状态
    change_state += to_string(x);
    change_state += ".txt";
    ofstream fout_change;
    fout_change.open(change_state);
    fout_change << 1;
    fout_change.close();
    change_state = "state";
    change_state += to_string(x + 1);
    change_state += ".txt";
    fout_change.open(change_state);
    fout_change << 2;
    fout_change.close();
}

void level(int m, int cnt_ans, int max_carpet, string inbox[], string carpet[], string ans[], instruction input[], string output[], int ins_can_use[], string str[], int level, int flag_file, int x) {
    int ptr_inbox = 0, ptr_input = 0, ptr_output = 0, cnt_output = 0, is_onestep = 0;//ptr_inbox是输入积木的指针,ptr_input是指令指针,ptr_output是输出积木的指针ptr,ptr_carpet是地毯的指针,cnt_output是输出积木的数量
    string hand = "null";//手里没有东西记为null
    establish(str, m, inbox, max_carpet, carpet, hand);//创建地图
    bot_creat(str, 29, hand);//创建机器人
    update_inbox(str, ptr_inbox, inbox);//更新inbox上的内容
    print(str, ptr_input, m, input);//开头先显示一个画面，给输入过程一个比较好的体验

    if (flag_file == 1) {
        read_from_file(level, input, m, 1, x);//从存档读取
        system("cls");
        print(str, ptr_input, m, input);//这是为了处理从文件读入后的界面显示，方便玩家修改input
    }
    else if (flag_file == 2) {
        read_from_file(level, input, m, 2, x);//从玩家给的文件读取
        system("cls");
        print(str, ptr_input, m, input);//这是为了处理从文件读入后的界面显示，方便玩家修改input
    }
    else {
        read_from_keyboard(input, m, str, ptr_input, level, x);//手动输入
    }

    change_input(m, input, str, ptr_input, level, x);//给玩家修改指令的机会

    while (true) {
        if (is_onestep == 1 || is_onestep == 2) {//如果进入了单步调试（is_onestep为1），就会在这里卡住，这时候玩家的输入会成为下一次是单步还是连续的依据
            cout << "┌-----------------------------------------┐" << '\n';
            cout << "|         你已经进入单步调试模式          |" << '\n'
                << "├-----------------------------------------┤" << '\n'
                << "|        已调完，回到连续执行 --> 0       |" << '\n'
                << "|        没调完，继续单步调试 --> 1       |" << '\n'
                << "|        发现代码错误，想修改 --> 2       |" << '\n'
                << "┕-----------------------------------------┙" << '\n';
            print(str, ptr_input, m, input);
            enter_safe(is_onestep, 0, 2);
            if (is_onestep == 2) {
                change_input(m, input, str, ptr_input, level, x);
            }
        }
        if (input[ptr_input].ins == "inbox") {//inbox
            if (inbox[ptr_inbox] == "null") break;//退出条件：inbox时发现没有积木
            move(str, 29, 12, hand, ptr_input, m, input);//移动到传送带
            hand = inbox[ptr_inbox++];//hand更新
            update_inbox(str, ptr_inbox, inbox);//一个积木被拿走了，需要更新inbox
            move(str, 12, 29, hand, ptr_input, m, input);//移动回去

        }

        else if (input[ptr_input].ins == "copyfrom" && ins_can_use[1] == 1) {//copyfrom
            int idx = static_cast<int>(input[ptr_input].op_num);//判断输入操作数是否非整数
            if (input[ptr_input].op_num - idx != 0) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        你的操作数不合法        |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (!(idx >= 0 && idx <= max_carpet)) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        没有这片地毯            |" << '\n';
                cout << "└---------------------------------┘";
                return;
            }
            else if (carpet[idx] == "") {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         地毯里没有东西         |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else {
                move(str, 29, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, hand, ptr_input, m, input);//移动到对应格子
                hand = carpet[idx];//hand拿上对应的值
                move(str, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, 29, hand, ptr_input, m, input);//移动回来
            }
        }

        else if (input[ptr_input].ins == "copyto" && ins_can_use[2] == 1) {//copyto
            int idx = static_cast<int>(input[ptr_input].op_num);
            if (input[ptr_input].op_num - idx != 0) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        你的操作数不合法        |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (!(idx >= 0 && idx <= max_carpet)) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        没有这片地毯            |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (hand == "null") {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         地毯上没有东西         |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else {
                move(str, 29, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, hand, ptr_input, m, input);
                carpet[idx] = hand;
                update_carpet(idx, carpet, str, max_carpet);//copyto要把图上的地毯也更新
                move(str, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, 29, hand, ptr_input, m, input);
            }//没有更新地毯，移动距离不对

        }

        else if (input[ptr_input].ins == "jump" && ins_can_use[3] == 1) {//jump
            int idx = static_cast<int>(input[ptr_input].op_num);//强转成整型，用于判断操作数是否是整数
            if (input[ptr_input].op_num - idx != 0) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        你的操作数不合法        |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (idx == ptr_input + 1) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|       不能跳转到自己身上       |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (!(idx > 0 && idx <= m)) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         没有这条指令！         |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else {
                ptr_input = idx - 1;
                Sleep(100);
                system("cls");

                continue;
            }
        }

        else if (input[ptr_input].ins == "jumpifzero" && ins_can_use[4] == 1) {//jumpifzero
            int idx = static_cast<int>(input[ptr_input].op_num);
            if (input[ptr_input].op_num - idx != 0) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        你的操作数不合法        |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (idx == ptr_input + 1) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|       不能跳转到自己身上       |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (hand == "null") {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         手里没有东西！         |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (!(idx > 0 && idx <= m)) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         没有这条指令！         |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else {
                if (hand == "0") {//多加一个判断
                    ptr_input = idx - 1;
                    Sleep(100);
                    system("cls");

                    continue;
                }
            }
        }

        else if (input[ptr_input].ins == "add" && ins_can_use[5] == 1) {//add
            int idx = static_cast<int>(input[ptr_input].op_num);
            if (input[ptr_input].op_num - idx != 0) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        你的操作数不合法        |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (!(idx >= 0 && idx <= max_carpet)) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        没有这片地毯            |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (hand == "null") {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         手里没有东西！         |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (carpet[idx] == "") {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         地毯上没有东西         |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (!(is_number(carpet[idx]) && is_number(hand))) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|     手和地毯的数字无法对应     |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else {
                move(str, 29, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, hand, ptr_input, m, input);
                hand = to_string(stoi(hand) + stoi(carpet[idx]));//转成数相减再转成字符串
                move(str, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, 29, hand, ptr_input, m, input);
            }
        }

        else if (input[ptr_input].ins == "sub" && ins_can_use[6] == 1) {//sub
            int idx = static_cast<int>(input[ptr_input].op_num);
            if (input[ptr_input].op_num - idx != 0) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        你的操作数不合法        |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (!(idx >= 0 && idx <= max_carpet)) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        没有这片地毯            |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (hand == "null") {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         手里没有东西！         |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (carpet[idx] == "") {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         地毯上没有东西         |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else if (!(is_number(carpet[idx]) && is_number(hand))) {
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|     手或地毯上不是数字          |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            else {
                move(str, 29, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, hand, ptr_input, m, input);
                hand = to_string(stoi(hand) - stoi(carpet[idx]));
                move(str, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, 29, hand, ptr_input, m, input);
            }
        }

        else if (input[ptr_input].ins == "outbox") {
            if (hand == "null") {//手里必须有东西
                cout << "┌---------------------------------┐" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "       |" << '\n';
                cout << "|         手里没有东西！          |" << '\n';
                cout << "└---------------------------------┘" << '\n';
                return;
            }
            move(str, 29, 46, hand, ptr_input, m, input);
            output[ptr_output++] = hand;
            hand = "null";//放完之后手变空
            update_outbox(ptr_output, output, str);
            move(str, 46, 29, hand, ptr_input, m, input);
            cnt_output++;
        }

        else {
            cout << "┌---------------------------------┐" << '\n';
            cout << "┴    Error on instruction " << ptr_input + 1 << "       ┴" << '\n';
            cout << "         你的指令" << input[ptr_input].ins << "不合法    " << '\n';
            cout << "└---------------------------------┘" << '\n';
            return;//其他不合法指令报错
        }
        ptr_input++;
        if (ptr_input == m) {
            break;//退出条件：指令执行完
        }
        if (_kbhit()) { // 检测是否有键盘输入//可以实现不影响主进程的前提下输入
            char ch = _getch(); // 获取键盘输入的字符
            if (ch == 'w') {
                cout << "┌----------------┐" << '\n';
                cout << "|你退出了当前游戏|" << '\n';
                cout << "└----------------┘" << '\n';
                return;
            }
            if (ch == 'n') {
                is_onestep = 1;//用is_onestep判断是否进入单步调试，若为1就是若为0就退出单步
            }
        }
    }

    int flag = judge_ans(cnt_ans, cnt_output, output, ans);

    if (flag == 1) {

        change_state(x);

    }
}