#pragma once
#include "basic.h"


void setFollow() {	//����FOLLOW����
	bool update = true;
	while (update) {
		update = false;
		for (char nonTerminalChar : non_terminal_symbol) { //�������ս������
			int followSize = Follow[nonTerminalChar].size();    //��¼ Follow ���ϳ�ʼ��С
			for (auto iter = grammer.begin(); iter != grammer.end(); iter++) {      //���������ķ���auto����������������ʱ����ݱ�����ʼֵ�������Զ�Ϊ�˱���ѡ��ƥ�������
				for (string rightSide : iter->second) {      //�������в���ʽ�Ҳ�
					int i = 0;
					while (i < rightSide.length()) {    //��������ʽ�Ҳ��ַ�
						for (; i < rightSide.length(); i++) {
							if (nonTerminalChar == rightSide[i]) {  //�ҵ��� nonTerminalChar ��ͬ���ַ������ҵ����ս��
								if (i == rightSide.length() - 1) { //�ж��ҵ��ķ��ս���Ƿ����Ҳ����һ���ַ�
									for (char ch : Follow[iter->first]) {   //�Ѳ���ʽ�󲿷��ս���� Follow ���뵽 nonTerminalChar �� Follow ������
										Follow[nonTerminalChar].insert(ch);
									}
								}
								i++;
								break;  //�ҵ��˾�ֹͣ
							}
						}
						for (; i < rightSide.length(); i++) {   //���������ַ�
							if (!isupper(rightSide[i])) {   //������ս��
								Follow[nonTerminalChar].insert(
									rightSide[i]);   //ֱ�ӽ��ս�����뵽 nonTerminalChar �� Follow ������
								break;      //ֱ���˳�
							}
							else {        //�Ƿ��ս��
								for (char ch : First[rightSide[i]]) {   //���÷��ս���� First/{��} ���ϼ��뵽 nonTerminalChar �� Follow ������
									if (ch != '@') {
										Follow[nonTerminalChar].insert(ch);
									}
								}
								if (!To_epsilon[rightSide[i]]) {     //����÷��ս���� First �����в����ڿմ������˳�ѭ��
									break;
								}
								else if (i == rightSide.length() - 1) {        //�÷��ս���� First �����д��ڿմ�����Ϊ�Ҳ����һ���ַ�
									for (char ch : Follow[iter->first]) {
										Follow[nonTerminalChar].insert(ch);     //���󲿷��ս���� Follow ���뵽 nonTerminalChar �� Follow ������
									}
								}
							}
							if (i == rightSide.length() - 1 && rightSide[i] == nonTerminalChar) { //������һ���ַ��� nonTerminalChar
								for (char ch : Follow[iter->first]) {
									Follow[nonTerminalChar].insert(ch); //�Ѳ���ʽ�󲿷��ս���� Follow ���뵽 nonTerminalChar �� Follow ������
								}
							}
						}
					}
				}
			}
			if (followSize != Follow[nonTerminalChar].size()) {
				update = true;
			}
		}
	}
	display_Set("Follow", Follow);
}

