#pragma once
#include "basic.h"

void deleteBlank(string& str) {
	int begin = 0;
	begin = str.find(" ", begin);	//���ҿո���str�е�һ�γ��ֵ�λ��
	while (begin != -1){	//��ʾ�ַ����д��ڿո�
		str.replace(begin, 1, "");	//�ÿմ��滻str�д�begin��ʼ��1���ַ�
		begin = str.find(" ", begin);	//���ҿո����滻���str�е�һ�γ��ֵ�λ��
	}
}

void readGrammar() {   //�����ķ�����ʼ���ս����������ս������
	ifstream in;
	in.open(path);	//�����ķ�
	if (!in.is_open()) {
		cout << "Can't open the file" << endl;
		exit(0);	//��������
	}
	string temp;
	bool flag = true;
	cout << "�ķ���" << endl;
	while (getline(in, temp)) {
		deleteBlank(temp);
		cout << temp << endl;
		grammer[temp[0]].push_back(temp.substr(3)); //����ķ�
		if (flag) {
			first_non_terminal_symbol = temp[0]; //��ʼ����
			flag = false;
		}
		if (is_in(temp[0], non_terminal_symbol)) {
			non_terminal_symbol += temp[0]; //���ս��
		}
		for (int i = 3; i < temp.length(); i++) {
			if (!isupper(temp[i]) && (temp[i] != '@')&&is_in(temp[i],terminal_symbol)) { //���Ǵ�д�����ս�����Ϳմ�
				terminal_symbol += temp[i];	//�ս��
			}
		}
	}
	cout << endl;
	display_Str("�ս����", terminal_symbol);
	display_Str("���ս����", non_terminal_symbol);
}


