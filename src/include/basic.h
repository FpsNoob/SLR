#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

#define MAX 200
#define path "D://WorkSpace//Cpp//SLR_Parser//SLR//src//test.txt"

map<char, vector<string>> grammer; //�ķ�
map<char, vector<string>> first;
map<char, vector<string>> follow;
string first_non_terminal_symbol; //��ʼ�ķ�
string terminal_symbol;		//�ս��
string non_terminal_symbol;	//���ս��

void display_Str(string title, string str) {
	cout << title << endl;
	for (int i = 0; i < str.length(); i++) {
		cout << str[i] << " ";
	}
	cout << endl << endl;
}

void display_Map(string title, map<char, vector<string>> ma) {
	cout << title << endl;
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


