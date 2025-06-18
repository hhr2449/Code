#include"fun.h"
void level_import(string level_import[], int cnt_level) {//将关卡信息和源文件分离，方便添加和维护关卡
    int a = 1;
    while (a == 1) {
        cout << "现在导入第" << cnt_level << "关,请输入关卡文件路径（编码要求为ANSI）......" << '\n';//提示导入的关卡数
        string temp_level;
        cin >> temp_level;
        string temp_memory = "memory";
        temp_memory += to_string(cnt_level);
        temp_memory += ".txt";//确认要导入关卡的同时创建一个memoryx文件用于储存对应关卡的存档
        string temp_state = "state";
        temp_state += to_string(cnt_level);
        temp_state += ".txt";
        cnt_level++;
        ifstream test(temp_level);//要检查应该用ifstream,ofstream会重新创建一个//检查是否有对应的关卡文件
        if (!test) {
            cout << "错误：没有找到关卡文件" << '\n';
            return;
        }
        test.close();
        ofstream fout("index.txt", ios::app);//这里输出文件的方式是在后添加
        if (!fout) {
            cout << "错误：无法打开 index 文件" << '\n';
            return;
        }
        fout << ' ' << temp_level;//关卡信息导入索引
        fout.close();
        cout << "导入成功" << '\n';
        fout.open(temp_memory);
        fout.close();
        fout.open(temp_state);
        fout << 0;
        fout.close();
        cout << "┌--------------------┐" << '\n';
        cout << "|继续 -> 1||退出 -> 0|" << '\n';
        cout << "┕--------------------┙" << '\n';
        enter_safe(a, 0, 1);
    }
}
void level_delect(string index[], int cnt_level) {

    int sn_delect;
    cout << "【请输入你要删除的关卡序号】" << '\n';
    enter_safe_norange(sn_delect);
    cout << "┌-------------┤善意的提醒├----------------┐" << '\n';
    cout << "|    关卡一旦删除无法找回，请慎重考虑     |" << '\n'
        << "├-----------------------------------------┤" << '\n'
        << "|              我确定 --> 0               |" << '\n'
        << "|              算了吧 --> 1               |" << '\n'
        << "┕-----------------------------------------┙" << '\n';
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
            cout << "错误：无法打开 index 文件" << '\n';
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