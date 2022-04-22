#pragma once
#include <string>
#include "Linear_Stack.h"
using namespace std;
char Precede(const char &a, const char &b)//比较算符优先级 a为栈顶元素 b为栈外元素
{
	int index_a = 0;//行
	int index_b = 0;//列
	//						   '+', '-', '*', '/', '(', ')', '#' 
	char OprRelation[7][7] = { {'>', '>', '<', '<', '<', '>', '>'}, //  '+'  
							  {'>', '>', '<', '<', '<', '>', '>'}, //  '-'  
							  {'>', '>', '>', '>', '<', '>', '>'}, //  '*'  
							  {'>', '>', '>', '>', '<', '>', '>'}, //  '/'  
							  {'<', '<', '<', '<', '<', '=', ' '}, //  '('  
							  {'>', '>', '>', '>', ' ', '>', '>'}, //  ')'  
							  {'<', '<', '<', '<', '<', ' ', '='} };// '#'  
	switch (a)//决定行优先级
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
	switch (b)//决定列优先级
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
	int length= str.length();//记录栈长
	Linear_Stack<char> OPTR(length);//运算符栈
	Linear_Stack<double> OPND(length);//操作数栈
	for (int i = 0; i < length; i++)
	{
		double a = 0;
		double b = 0;
		int number_count = -1;//记录数字位数 
		int count = 0;//整合数字计数器  (10^count)
		double sum = 0;
		if (str[i] >= '0'&&str[i] <= '9')//如果是数字则压入 OPND操作数栈
		{
			for (int j = i ; j < length; j++)//检测长整型数字位数 
				if (str[j] >= '0'&&str[j] <= '9') 
					number_count++; //记 长整型数字位数
				else break;
			count = number_count;//count记录小数点前位数
			for (int j = i; j < length; j++, count--)//回溯进行数字整合
			{
				if (count >= 0)
					sum = sum + (int(str[j]) - 48) * pow(10, count);
				else break;
			}
			if (str[i + number_count + 1] == '.')//检测小数点后位数
			{
				number_count++;//记 小数点后位数
				count = 0;//记录小数点后次方位数
				for (int j = (i + number_count + 1); j < length; j++)
					if (str[j] >= '0'&&str[j] <= '9') 
					{
						number_count++;
						count--;//记 小数点后位数
						sum = sum + (int(str[j]) - 48) * pow(10, count);
					}
					else break;
			}
			i = i + number_count;//检测游标跳过整串数字
			OPND.Push(sum);
		}
		else if (OPTR.Empty())		//第一次压入起始符“#”
			OPTR.Push(str[i]);
		else {						//如果是运算符则压入 OPTR运算符栈
			switch (Precede(char(OPTR.Top()), str[i]))
			{
			case'<': {//待入栈运算符优先级小于栈顶运算符
				OPTR.Push(str[i]);
				break;}
			case'>': {//待入栈运算符优先级大于栈顶运算符   执行运算
				b = OPND.Pop();
				a = OPND.Pop();
				switch (char(OPTR.Pop()))
				{
				case'+': {//加法运算
					OPND.Push(a + b);
					if (str[i] != '#' && str[i] != ')')OPTR.Push(str[i]); //若非'#'和')'则压入栈顶参与下次比较
					break; }
				case'-': {//减法运算
					OPND.Push(a - b);
					if (str[i] != '#' && str[i] != ')')OPTR.Push(str[i]);
					break; }
				case'*': {//乘法运算
					OPND.Push(a * b);
					if (str[i] != '#' && str[i] != ')')OPTR.Push(str[i]);
					break; }
				case'/': {//除法运算
					OPND.Push(a / b);
					if (str[i] != '#' && str[i] != ')')OPTR.Push(str[i]);
					break; }
				default://switch (char(OPTR.Pop()))
					break;
				} 
				if (i == length - 1 || str[i] == ')')i--;//若为'#'或')'则i退位继续计算
				break;
			}
			case'=': {
				if (str[i] == ')')//若为右括号则括号相消
					OPTR.Pop();
				else if (str[i] == '#')//若为结束符“#”则结束运算返回结果
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