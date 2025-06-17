#include"fun.h"
using namespace std;


void level_init(int x, string index[]) {//����������ڶ�ȡ�ؿ���Ϣ
    string inbox[150];
    string carpet[10];
    string ans[150];
    instruction input[150];
    string output[150];
    int cnt_ans, max_carpet;
    string ins_set[8];
    int ins_can_use[8] = { 0 };
    string str[30];
    str[23] = "����ע�⣺�������;�˳�������w���˳����޷��ص���ǰ״̬����������뵥������������n��������ڵ��²�ִ����Ϻ�����Ӧ״̬����";
    ifstream fin;
    fin.open(index[x]);//�򿪶�Ӧ�Ĺؿ���Ϣ�ļ�
    if (!fin) {
        cout << "û������ؿ�" << '\n';
        return;
    }
    int flag_file = 0;
    system("cls");
    cout << "���ѡ���˵�" << x << "�أ�" << '\n';
    cout << "��-----------�����������No.2��---------------��" << '\n';
    cout << "|     ϵͳ��⵽�пɶ������Ƿ��������     |" << '\n'
        << "��------------------------------------------��" << '\n'
        << "|        �Ҳ������--> 0                   |" << '\n'
        << "|        ��Ҫ����--> 1                     |" << '\n'
        << "|        ʵ�������Լ�д���ļ�...--> 2      |" << '\n'
        << "��------------------------------------------��" << '\n';
    enter_safe(flag_file, 0, 2);
    system("cls");
    for (int i = 18; i < 23; i++) {
        getline(fin, str[i]);//��ȡǰ���йؿ�����
    }
    for (int i = 1; i < 50; i++) {
        if (str[19][i] == '_') {
            str[19][i + 1] = (char)(x + '1' - 1);
            break;
        }
    }
    string temp1;
    string temp2;
    getline(fin, temp1);//���ж�ȡ��temp1
    istringstream iss1(temp1);//������iss����һ�������ݰ��ո�ָ�Ϊ�Ӵ�����
    for (int i = 0; iss1 >> temp2; i++) {//��ʱ����temp2���ڴ���ָ���ַ���
        inbox[i] = temp2;//��ȡinbox
    }
    getline(fin, temp1);
    istringstream iss2(temp1);
    for (int i = 0; iss2 >> temp2; i++) {
        ans[i] = temp2;//��ȡans
    }
    getline(fin, temp1);
    istringstream iss3(temp1);
    for (int i = 0; iss3 >> temp2; i++) {
        ins_set[i] = temp2;//��ȡins_set
    }
    getline(fin, temp1);
    istringstream iss4(temp1);
    for (int i = 0; iss4 >> temp2; i++) {
        carpet[i] = temp2;//��ȡcarpet
    }
    is_ins(ins_set, ins_can_use);//������ָ��ת����������
    fin >> cnt_ans;
    fin >> max_carpet;//�������������̺��
    fin.close();
    establish(str, 0, inbox, max_carpet, carpet, "  ");
    print(str, 0, 0, input);//�������˼����������ָ����֮ǰ��Ҫ��ӡ��ͼ�͹ؿ���Ϣ
    int m;
    cout << "��----------------------����д1��---------------------------��" << '\n';
    cout << "|��������Ҫ�����ָ����(�����Ҫ���������ļ���������)|" << '\n';
    cout << "��--------------------------------------------------------��" << '\n';
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
    int state[100] = { -1 };//����ؿ�״̬��0��lock,1��pass,2�ǿ��Գ���
    ifstream fin("index.txt");//���ﴴ����һ���ؿ�����index�����洢���˹ؿ���Ϣ����Ӧ���ļ�·����ÿ�ν���ؿ�ʱ�ᵼ���index����
    if (!fin) {
        cout << "�����޷��� index �ļ�";
        return 0;
    }
    while (!fin.eof()) {
        fin >> index[cnt_level++];//����������ͬʱcnt_level������ùؿ���
    }
    fin.close();
    cout << "**      **                                         *******                                                            ****     ****                   **      **                " << endl
        << "/**     /**                                        /**////**         ��      ��     ��     Դ     ��     ��           /**/**   **/**                  /**     //                  " << endl
        << "/**     /** **   ** **********   ******   *******  /**   /**   *****   ******  ******  **   ** ******  *****   *****  /**//** ** /**  ******    ***** /**      ** *******   ***** " << endl
        << "/**********/**  /**//**//**//** //////** //**///*  /*******   **///** **////  **////**/**  /**//**//* **///** **///** /** //***  /** //////**  **///**/****** /**//**///** **///**" << endl
        << "/**//////**/**  /** /** /** /**  *******  /**  /*  /**///**  /*******//***** /**   /**/**  /** /** / /**  // /******* /**  //*   /**  ******* /**  // /**///**/** /**  /**/******" << endl
        << "/**     /**/**  /** /** /** /** **////**  /**  /*  /**  //** /**////  /////**/**   /**/**  /** /**   /**   **/**////  /**   /    /** **////** /**   **/**  /**/** /**  /**/**////" << endl
        << "/**     /**//****** *** /** /**//******** ***  /*  /**   //**//****** ****** //****** //******/***   //***** //****** /**        /**//********//***** /**  /**/** ***  /**//******" << endl
        << "//      //  ////// ///  //  //  //////// ///   //  //     //  ////// //////   //////   ////// ///     /////   //////  //         //  ////////  /////  //   // // ///   //  ////// " << endl;
    string text1 = "*��ӭ����������Դ���������磡��ͨ������������̽���������*", text2 = "��-------------��", text3 = "|��ʼ��Ϸ -> 1|", text4 = "|����ؿ� -> 2|", text5 = "|ɾ���ؿ� -> 3|", text6 = "��-------------��";
    cout << setw((width + text1.length()) / 2) << text1 << endl;
    cout << setw((width + text2.length()) / 2) << text2 << '\n';
    cout << setw((width + text3.length()) / 2 - 1) << text3 << '\n';
    cout << setw((width + text4.length()) / 2 - 1) << text4 << '\n';
    cout << setw((width + text5.length()) / 2 - 1) << text5 << '\n';
    cout << setw((width + text6.length()) / 2) << text6 << '\n';//��ӵ���ؿ�����
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
                cout << "��---------�����������No.1 (1)��----------------��" << '\n';
                cout << "| ������һЩ��Ϸ������ָ����Ƿ���Ҫ���һ��|" << '\n';
                cout << "��---------------------------------------------��" << '\n';
                cout << "|  ���ǲ˼�������Ҫ --> 1  |  �Ҳ���Ҫ --> 2  |" << '\n';
                cout << "��---------------------------------------------��" << '\n';
                enter_safe(ishelp, 1, 2);
                if (ishelp == 1) {
                    get_help();
                }
            }
            else {
                cout << "��---------�����������No.1 (2)��------------��" << '\n';
                cout << "|    �Ƿ�������棨�������ؿ�ѡ����棩   |" << '\n'
                    << "��-----------------------------------------��" << '\n'
                    << "|        ��ͻȻ���£��Ȳ����� --> 0       |" << '\n'
                    << "|        ��Ҫ������          --> 1        |" << '\n'
                    << "|        �����˹�����Ҫ��ϰ --> 2       |" << '\n'
                    << "��-----------------------------------------��" << '\n';
                enter_safe(iscontinue, 0, 2);
                if (iscontinue == 0) {
                    cout << "���õģ�See you next time��";
                    break;
                }
                if (iscontinue == 2) {
                    get_help();

                }
            }
            system("cls");
            cout << "��--------------------------�ȹؿ�ѡ���--------------------------��" << '\n';
            cout << "|                      ��������ѡ��ؿ��ɣ�                    |" << '\n'
                << "��--------------------------------------------------------------��-" << '\n'
                << "|        ";
            for (int i = 1; i < cnt_level; i++) {
                cout << "�ؿ�" << i;
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
            cout << "��----------------------------------------------------------------" << '\n';
            enter_safe(x, 0, cnt_level - 1);
            while (1) {
                if (state[x] == 0) {//������δ�����ؿ�
                    system("cls");
                    cout << "��-------------------------------------------��" << '\n';
                    cout << "| �㻹û��ͨ��ǰһ�ؿ�����ͨ��ǰһ�������ɣ�|" << '\n';
                    cout << "��-------------------------------------------��" << '\n';
                    cout << "����ѡ��ؿ���" << '\n';
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