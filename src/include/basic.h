#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <map>
#include <vector>
#include <iterator>
#include <set>

using namespace std;

#define MAX 200
#define path "./test.txt"

map<char, vector<string>> grammer; //�ķ�
map<int, vector<string>> production;	//����ʽ
map<int, vector<string>> items; //��Ŀ��
string first_non_terminal_symbol; //��ʼ�ķ�
string terminal_symbol;		//�ս��
string non_terminal_symbol;	//���ս��
map<char, set<char>> First; //first����
map<char, set<char>> Follow; //follow����
map<char, bool>To_epsilon;  //first�������Ƿ���ڿմ�

string end_string;
char input_str[30];  //�����ַ���
/*	
	��ʶ��ID	����value = 10
	����NUM		����value = 1
	�����������������value = 0
*/
typedef struct {    
	char data[50];
	int value;
}midsta; //�ʷ�����������ַ���
midsta symbolTables[20];

void display_Set(string title, map<char, set<char>> ma) {  //��ӡ
	cout << title<<"���ϣ�" << endl;
	set<char> temp;
	for (auto it = ma.begin(); it != ma.end(); it++) {
		cout <<"\t"<< title <<"(" << it->first << ") = { ";
		temp = ma[it->first];
		int flag = 1;
		for (char ch : temp) {
			if (flag) {
				cout << ch;
			}
			else {
				cout << ", " << ch;
			}
			flag = 0;
		}
		cout << " }" << endl;
	}
	cout << endl;
}

void display_Str(string title, string str) {
	cout << title<<"\n\t";
	for (int i = 0; i < str.length(); i++) {
		cout << str[i] << " ";
	}
	cout << endl << endl;
}

template<typename T> void display_Map(string title, map<T, vector<string>> ma) {
	cout << title <<"\n";
	for (auto it = ma.begin(); it != ma.end(); it++) {
		cout <<"\t"<< it->first << ": ";
		copy(it->second.begin(), it->second.end(), ostream_iterator<string>(cout, " "));
		cout << endl;
	}
}

void display_struct(string title, int length) {
	cout << title << endl;
	for (int j = 0; j < length; j++) {
		cout << "\t" << symbolTables[j].value << "\t" << symbolTables[j].data << endl;
 	}
}

bool is_in(char ch, string str) {  
	for (int i = 0; i < str.length(); i++) {
		if (ch == str[i]) {
			return false;
		}
	}
	return true;
}

int items_number(int num) {  //map��ĳ��key��value��
	int cnt = 0;
	auto it = items.find(num);
	for (string temp : it->second) {
		cnt++;
	}
	return cnt;
}

int items_key() { //map��key������
	int cnt = 0;
	for (auto it = items.begin(); it != items.end(); it++) {
		cnt++;
	}
	return cnt;
}

bool in_items(int num,string str) { //key���Ƿ���ڸ��ַ���
	auto it = items.find(num);
	for (string temp : it->second) {
		if (temp == str) {
			return true;
		}
	}
	return false;
}


string after_point(int num) {  //�����ַ�
	auto it = items.find(num);
	string expand = "";
	for (string temp : it->second) {
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == '.'&&temp[i+1]!='\0') {
				string::size_type index;
				index = expand.find(temp[i + 1]);
				if (index == string::npos&&is_in(temp[i+1],expand)) {
					expand += temp[i + 1];
				}
			}
		}
	}
	return expand;
}


int find_key(string temp) {
	int len = temp.length() - 1;
	temp.erase(len, 1);
	for (auto it = production.begin(); it != production.end(); it++) {
		for (string str : it->second) {
			if (temp == str) {
				return it->first;
			}
		}
	}
}

char int_char(int i) {
	char ch;
	if (i < 10) {
		ch = (char)(i + '0');;
	}
	else {
		i = i + 87;
		ch = i;
	}
	return ch;
}

int char_int(char ch) {
	int i;
	if (ch < 'a') {
		i = (int)(ch - '0');
	}
	else {
		i = ch - 87;
	}
	return i;
}



