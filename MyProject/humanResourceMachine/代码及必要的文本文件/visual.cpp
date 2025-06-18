#include"fun.h"
void establish(string str[], int m, string inbox[], int max_carpet, string carpet[], string hand) {
	int carpet_num = max_carpet + 1;
	str[0] = "      +---+                                         +---+        |      ===== CODE =====";
	str[1] = "IN    |   |                                         |   |   OUT  |        ";
	str[2] = "      +---+                                         +---+        |        ";
	str[3] = "      +---+                                         +---+        |        ";
	str[4] = "      |   |                                         |   |        |        ";
	for (int i = 5; i < 17; i += 3)
	{
		str[i] = str[2];
		str[i + 1] = str[3];
		str[i + 2] = str[4];
	}//基本的框架
	str[17] = str[3];
	//建立地毯
	int start = 31 - 5 * carpet_num / 2;//地毯起点
	for (int i = start; i < start + 5 * carpet_num; i += 5) {
		str[11][i] = '+';
		str[11][i + 1] = '-';
		str[11][i + 2] = '-';
		str[11][i + 3] = '-';
		str[11][i + 4] = '+';
	}
	for (int i = start; i < start + 5 * carpet_num; i += 5) {
		str[12][i] = '|';
		str[12][i + 4] = '|';
	}
	for (int i = start; i < start + 5 * carpet_num; i += 5) {
		str[13][i] = '+';
		str[13][i + 1] = '-';
		str[13][i + 2] = '-';
		str[13][i + 3] = '-';
		str[13][i + 4] = '+';
	}//for循环创建地毯轮廓
	for (int i = 0; i < carpet_num; i++) {
		str[14][start + 2 + 5 * i] = '0' + i;//地毯序号
	}
	for (int idx = 0; idx < carpet_num; idx++) {//还是应该考虑地毯初始就有东西的情况//遍历地毯，将其填入
		switch (carpet[idx].length()) {
		case 1:
			str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx] = carpet[idx][0];//注意位置坐标换算
			break;
		case 2:
			str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx - 1] = carpet[idx][0];
			str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx] = carpet[idx][1];
			break;
		case 3:
			str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx - 1] = carpet[idx][0];
			str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx] = carpet[idx][1];
			str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx + 1] = carpet[idx][2];
		}
	}
}

void bot_creat(string str[], int spot_left, string hand) {//认为机器人在同一水平线上移动，上到0，下到9，左到spot_left，右到spot_left+4//创建一个机器人
	if (hand == "null") {                               //把机器人看成一个方块，创建和移动都以这个方块为单位进行
		for (int i = 0; i < 5; i++)
		{
			str[4][spot_left + i] = '-';//由于bot_creat除了开始创建地图时，都是在move函数中和清除连用的，所以这里似乎不用考虑清除
		}
		str[5][spot_left] = '|';
		str[5][spot_left + 1] = '@';
		str[5][spot_left + 3] = '@';
		str[5][spot_left + 4] = '|';
		str[6][spot_left + 2] = '+';
		str[7][spot_left] = '/';
		str[7][spot_left + 4] = '\\';
		str[8][spot_left + 1] = '|';
		str[8][spot_left + 3] = '|';
	}
	else {//考虑了手中有东西和没有东西的情况
		str[0][spot_left] = '+';
		str[0][spot_left + 1] = '-';
		str[0][spot_left + 2] = '-';
		str[0][spot_left + 3] = '-';
		str[0][spot_left + 4] = '+';
		str[1][spot_left] = '|';
		switch (hand.length()) {
		case 1:
			str[1][spot_left + 2] = hand[0];
			break;
		case 2:
			str[1][spot_left + 1] = hand[0];
			str[1][spot_left + 2] = hand[1];
			break;
		case 3:
			str[1][spot_left + 1] = hand[0];
			str[1][spot_left + 2] = hand[1];
			str[1][spot_left + 3] = hand[2];
		}
		str[1][spot_left + 4] = '|';
		str[2][spot_left] = '+';
		str[2][spot_left + 1] = '-';
		str[2][spot_left + 2] = '-';
		str[2][spot_left + 3] = '-';
		str[2][spot_left + 4] = '+';
		str[3][spot_left] = '@';
		str[3][spot_left + 4] = '@';
		for (int i = 0; i < 5; i++)
		{
			str[4][spot_left + i] = '-';
		}
		str[5][spot_left] = '|';
		str[5][spot_left + 1] = '@';
		str[5][spot_left + 3] = '@';
		str[5][spot_left + 4] = '|';
		str[6][spot_left + 2] = '+';
		str[7][spot_left] = '/';
		str[7][spot_left + 4] = '\\';
		str[8][spot_left + 1] = '|';
		str[8][spot_left + 3] = '|';
	}
}

void move(string str[], int left_spot_start, int left_spot_end, string hand, int ptr_input, int m, instruction input[]) {//机器人在两个位置间的移动
	if (left_spot_start > left_spot_end) {
		for (int i = 0; i < left_spot_start - left_spot_end; i++) {//通过循环创建机器人实现其位置的改变
			for (int p = 0; p < 10; p++) {
				for (int j = 0; j < 5; j++) {
					str[p][left_spot_start - i + 1 + j] = '  ';//把原先位置清空
				}
			}
			bot_creat(str, left_spot_start - i, hand);//在新的位置创建机器人
			print(str, ptr_input, m, input);//打印
			Sleep(60);
			system("cls");//清屏
		}
	}
	else {//考虑左移和右移两种情况
		for (int i = 0; i < left_spot_end - left_spot_start; i++) {
			for (int p = 0; p < 10; p++) {
				for (int j = 0; j < 5; j++) {
					str[p][left_spot_start + i - 1 + j] = '  ';
				}
			}
			bot_creat(str, left_spot_start + i, hand);
			print(str, ptr_input, m, input);
			Sleep(60);
			system("cls");
		}
	}
}

void update_inbox(string str[], int ptr_inbox, string inbox[]) {//更新inbox中的内容
	for (int i = 0; i < 6; i++) {//先把对应位置清空
		str[1 + 3 * i][7] = '  ';
		str[1 + 3 * i][8] = '  ';
		str[1 + 3 * i][9] = '  ';
	}
	for (int i = 0; i < 6; i++) {
		if (inbox[ptr_inbox + i] != "null") {//填入inbox中的东西，直到inbox中的东西填完或者填满六个
			switch (inbox[ptr_inbox + i].length()) {
			case 1:
				str[1 + 3 * i][8] = inbox[ptr_inbox + i][0];
				break;
			case 2:
				str[1 + 3 * i][7] = inbox[ptr_inbox + i][0];
				str[1 + 3 * i][8] = inbox[ptr_inbox + i][1];
				break;
			case 3:
				str[1 + 3 * i][7] = inbox[ptr_inbox + i][0];
				str[1 + 3 * i][8] = inbox[ptr_inbox + i][1];
				str[1 + 3 * i][9] = inbox[ptr_inbox + i][2];
			}
		}
	};//更新传送带
}

void update_outbox(int ptr_outbox, string outbox[], string str[]) {//填outbox的内容
	for (int i = 0; i < 6; i++) {
		str[1 + 3 * i][53] = '  ';
		str[1 + 3 * i][54] = '  ';
		str[1 + 3 * i][55] = '  ';
	}
	for (int i = 0; i < 6 && ptr_outbox - i - 1 >= 0; i++) {
		switch (outbox[ptr_outbox - i - 1].length()) {//放入一个，ptr_outbox更新后格子也要更新,此时ptr指向空格，并且应该向前
		case 1:
			str[1 + 3 * i][54] = outbox[ptr_outbox - i - 1][0];
			break;
		case 2:
			str[1 + 3 * i][53] = outbox[ptr_outbox - i - 1][0];
			str[1 + 3 * i][54] = outbox[ptr_outbox - i - 1][1];
			break;
		case 3:
			str[1 + 3 * i][53] = outbox[ptr_outbox - i - 1][0];
			str[1 + 3 * i][54] = outbox[ptr_outbox - i - 1][1];
			str[1 + 3 * i][55] = outbox[ptr_outbox - i - 1][2];
		}
	}
}

void update_carpet(int idx, string carpet[], string str[], int max_carpet) {//填地毯的内容
	for (int i = 0; i < 3; i++) {
		str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx - 1 + i] = '  ';
	}
	switch (carpet[idx].length()) {
	case 1:
		str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx] = carpet[idx][0];//注意位置坐标换算
		break;
	case 2:
		str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx - 1] = carpet[idx][0];
		str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx] = carpet[idx][1];
		break;
	case 3:
		str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx - 1] = carpet[idx][0];
		str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx] = carpet[idx][1];
		str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx + 1] = carpet[idx][2];
	}
}

void print(string str[], int ptr_input, int m, instruction input[]) {//打印地图//任何改变都在str[]中运用赋值操作进行，再打印出来呈现

	for (int i = 0; i < 24; i++)
	{
		cout << str[i];
		if (i >= 1 && i <= m)//第1到第m行是指令//指令受到画面篇幅限制
		{
			if (input[i - 1].op_num == -1) {//op_num默认为-1（没有操作数是-1）
				if (i == ptr_input + 1) {
					cout << '>' << ' ' << i << ' ' << input[i - 1].ins << '\n';//指向当前指令
				}
				else {
					cout << "  " << i << ' ' << input[i - 1].ins << '\n';
				}
			}
			else {//有操作数
				if (i == ptr_input + 1) {
					cout << '>' << ' ' << i << ' ' << input[i - 1].ins << ' ' << input[i - 1].op_num << '\n';//指向当前指令
				}
				else {
					cout << "  " << i << ' ' << input[i - 1].ins << ' ' << input[i - 1].op_num << '\n';
				}
			}
		}
		else {
			cout << '\n';//没有指令也需要转行
		}
	}
}