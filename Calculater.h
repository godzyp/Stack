#pragma once
#include <string>
#include "Linear_Stack.h"
using namespace std;
char Precede(const char &a, const char &b)//�Ƚ�������ȼ� aΪջ��Ԫ�� bΪջ��Ԫ��
{
	int index_a = 0;//��
	int index_b = 0;//��
	//						   '+', '-', '*', '/', '(', ')', '#' 
	char OprRelation[7][7] = { {'>', '>', '<', '<', '<', '>', '>'}, //  '+'  
							  {'>', '>', '<', '<', '<', '>', '>'}, //  '-'  
							  {'>', '>', '>', '>', '<', '>', '>'}, //  '*'  
							  {'>', '>', '>', '>', '<', '>', '>'}, //  '/'  
							  {'<', '<', '<', '<', '<', '=', ' '}, //  '('  
							  {'>', '>', '>', '>', ' ', '>', '>'}, //  ')'  
							  {'<', '<', '<', '<', '<', ' ', '='} };// '#'  
	switch (a)//���������ȼ�
	{
	case'+': {
		index_a = 0;
		break; }
	case'-': {
		index_a = 1;
		break; }
	case'*': {
		index_a = 2;
		break; }
	case'/': {
		index_a = 3;
		break; }
	case'(': {
		index_a = 4;
		break; }
	case')': {
		index_a = 5;
		break; }
	case'#': {
		index_a = 6;
		break; }
	default:
		break;
	}
	switch (b)//���������ȼ�
	{
	case'+': {
		index_b = 0;
		break; }
	case'-': {
		index_b = 1;
		break; }
	case'*': {
		index_b = 2;
		break; }
	case'/': {
		index_b = 3;
		break; }
	case'(': {
		index_b = 4;
		break; }
	case')': {
		index_b = 5;
		break; }
	case'#': {
		index_b = 6;
		break; }
	default:
		break;
	}
	return OprRelation[index_a][index_b];
}
double calculate(string &str)
{
	double result = 0;
	int length= str.length();//��¼ջ��
	Linear_Stack<char> OPTR(length);//�����ջ
	Linear_Stack<double> OPND(length);//������ջ
	for (int i = 0; i < length; i++)
	{
		double a = 0;
		double b = 0;
		int number_count = -1;//��¼����λ�� 
		int count = 0;//�������ּ�����  (10^count)
		double sum = 0;
		if (str[i] >= '0'&&str[i] <= '9')//�����������ѹ�� OPND������ջ
		{
			for (int j = i ; j < length; j++)//��ⳤ��������λ�� 
				if (str[j] >= '0'&&str[j] <= '9') 
					number_count++; //�� ����������λ��
				else break;
			count = number_count;//count��¼С����ǰλ��
			for (int j = i; j < length; j++, count--)//���ݽ�����������
			{
				if (count >= 0)
					sum = sum + (int(str[j]) - 48) * pow(10, count);
				else break;
			}
			if (str[i + number_count + 1] == '.')//���С�����λ��
			{
				number_count++;//�� С�����λ��
				count = 0;//��¼С�����η�λ��
				for (int j = (i + number_count + 1); j < length; j++)
					if (str[j] >= '0'&&str[j] <= '9') 
					{
						number_count++;
						count--;//�� С�����λ��
						sum = sum + (int(str[j]) - 48) * pow(10, count);
					}
					else break;
			}
			i = i + number_count;//����α�������������
			OPND.Push(sum);
		}
		else if (OPTR.Empty())		//��һ��ѹ����ʼ����#��
			OPTR.Push(str[i]);
		else {						//������������ѹ�� OPTR�����ջ
			switch (Precede(char(OPTR.Top()), str[i]))
			{
			case'<': {//����ջ��������ȼ�С��ջ�������
				OPTR.Push(str[i]);
				break;}
			case'>': {//����ջ��������ȼ�����ջ�������   ִ������
				b = OPND.Pop();
				a = OPND.Pop();
				switch (char(OPTR.Pop()))
				{
				case'+': {//�ӷ�����
					OPND.Push(a + b);
					if (str[i] != '#' && str[i] != ')')OPTR.Push(str[i]); //����'#'��')'��ѹ��ջ�������´αȽ�
					break; }
				case'-': {//��������
					OPND.Push(a - b);
					if (str[i] != '#' && str[i] != ')')OPTR.Push(str[i]);
					break; }
				case'*': {//�˷�����
					OPND.Push(a * b);
					if (str[i] != '#' && str[i] != ')')OPTR.Push(str[i]);
					break; }
				case'/': {//��������
					OPND.Push(a / b);
					if (str[i] != '#' && str[i] != ')')OPTR.Push(str[i]);
					break; }
				default://switch (char(OPTR.Pop()))
					break;
				} 
				if (i == length - 1 || str[i] == ')')i--;//��Ϊ'#'��')'��i��λ��������
				break;
			}
			case'=': {
				if (str[i] == ')')//��Ϊ����������������
					OPTR.Pop();
				else if (str[i] == '#')//��Ϊ��������#����������㷵�ؽ��
				{
					OPTR.Pop();
					result = OPND.Pop();
					break;
				}
				break;
			}
			default://switch (Precede(char(OPTR.Top()), str[i]))
				break;
			}		
		}
	}
	return result;
}