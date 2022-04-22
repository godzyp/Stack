#pragma once
#include <string>
using namespace std;
string Filter(const string &str)//字符串过滤
/*	过滤后仅剩数字1~9及 ‘+’ ‘-’ ‘*’ ‘/’ ‘(’ ‘)’ ‘.’ ‘’ ‘’	*/
{
	string formula;
	formula.append("#");//设置算式起始符#
	for (int i = 0; i < (str.length()); i++)
	{
		if (str[i] == '+'||str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')' || str[i] == '.')//运算符过滤
			formula.append(str, i, 1);//将经过过滤的字符加入至待输出字符串
		else if (str[i] >= '0' &&  str[i] <= '9')
				//运算数字过滤
				formula.append(str, i, 1);//将经过过滤的字符加入至待输出字符串
		else continue;
	}
	formula.append("#");//设置算式终止符#
	return formula;//返回过滤后的字符串
}