#include"fun.h"
void level_import(string level_import[], int cnt_level) {//���ؿ���Ϣ��Դ�ļ����룬������Ӻ�ά���ؿ�
    int a = 1;
    while (a == 1) {
        cout << "���ڵ����" << cnt_level << "��,������ؿ��ļ�·��������Ҫ��ΪANSI��......" << '\n';//��ʾ����Ĺؿ���
        string temp_level;
        cin >> temp_level;
        string temp_memory = "memory";
        temp_memory += to_string(cnt_level);
        temp_memory += ".txt";//ȷ��Ҫ����ؿ���ͬʱ����һ��memoryx�ļ����ڴ����Ӧ�ؿ��Ĵ浵
        string temp_state = "state";
        temp_state += to_string(cnt_level);
        temp_state += ".txt";
        cnt_level++;
        ifstream test(temp_level);//Ҫ���Ӧ����ifstream,ofstream�����´���һ��//����Ƿ��ж�Ӧ�Ĺؿ��ļ�
        if (!test) {
            cout << "����û���ҵ��ؿ��ļ�" << '\n';
            return;
        }
        test.close();
        ofstream fout("index.txt", ios::app);//��������ļ��ķ�ʽ���ں����
        if (!fout) {
            cout << "�����޷��� index �ļ�" << '\n';
            return;
        }
        fout << ' ' << temp_level;//�ؿ���Ϣ��������
        fout.close();
        cout << "����ɹ�" << '\n';
        fout.open(temp_memory);
        fout.close();
        fout.open(temp_state);
        fout << 0;
        fout.close();
        cout << "��--------------------��" << '\n';
        cout << "|���� -> 1||�˳� -> 0|" << '\n';
        cout << "��--------------------��" << '\n';
        enter_safe(a, 0, 1);
    }
}
void level_delect(string index[], int cnt_level) {

    int sn_delect;
    cout << "����������Ҫɾ���Ĺؿ���š�" << '\n';
    enter_safe_norange(sn_delect);
    cout << "��-------------����������ѩ�----------------��" << '\n';
    cout << "|    �ؿ�һ��ɾ���޷��һأ������ؿ���     |" << '\n'
        << "��-----------------------------------------��" << '\n'
        << "|              ��ȷ�� --> 0               |" << '\n'
        << "|              ���˰� --> 1               |" << '\n'
        << "��-----------------------------------------��" << '\n';
    int a;
    enter_safe(a,0,1);
    if (a == 0) {
        ifstream fin_state_temp;
        string in_state = "state";
        in_state += to_string(sn_delect);
        in_state += ".txt";
        int state_temp;
        fin_state_temp.open(in_state);
        fin_state_temp >> state_temp;
        fin_state_temp.close();

        string file_path_temp = index[sn_delect];
        char* file_path = (char*)file_path_temp.data();
        remove(file_path);
        file_path_temp = "memory";
        file_path_temp += to_string(sn_delect);
        file_path_temp += ".txt";
        file_path = (char*)file_path_temp.data();
        remove(file_path);
        file_path_temp = "state";
        file_path_temp += to_string(sn_delect);
        file_path_temp += ".txt";
        file_path = (char*)file_path_temp.data();
        remove(file_path);


        for (int i = sn_delect; i < cnt_level - 1; i++) {
            index[i] = index[i + 1];
        }
        ofstream fout("index.txt");
        if (!fout) {
            cout << "�����޷��� index �ļ�" << '\n';
            return;
        }
        fout << index[0];
        for (int i = 1; i < cnt_level - 1; i++) {
            fout << ' ' << index[i];
        }
        fout.close();
        string oldName;
        string newName;


        for (int i = sn_delect + 1; i < cnt_level; i++) {
            oldName = "memory";
            oldName += to_string(i);
            oldName += ".txt";

            newName = "memory";
            newName += to_string(i - 1);
            newName += ".txt";

            rename(oldName.c_str(), newName.c_str());

            oldName = "state";
            oldName += to_string(i);
            oldName += ".txt";

            newName = "state";
            newName += to_string(i - 1);
            newName += ".txt";
            rename(oldName.c_str(), newName.c_str());
        }

        if (state_temp == 2) {
            ofstream fout_state_temp;
            fout_state_temp.open(in_state);
            fout_state_temp << 2;
            fout_state_temp.close();
        }
    }
    return;

}