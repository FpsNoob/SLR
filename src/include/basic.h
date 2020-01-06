#pragma once
#include <iostream>
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
string first_non_terminal_symbol; //��ʼ�ķ�
string terminal_symbol;		//�ս��
string non_terminal_symbol;	//���ս��
map<char, set<char>> First; //first����
map<char, set<char>> Follow; //follow����
map<char, bool>To_epsilon;  //first�������Ƿ���ڿմ�

void display_Set(string title, map<char, set<char>> ma) {  //��ӡ
	cout << title << endl;
	set<char> temp;
	for (auto it = ma.begin(); it != ma.end(); it++) {
		cout <<"\t"<< "First(" << it->first << ") = { ";
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
}

void display_Str(string title, string str) {
	cout << title ;
	for (int i = 0; i < str.length(); i++) {
		cout << str[i] << " ";
	}
	cout << endl << endl;
}

void display_Map(string title, map<char, vector<string>> ma) {
	cout << title ;
	for (auto it = ma.begin(); it != ma.end(); it++) {
		cout << it->first << "->";
		copy(it->second.begin(), it->second.end(), ostream_iterator<string>(cout, " "));
		cout << endl;
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


