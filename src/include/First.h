#pragma once
#include "basic.h"

int FirstSize;

void setFirst() {  //��ȡfirst��
	bool flag = true;
	while (flag) {
		flag = false;
		for (char nonte_Char : non_terminal_symbol) { //�������ս������ʽ����ߣ�
			FirstSize = First[nonte_Char].size(); //��¼���ս������
			for (string RightSide : grammer[nonte_Char]) { //��������ʽ���Ҳ�
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
							if (temp == '@') { //���ڿմ�
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
	for (char nonte_Char : non_terminal_symbol) { //�������ս������
		//���ҵ��Ħ��ǽ����ַ�end()������0�����򷵻�To_epsilon[nonte_Char]=1
		To_epsilon[nonte_Char] = First[nonte_Char].find('@') != First[nonte_Char].end();
	}
	display_Set("First���ϣ�", First);
}

