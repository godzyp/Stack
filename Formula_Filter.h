#pragma once
#include <string>
using namespace std;
string Filter(const string &str)//�ַ�������
/*	���˺��ʣ����1~9�� ��+�� ��-�� ��*�� ��/�� ��(�� ��)�� ��.�� ���� ����	*/
{
	string formula;
	formula.append("#");//������ʽ��ʼ��#
	for (int i = 0; i < (str.length()); i++)
	{
		if (str[i] == '+'||str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')' || str[i] == '.')//���������
			formula.append(str, i, 1);//���������˵��ַ�������������ַ���
		else if (str[i] >= '0' &&  str[i] <= '9')
				//�������ֹ���
				formula.append(str, i, 1);//���������˵��ַ�������������ַ���
		else continue;
	}
	formula.append("#");//������ʽ��ֹ��#
	return formula;//���ع��˺���ַ���
}