#include"fun.h"
void is_ins(string ins_set[], int ins_can_use[]) {
    for (int i = 0; i < 8; i++) {
        if (ins_set[i] == "inbox") {//��ins_set������һһ��Ӧ
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
        // ����ַ��Ƿ�Ϊ���ֽ��ַ�����ʼ�ֽ�
        if ((static_cast<unsigned char>(str[i]) & 0xC0) == 0xC0) {
            // ����Ƿ�����Ч�� UTF-8 ����
            if ((i + 1 < str.length()) && ((static_cast<unsigned char>(str[i + 1]) & 0xC0) == 0x80)) {
                return true;
            }
        }
    }
    return false;
}

bool is_number(const string& s) {//�����ж�һ���ַ����Ƿ�������
    for (char const& ch : s) {
        if (!isdigit(ch) && ch != '-') // ����ַ��������֣��򷵻�false//ע��'-'
            return false;
    }
    return true; // �����ַ��������֣�����true
}

void enter_safe_norange(int& x) {
    while (1) {
        string x_temp;
        cin >> x_temp;//�������,��������ַ���
        if (IncludeChinese(x_temp)) {//���������ĵ����
            cout << "������������ǷǷ���" << '\n';
            continue;
        }
        if (!is_number(x_temp)) {//��������ĸ�򸡵������������ַ������
            cout << "������������ǷǷ���" << '\n';
            continue;
        }
        x = stoi(x_temp);
        break;
    }
}

void enter_safe(int& x, int start, int end) {
    while (1) {
        string x_temp;
        cin >> x_temp;//�������,��������ַ���
        if (IncludeChinese(x_temp)) {//���������ĵ����
            cout << "������������ǷǷ���" << '\n';
            continue;
        }
        if (!is_number(x_temp)) {//��������ĸ�򸡵������������ַ������
            cout << "������������ǷǷ���" << '\n';
            continue;
        }
        x = stoi(x_temp);
        int feifa = 1;
        for (int i = start; i <= end; i++) {//��֤�Ƿ��ǷǷ�����
            if (x == i) {
                feifa = 0;
            }
        }
        if (feifa == 1) {
            cout << "����û�����ѡ��" << '\n';
            continue;
        }
        break;
    }
}

void read_from_keyboard(instruction input[], int m, string str[], int ptr_input, int level, int x) {//����ָ��
    int i = 0;
    string temp_open_file = "memory";
    temp_open_file += to_string(x);
    temp_open_file += ".txt";//Ϊ�˵õ���Ӧ�ؿ��浵�ļ���
    ofstream fout(temp_open_file);
    if (!fout.is_open()) {
        cout << "�����ļ���ʧ��" << '\n';
        // �����ļ���ʧ�ܵ����
        return;
    }
    while (i < m) {
        cin >> input[i].ins;
        if (input[i].ins == "add" || input[i].ins == "sub" || input[i].ins == "copyto" || input[i].ins == "copyfrom" || input[i].ins == "jump" || input[i].ins == "jumpifzero")
        {
            string temp_op_num;
            cin >> temp_op_num;
            if (IncludeChinese(temp_op_num)) {//���������ĵ����
                cout << "�����������ָ��Ƿ�" << '\n';
                continue;
            }
            if (!is_number(temp_op_num)) {//��������ĸ�򸡵������������ַ������
                cout << "�����������ָ��Ƿ�" << '\n';
                continue;
            }
            input[i].op_num = stoi(temp_op_num);//�в�������ָ��Ҫ���������
            fout << input[i].ins << ' ' << input[i].op_num << ' ';//������Ĺ�����˳��浵
            i++;
        }
        else if (input[i].ins == "inbox" || input[i].ins == "outbox") {
            fout << input[i].ins << ' ';//������Ĺ�����˳��浵
            i++;
        }
        else {
            cout << "�����������ָ��Ƿ�" << '\n';
            continue;//���ҽ��������ָ��Ͳ�����ͬʱ��ȷ�ǲŻ������һ��ָ�����룬�����Ҫ��������
        }
        system("cls");
        print(str, ptr_input, m, input);//����ʵʱ���������ָ��
    }
    fout.close();
}

void read_from_file(int level, instruction input[], int& m, int is_my_file, int x) {//is_my_file�������ж����Լ����ļ���2�����Ƕ�����1��
    ifstream fin;
    while (1) {
        if (is_my_file == 2) {//�Լ������ļ�
            cout << "" << '\n';
            cout << "��------------------��" << '\n';
            cout << "|����������ļ�·��|" << '\n';
            cout << "��------------------��" << '\n';
            string file_path;
            cin >> file_path;
            ifstream test(file_path);
            fin.open(file_path);
        }
        else {//����
            string temp_open_file = "memory";
            temp_open_file += to_string(x);
            temp_open_file += ".txt";
            fin.open(temp_open_file);//Ϊ�˵õ���Ӧ�ؿ��浵�ļ���
        }

        if (!fin) {
            // �����ļ���ʧ�ܵ����
            cout << "�����ļ���ʧ��" << '\n';
            continue;
        }
        break;
    }
    for (int i = 0; !fin.eof(); i++) {//��������ָ��
        fin >> input[i].ins;
        if (input[i].ins == "add" || input[i].ins == "sub" || input[i].ins == "copyto" || input[i].ins == "copyfrom" || input[i].ins == "jump" || input[i].ins == "jumpifzero")
        {
            fin >> input[i].op_num;
        }
        m = i;//�����m���ô��룬�õ�ָ����ܸ���
    }
}

void change_input(int& m, instruction input[], string str[], int ptr_input, int level, int x) {//�޸�ָ��ĺ���
    int is_change = 0, change_ins = 0, num_ins = 0, temp_op_num = -1, is_write = 0;
    string temp_ins;
    cout << "��-----��ָ��ȷ�ϩ�------------��" << '\n';
    cout << "|    �Ƿ�ȷ��ָ��           |" << '\n';
    cout << "��---------------------------��" << '\n'
        << "|������ -> 0 | ��Ҫ�޸� -> 1|" << '\n'
        << "��---------------------------��" << '\n';
    enter_safe(is_change, 0, 1);
    if (is_change == 1) {
        while (1) {
            system("cls");
            print(str, ptr_input, m, input);
            cout << "��-----��ָ����ĩ�-------��" << '\n';
            cout << "|    �������Ӧ����    |" << '\n';
            cout << "��----------------------��" << '\n'
                << "|   ��Ҫɾ��ָ�� -> 1  |" << '\n'
                << "|   ��Ҫ���ָ�� -> 2  |" << '\n'
                << "|   �������� -> 3      |" << '\n'
                << "��----------------------��" << '\n';
            enter_safe(change_ins, 1, 3);
            switch (change_ins) {
            case 1: {//ɾ��ָ��
                cout << "-----��ָ��ɾ����-----" << '\n';
                cout << "����Ҫɾ����ָ�����" << '\n';
                cout << "----------------------" << '\n';
                enter_safe_norange(num_ins);
                if (num_ins > m) {
                    num_ins = m;
                }
                for (int i = num_ins; i < m; i++) {//ֱ�ӽ�input�Ӹı����һ��ָ�ʼ��ǰ��һ��
                    input[i - 1] = input[i];
                }
                m--;//��ʱm���趨Ϊ���ô��룬ÿɾ��һ����1
                system("cls");
                print(str, ptr_input, m, input);//���½���
                break;
            }
            case 2: {//���ָ��
                cout << "-----��ָ����ө�-----" << '\n';
                cout << "����ָ�����Ϊ2" << '\n' << "�����ָ��Ϊ��ָ��ĵ�2��" << '\n';
                cout << "������Ҫ��ӵ�ָ�����" << '\n';
                cout << "----------------------" << '\n';
                enter_safe_norange(num_ins);
                if (num_ins > m) {
                    num_ins = m + 1;
                }
                for (int i = m; i > num_ins - 1; i--) {
                    input[i] = input[i - 1];//�Ӽ����λ�ÿ�ʼȫ�������һ���ڳ�һ���ռ�
                }
                cout << "----------------------" << '\n';
                cout << "������Ҫ��ӵ�ָ������" << '\n';
                cout << "----------------------" << '\n';
                cin >> temp_ins;//��ָ������ճ��Ŀռ�
                input[num_ins - 1].ins = temp_ins;
                if (temp_ins == "add" || temp_ins == "sub" || temp_ins == "copyto" || temp_ins == "copyfrom" || temp_ins == "jump" || temp_ins == "jumpifzero") {
                    enter_safe_norange(temp_op_num);
                    input[num_ins - 1].op_num = temp_op_num;//Ҫ���������
                }
                else {
                    input[num_ins - 1].op_num = -1;//����Ҫ��������ָ����Ϊ-1
                }
                m++;//ָ������1
                system("cls");
                print(str, ptr_input, m, input);//���½���
                break;
            }
            case 3: {//�˳�
                cout << "��-----�ȱ�����ĩ�-------��" << '\n';
                cout << "|    �Ƿ񱣴���ģ�    |" << '\n';
                cout << "��----------------------��" << '\n'
                    << "|   ��Ҫ���� -> 1      |" << '\n'
                    << "|   ���ñ��� -> 0      |" << '\n'
                    << "��----------------------��" << '\n';//ѯ���Ƿ񱣴���ĵ��浵
                cin >> is_write;
                if (is_write == 1) {
                    string temp_open_file = "memory";
                    temp_open_file += to_string(x);
                    temp_open_file += ".txt";
                    ofstream fout(temp_open_file);//Ϊ�˵õ���Ӧ�ؿ��浵�ļ���
                    if (!fout.is_open()) {
                        // �����ļ���ʧ�ܵ����
                        cout << "�����ļ���ʧ��" << '\n';
                        return;
                    }
                    for (int i = 0; i < m; i++) {//��������ָ������
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
                cout << "���󣡲��Ϸ�ָ��" << '\n';
            }
        }
    }
}

