#pragma once
#pragma once
#include "basic.h"
#include "SqStack.h"
#include "SLRparsing.h"

string now = ""; //��¼��ǰ״̬
/*��ȡ�ַ�*/
int ip = 0;
string advance() {  //��ȡ�ַ������еĵ���
	return symbolTables[ip].data;
}
int advance_value() {  //��ȡ�ַ������еĵ���
	return symbolTables[ip].value;
}

int char_int(char ch) {
	int i = ch - '0';
	return i;
}


string find_index(string state, string a, int value) {
	string action = "error";
	if (value == 10) {
		a = "i";
	}
	if (value == 1) {
		a = "n";
	}
	for (int i = 0; i < slr_cnt; i++) {
		if (char_int(state[0]) == slr[i].state && a[0]==slr[i].row) {
			action = slr[i].action;
		}
	}
	return action;
}

int action_goto(string s, string a, int value) {
	now = find_index(s, a, value);
	string action = now.substr(0, 1);
	if (action == "s") { //�ƽ�
		return 1;
	}
	else if (action == "r") { //��Լ
		return 2;
	}
	else if (action == "a") { //����
		return 3;
	}
	else if (action == "e") { //����
		return 4;
	}
	else {  //ת��
		return 5;
	}
}

void Parsing_SLR() {   //gbk+6*h#
	SqStack<string>* st;
	InitStack(st);
	Push(st, string("0"));	//��״̬0��ջ
	string state;
	string a;
	bool flag = true;
	bool ok = false;
	while (flag) {
		GetTop(st, state); //��ջջ��״̬
		a = advance();
		int res = action_goto(state, a, advance_value());
		int len=0;
 		auto it=production.find(1);
		string css="";
		switch (res) {
		case 1:Push(st, a); Push(st, now.substr(1,1)); ip++; break; //�ƽ�
		case 2:
			it = production.find(char_int(now[1]));
			for (string temp : it->second) {
				len = temp.length() - 3;
				css = temp;
			}
			for (int j = 0; j < 2 * len; j++) {
				Pop(st, state);
			}
			GetTop(st, state);
			Push(st, css.substr(0,1));//����ʽ�������ջ
			action_goto(state, css.substr(0, 1), 0); //��ù�ͨ���
			Push(st, now.substr(0,1));//goto�����ջ
			break;
		case 3:flag = false; ok = true; break; //����
		case 4:flag = false; ok = false; break;//����
		}
	}
	if (ok == true) {
		cout << "��ȷ�ı��ʽ" << endl;
	}
	else {
		cout << "����ı��ʽ" << endl;
	}
}