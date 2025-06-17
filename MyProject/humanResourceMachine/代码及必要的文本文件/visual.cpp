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
	}//�����Ŀ��
	str[17] = str[3];
	//������̺
	int start = 31 - 5 * carpet_num / 2;//��̺���
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
	}//forѭ��������̺����
	for (int i = 0; i < carpet_num; i++) {
		str[14][start + 2 + 5 * i] = '0' + i;//��̺���
	}
	for (int idx = 0; idx < carpet_num; idx++) {//����Ӧ�ÿ��ǵ�̺��ʼ���ж��������//������̺����������
		switch (carpet[idx].length()) {
		case 1:
			str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx] = carpet[idx][0];//ע��λ�����껻��
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

void bot_creat(string str[], int spot_left, string hand) {//��Ϊ��������ͬһˮƽ�����ƶ����ϵ�0���µ�9����spot_left���ҵ�spot_left+4//����һ��������
	if (hand == "null") {                               //�ѻ����˿���һ�����飬�������ƶ������������Ϊ��λ����
		for (int i = 0; i < 5; i++)
		{
			str[4][spot_left + i] = '-';//����bot_creat���˿�ʼ������ͼʱ��������move�����к�������õģ����������ƺ����ÿ������
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
	else {//�����������ж�����û�ж��������
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

void move(string str[], int left_spot_start, int left_spot_end, string hand, int ptr_input, int m, instruction input[]) {//������������λ�ü���ƶ�
	if (left_spot_start > left_spot_end) {
		for (int i = 0; i < left_spot_start - left_spot_end; i++) {//ͨ��ѭ������������ʵ����λ�õĸı�
			for (int p = 0; p < 10; p++) {
				for (int j = 0; j < 5; j++) {
					str[p][left_spot_start - i + 1 + j] = '  ';//��ԭ��λ�����
				}
			}
			bot_creat(str, left_spot_start - i, hand);//���µ�λ�ô���������
			print(str, ptr_input, m, input);//��ӡ
			Sleep(60);
			system("cls");//����
		}
	}
	else {//�������ƺ������������
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

void update_inbox(string str[], int ptr_inbox, string inbox[]) {//����inbox�е�����
	for (int i = 0; i < 6; i++) {//�ȰѶ�Ӧλ�����
		str[1 + 3 * i][7] = '  ';
		str[1 + 3 * i][8] = '  ';
		str[1 + 3 * i][9] = '  ';
	}
	for (int i = 0; i < 6; i++) {
		if (inbox[ptr_inbox + i] != "null") {//����inbox�еĶ�����ֱ��inbox�еĶ������������������
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
	};//���´��ʹ�
}

void update_outbox(int ptr_outbox, string outbox[], string str[]) {//��outbox������
	for (int i = 0; i < 6; i++) {
		str[1 + 3 * i][53] = '  ';
		str[1 + 3 * i][54] = '  ';
		str[1 + 3 * i][55] = '  ';
	}
	for (int i = 0; i < 6 && ptr_outbox - i - 1 >= 0; i++) {
		switch (outbox[ptr_outbox - i - 1].length()) {//����һ����ptr_outbox���º����ҲҪ����,��ʱptrָ��ո񣬲���Ӧ����ǰ
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

void update_carpet(int idx, string carpet[], string str[], int max_carpet) {//���̺������
	for (int i = 0; i < 3; i++) {
		str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx - 1 + i] = '  ';
	}
	switch (carpet[idx].length()) {
	case 1:
		str[12][33 - 5 * (max_carpet + 1) / 2 + 5 * idx] = carpet[idx][0];//ע��λ�����껻��
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

void print(string str[], int ptr_input, int m, instruction input[]) {//��ӡ��ͼ//�κθı䶼��str[]�����ø�ֵ�������У��ٴ�ӡ��������

	for (int i = 0; i < 24; i++)
	{
		cout << str[i];
		if (i >= 1 && i <= m)//��1����m����ָ��//ָ���ܵ�����ƪ������
		{
			if (input[i - 1].op_num == -1) {//op_numĬ��Ϊ-1��û�в�������-1��
				if (i == ptr_input + 1) {
					cout << '>' << ' ' << i << ' ' << input[i - 1].ins << '\n';//ָ��ǰָ��
				}
				else {
					cout << "  " << i << ' ' << input[i - 1].ins << '\n';
				}
			}
			else {//�в�����
				if (i == ptr_input + 1) {
					cout << '>' << ' ' << i << ' ' << input[i - 1].ins << ' ' << input[i - 1].op_num << '\n';//ָ��ǰָ��
				}
				else {
					cout << "  " << i << ' ' << input[i - 1].ins << ' ' << input[i - 1].op_num << '\n';
				}
			}
		}
		else {
			cout << '\n';//û��ָ��Ҳ��Ҫת��
		}
	}
}