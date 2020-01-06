#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <fstream>

using namespace std;

map<char, vector<string>> GRAMMAR;          //�ķ�
map<char, set<char>> FIRST;                 //���ս����first����
map<char, set<char>> FOLLOW;                //���ս����follow����
set<char> NonterminalSet;				   //���ս������
set<char> TerminalSet;                   //�ս������
map<char, bool> toEpsilon;                  //First�����Ƿ���ڿմ�


void setFOLLOW() {	//����FOLLOW����
	bool update = true;
	while (update) {
		update = false;
		for (char nonTerminalChar : NonterminalSet) { //�������ս������
			int followSize = FOLLOW[nonTerminalChar].size();    //��¼ Follow ���ϳ�ʼ��С
			for (auto iter = GRAMMAR.begin(); iter != GRAMMAR.end(); iter++) {      //���������ķ���auto����������������ʱ����ݱ�����ʼֵ�������Զ�Ϊ�˱���ѡ��ƥ�������
				for (string rightSide : iter->second) {      //�������в���ʽ�Ҳ�
					int i = 0;
					while (i < rightSide.length()) {    //��������ʽ�Ҳ��ַ�
						for (; i < rightSide.length(); i++) {
							if (nonTerminalChar == rightSide[i]) {  //�ҵ��� nonTerminalChar ��ͬ���ַ������ҵ����ս��
								if (i == rightSide.length() - 1) { //�ж��ҵ��ķ��ս���Ƿ����Ҳ����һ���ַ�
									for (char ch : FOLLOW[iter->first]) {   //�Ѳ���ʽ�󲿷��ս���� Follow ���뵽 nonTerminalChar �� Follow ������
										FOLLOW[nonTerminalChar].insert(ch);
									}
								}
								i++;
								break;  //�ҵ��˾�ֹͣ
							}
						}
						for (; i < rightSide.length(); i++) {   //���������ַ�
							if (!isupper(rightSide[i])) {   //������ս��
								FOLLOW[nonTerminalChar].insert(
									rightSide[i]);   //ֱ�ӽ��ս�����뵽 nonTerminalChar �� Follow ������
								break;      //ֱ���˳�
							}
							else {        //�Ƿ��ս��
								for (char ch : FIRST[rightSide[i]]) {   //���÷��ս���� First/{��} ���ϼ��뵽 nonTerminalChar �� Follow ������
									if (ch != '@') {
										FOLLOW[nonTerminalChar].insert(ch);
									}
								}
								if (!toEpsilon[rightSide[i]]) {     //����÷��ս���� First �����в����ڿմ������˳�ѭ��
									break;
								}
								else if (i == rightSide.length() - 1) {        //�÷��ս���� First �����д��ڿմ�����Ϊ�Ҳ����һ���ַ�
									for (char ch : FOLLOW[iter->first]) {
										FOLLOW[nonTerminalChar].insert(ch);     //���󲿷��ս���� Follow ���뵽 nonTerminalChar �� Follow ������
									}
								}
							}
							if (i == rightSide.length() - 1 && rightSide[i] == nonTerminalChar) { //������һ���ַ��� nonTerminalChar
								for (char ch : FOLLOW[iter->first]) {
									FOLLOW[nonTerminalChar].insert(ch); //�Ѳ���ʽ�󲿷��ս���� Follow ���뵽 nonTerminalChar �� Follow ������
								}
							}
						}
					}
				}
			}
			if (followSize != FOLLOW[nonTerminalChar].size()) {
				update = true;
			}
		}
	}
}

void printFOLLOW() {    //��ӡ FOLLOW ����
	cout << "-----------FOLLOW��-----------" << endl;
	for (char chr : NonterminalSet) {
		cout << "FOLLOW(" ;
		cout << chr << ") = { ";
		set<char> follow;
		follow = FOLLOW[chr];
		for (char ch : follow) {
			cout << ch << ",";
		}
		cout << chr << " } ";
		cout << endl;
	}
	cout << endl;
}