#pragma once
#include <string>
#include "Linear_Stack.h"
using namespace std;
bool illegal(string &str)//�����ʽ�Ƿ�Ƿ����Ƿ�����true�����򷵻�false
{
	Linear_Stack<char> s;//����ƥ����ջ
	bool state = false;
	if (str[1] == ')' || str[1] == '+' || str[1] == '-' || str[1] == '*' || str[1] == '/')
	{
		state = true;//���ַ�Ϊ�� ) + - * / �����Ϸ�
		goto error;
	}
	if (str[str.length() - 2] == '(' || str[str.length() - 2] == '+' || str[str.length() - 2] == '-' ||
		str[str.length() - 2] == '*' || str[str.length() - 2] == '/')
	{
		state = true;//β�ַ�Ϊ�� ( + - * / �����Ϸ�
		goto error;
	}
	for (int i = 1; i < (str.length() - 1); i++)
	{
		if (str[i]>='0'&&str[i] <='9')
		{
			if (str[i + 1] == '(' || str[i - 1] == ')')
			{
				state = true;//��������")"������"(" ���Ϸ� 
				goto error;
			}
		}
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			if(str[i+1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/')
			{
				state = true;//�����ַ�Ϊ��  + - * / �����Ϸ�
				goto error;
			}
		if (str[i] == '(' )
			s.Push(str[i]);	
		if (str[i] == ')')
		{
			if (str[i + 1] == '('||s.Empty() )//")"��"("���� ���Ϸ�	
			{			
				state = true;//"("��")"����Ӧ ���Ϸ�
				goto error;
			}
			else if (!s.Empty() && s.Top() == '(')//��������������������
				s.Pop();
		}
	}
	if (!s.Empty())
	{
		state = true;//"("��")"����Ӧ ���Ϸ�
		goto error;
	}
	error://������������ ��ǩ
	return state;
}