#pragma once
#include"basic.h"
#include<string>
#include<iostream>
using namespace std;

int Isdigit();  //�����ж�
int Isletter(); //�ַ��ж�
int Isunderline(); //�»����ж�
void concat(); //���ӱ�ʶ��
int Isoperator(); //������ж�
char m_getch(); //��ȡ�ַ�
char ch; 
int m_i = 0, i_i = 0, i = 0;  //�ṹ����data���ƶ��������ַ������ƶ����ṹ��������ƶ�

void lex() {  //�ʷ�������
	int k = 0;
	m_getch();
	while (ch != '#') {
		if (Isletter()) {  //�ַ���ͷ��ID
			while (Isunderline() || Isdigit() || Isletter()) { //���»��ߣ����֣���ĸ��β
				concat();
				m_getch();
			}
		}
		else if (Isdigit()) {  //����num
			while (Isdigit()) { //���ֽ�β
				concat();
				m_getch();
			}
		}
		else if(Isoperator()) {  //�������
			m_getch();
		}
		i++;
		m_i = 0;
	}
	//display_struct("�ʷ�������:", i);
};

char m_getch() //��ȡ�ַ�
{
	ch = input_str[i_i];
	i_i++;
	return ch;
}

int Isoperator() { //������ж�
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
		m[i].data[0] = ch;
		return 1;
	}
	else {
		return 0;
	}
}

int Isdigit() {  //�����ж�
	if (ch >= '0' && ch <= '9') {
		return 1;
	}
	else {
		return 0;
	}
}

int Isletter() {  //�ַ��ж�
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
		return 1;
	}
	else {
		return 0;
	}
}

int Isunderline() { //�»����ж�
	if (ch == '_') {
		return 1;
	}
	else {
		return 0;
	}
}

void concat() //ƴ�ӵ���
{
	m[i].data[m_i] = ch;
	m_i++;
	m[i].data[m_i] = '\0';
}