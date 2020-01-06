#pragma once
#include"Lex.h"
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <fstream>

using namespace std;

map<char, vector<string>> Grammer;          //�ķ�
map<char, set<char>> First; //first����
map<char, set<char>> Follow; //follow����
map<char, bool>To_epsilon;  //first�������Ƿ���ڿմ�
set<char> NonTerminalSet; //���ս������
set<char> TerminalSet; //�ս������
int FirstSize;

void Getfirst() {  //��ȡfirst��
	bool flag = true;
	while (flag) {
		flag = false;
		for (char nonte_Char : NonTerminalSet) { //�������ս������ʽ����ߣ�
			FirstSize = First[nonte_Char].size(); //��¼���ս������
			for (string RightSide : Grammer[nonte_Char]) { //��������ʽ���Ҳ�
				for (char ch : RightSide) {  //��������ʽ�Ҳ��������ַ�
					//���Ǵ�д��ĸ��������ս��,˵���ò���ʽ�������
					if (!isupper(ch)) { 
						//�����ս��ַ����뵽���ս����first������
						First[nonte_Char].insert(ch);
						break;  //����ѭ��
					}
					else {
						bool Epsilon_falg = false; //first���Ƿ���ڿ�
						for (char temp : First[ch]) {
							if (temp == '��') { //���ڿմ�
								Epsilon_falg = true;
							}
							//�����ս��ch��first���ϼ��뵽���ս����first������
							First[nonte_Char].insert(temp); 
						}
						if (!Epsilon_falg) {//��������ڿմ�
							break;
						}
					}
				}
			}
			if (FirstSize != First[nonte_Char].size()) {  //���ս��û�б�����
				flag = true;
			}
		}
	}
	for (char nonte_Char : NonTerminalSet) { //�������ս������
		//���ҵ��Ħ��ǽ����ַ�end()������0�����򷵻�To_epsilon[nonte_Char]=1
		To_epsilon[nonte_Char] = First[nonte_Char].find('��') != First[nonte_Char].end();
	}
}
void printfirst() {  //��ӡ
	cout << "First����" << endl;
	for (char ch_f : NonTerminalSet) { //ȡ���ս������
		cout << "First(";
		cout << ch_f << ") = { ";
		set<char> print_first;
		print_first = First[ch_f];  //ȡÿ�����ս����first��
		for (char ch : print_first) {
			cout << ch << ",";
		}
		cout <<" }"<< endl;
	}
}
