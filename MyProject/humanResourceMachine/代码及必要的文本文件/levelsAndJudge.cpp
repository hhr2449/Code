#include"fun.h"
int judge_ans(int cnt_ans, int cnt_output, string output[], string ans[]) {
    //�ж��Ƿ����
    int flag = 1;
    if (cnt_ans != cnt_output) {//�ȱȽ��������
        flag = 0;
        cout << "��--------------------------------------��" << '\n';
        cout << "|    ������Ҫ" << cnt_ans << "���������ȴ�ͽ���" << cnt_output << "��    |" << '\n';//������һ��ֱ�ӱ���
        cout << "��--------------------------------------��" << '\n';
    }
    if (flag == 1) {
        for (int i = 0; i < cnt_ans; ++i) {//��һ�����Ƚ����������
            if (output[i] != ans[i]) {
                flag = 0;
                cout << "��--------------------------------------��" << '\n';
                cout << "|    ��" << i + 1 << "������д���    " << '\n';
                cout << "|    ������Ҫ" << ans[i] << "��ȴ�ͽ���" << output[i] << "    " << '\n';
                cout << "��--------------------------------------��" << '\n';
                break;
            }
        }
    }
    cout << '\n' << (flag ? "��!SUCCESS!��" : "��FAIL...��") << '\n';
    return flag;
}

void change_state(int x) {
    string change_state = "state";//�ı�ؿ�״̬
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
    int ptr_inbox = 0, ptr_input = 0, ptr_output = 0, cnt_output = 0, is_onestep = 0;//ptr_inbox�������ľ��ָ��,ptr_input��ָ��ָ��,ptr_output�������ľ��ָ��ptr,ptr_carpet�ǵ�̺��ָ��,cnt_output�������ľ������
    string hand = "null";//����û�ж�����Ϊnull
    establish(str, m, inbox, max_carpet, carpet, hand);//������ͼ
    bot_creat(str, 29, hand);//����������
    update_inbox(str, ptr_inbox, inbox);//����inbox�ϵ�����
    print(str, ptr_input, m, input);//��ͷ����ʾһ�����棬���������һ���ȽϺõ�����

    if (flag_file == 1) {
        read_from_file(level, input, m, 1, x);//�Ӵ浵��ȡ
        system("cls");
        print(str, ptr_input, m, input);//����Ϊ�˴�����ļ������Ľ�����ʾ����������޸�input
    }
    else if (flag_file == 2) {
        read_from_file(level, input, m, 2, x);//����Ҹ����ļ���ȡ
        system("cls");
        print(str, ptr_input, m, input);//����Ϊ�˴�����ļ������Ľ�����ʾ����������޸�input
    }
    else {
        read_from_keyboard(input, m, str, ptr_input, level, x);//�ֶ�����
    }

    change_input(m, input, str, ptr_input, level, x);//������޸�ָ��Ļ���

    while (true) {
        if (is_onestep == 1 || is_onestep == 2) {//��������˵������ԣ�is_onestepΪ1�����ͻ������￨ס����ʱ����ҵ�������Ϊ��һ���ǵ�����������������
            cout << "��-----------------------------------------��" << '\n';
            cout << "|         ���Ѿ����뵥������ģʽ          |" << '\n'
                << "��-----------------------------------------��" << '\n'
                << "|        �ѵ��꣬�ص�����ִ�� --> 0       |" << '\n'
                << "|        û���꣬������������ --> 1       |" << '\n'
                << "|        ���ִ���������޸� --> 2       |" << '\n'
                << "��-----------------------------------------��" << '\n';
            print(str, ptr_input, m, input);
            enter_safe(is_onestep, 0, 2);
            if (is_onestep == 2) {
                change_input(m, input, str, ptr_input, level, x);
            }
        }
        if (input[ptr_input].ins == "inbox") {//inbox
            if (inbox[ptr_inbox] == "null") break;//�˳�������inboxʱ����û�л�ľ
            move(str, 29, 12, hand, ptr_input, m, input);//�ƶ������ʹ�
            hand = inbox[ptr_inbox++];//hand����
            update_inbox(str, ptr_inbox, inbox);//һ����ľ�������ˣ���Ҫ����inbox
            move(str, 12, 29, hand, ptr_input, m, input);//�ƶ���ȥ

        }

        else if (input[ptr_input].ins == "copyfrom" && ins_can_use[1] == 1) {//copyfrom
            int idx = static_cast<int>(input[ptr_input].op_num);//�ж�����������Ƿ������
            if (input[ptr_input].op_num - idx != 0) {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        ��Ĳ��������Ϸ�        |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (!(idx >= 0 && idx <= max_carpet)) {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        û����Ƭ��̺            |" << '\n';
                cout << "��---------------------------------��";
                return;
            }
            else if (carpet[idx] == "") {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         ��̺��û�ж���         |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else {
                move(str, 29, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, hand, ptr_input, m, input);//�ƶ�����Ӧ����
                hand = carpet[idx];//hand���϶�Ӧ��ֵ
                move(str, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, 29, hand, ptr_input, m, input);//�ƶ�����
            }
        }

        else if (input[ptr_input].ins == "copyto" && ins_can_use[2] == 1) {//copyto
            int idx = static_cast<int>(input[ptr_input].op_num);
            if (input[ptr_input].op_num - idx != 0) {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        ��Ĳ��������Ϸ�        |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (!(idx >= 0 && idx <= max_carpet)) {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        û����Ƭ��̺            |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (hand == "null") {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         ��̺��û�ж���         |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else {
                move(str, 29, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, hand, ptr_input, m, input);
                carpet[idx] = hand;
                update_carpet(idx, carpet, str, max_carpet);//copytoҪ��ͼ�ϵĵ�̺Ҳ����
                move(str, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, 29, hand, ptr_input, m, input);
            }//û�и��µ�̺���ƶ����벻��

        }

        else if (input[ptr_input].ins == "jump" && ins_can_use[3] == 1) {//jump
            int idx = static_cast<int>(input[ptr_input].op_num);//ǿת�����ͣ������жϲ������Ƿ�������
            if (input[ptr_input].op_num - idx != 0) {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        ��Ĳ��������Ϸ�        |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (idx == ptr_input + 1) {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|       ������ת���Լ�����       |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (!(idx > 0 && idx <= m)) {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         û������ָ�         |" << '\n';
                cout << "��---------------------------------��" << '\n';
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
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        ��Ĳ��������Ϸ�        |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (idx == ptr_input + 1) {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|       ������ת���Լ�����       |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (hand == "null") {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         ����û�ж�����         |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (!(idx > 0 && idx <= m)) {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         û������ָ�         |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else {
                if (hand == "0") {//���һ���ж�
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
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        ��Ĳ��������Ϸ�        |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (!(idx >= 0 && idx <= max_carpet)) {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        û����Ƭ��̺            |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (hand == "null") {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         ����û�ж�����         |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (carpet[idx] == "") {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         ��̺��û�ж���         |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (!(is_number(carpet[idx]) && is_number(hand))) {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|     �ֺ͵�̺�������޷���Ӧ     |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else {
                move(str, 29, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, hand, ptr_input, m, input);
                hand = to_string(stoi(hand) + stoi(carpet[idx]));//ת���������ת���ַ���
                move(str, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, 29, hand, ptr_input, m, input);
            }
        }

        else if (input[ptr_input].ins == "sub" && ins_can_use[6] == 1) {//sub
            int idx = static_cast<int>(input[ptr_input].op_num);
            if (input[ptr_input].op_num - idx != 0) {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        ��Ĳ��������Ϸ�        |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (!(idx >= 0 && idx <= max_carpet)) {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|        û����Ƭ��̺            |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (hand == "null") {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         ����û�ж�����         |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (carpet[idx] == "") {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|         ��̺��û�ж���         |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else if (!(is_number(carpet[idx]) && is_number(hand))) {
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "    |" << '\n';
                cout << "|     �ֻ��̺�ϲ�������          |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            else {
                move(str, 29, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, hand, ptr_input, m, input);
                hand = to_string(stoi(hand) - stoi(carpet[idx]));
                move(str, 33 - 5 * (max_carpet + 1) / 2 + 5 * idx, 29, hand, ptr_input, m, input);
            }
        }

        else if (input[ptr_input].ins == "outbox") {
            if (hand == "null") {//��������ж���
                cout << "��---------------------------------��" << '\n';
                cout << "|    Error on instruction " << ptr_input + 1 << "       |" << '\n';
                cout << "|         ����û�ж�����          |" << '\n';
                cout << "��---------------------------------��" << '\n';
                return;
            }
            move(str, 29, 46, hand, ptr_input, m, input);
            output[ptr_output++] = hand;
            hand = "null";//����֮���ֱ��
            update_outbox(ptr_output, output, str);
            move(str, 46, 29, hand, ptr_input, m, input);
            cnt_output++;
        }

        else {
            cout << "��---------------------------------��" << '\n';
            cout << "��    Error on instruction " << ptr_input + 1 << "       ��" << '\n';
            cout << "         ���ָ��" << input[ptr_input].ins << "���Ϸ�    " << '\n';
            cout << "��---------------------------------��" << '\n';
            return;//�������Ϸ�ָ���
        }
        ptr_input++;
        if (ptr_input == m) {
            break;//�˳�������ָ��ִ����
        }
        if (_kbhit()) { // ����Ƿ��м�������//����ʵ�ֲ�Ӱ�������̵�ǰ��������
            char ch = _getch(); // ��ȡ����������ַ�
            if (ch == 'w') {
                cout << "��----------------��" << '\n';
                cout << "|���˳��˵�ǰ��Ϸ|" << '\n';
                cout << "��----------------��" << '\n';
                return;
            }
            if (ch == 'n') {
                is_onestep = 1;//��is_onestep�ж��Ƿ���뵥�����ԣ���Ϊ1������Ϊ0���˳�����
            }
        }
    }

    int flag = judge_ans(cnt_ans, cnt_output, output, ans);

    if (flag == 1) {

        change_state(x);

    }
}