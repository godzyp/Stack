#pragma once
#include <string>
#include "Linear_Stack.h"
using namespace std;
bool illegal(string &str)//检测算式是否非法，非法返回true，否则返回false
{
	Linear_Stack<char> s;//括号匹配检测栈
	bool state = false;
	if (str[1] == ')' || str[1] == '+' || str[1] == '-' || str[1] == '*' || str[1] == '/')
	{
		state = true;//首字符为“ ) + - * / ”不合法
		goto error;
	}
	if (str[str.length() - 2] == '(' || str[str.length() - 2] == '+' || str[str.length() - 2] == '-' ||
		str[str.length() - 2] == '*' || str[str.length() - 2] == '/')
	{
		state = true;//尾字符为“ ( + - * / ”不合法
		goto error;
	}
	for (int i = 1; i < (str.length() - 1); i++)
	{
		if (str[i]>='0'&&str[i] <='9')
		{
			if (str[i + 1] == '(' || str[i - 1] == ')')
			{
				state = true;//数字左邻")"或右邻"(" 不合法 
				goto error;
			}
		}
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			if(str[i+1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/')
			{
				state = true;//相邻字符为“  + - * / ”不合法
				goto error;
			}
		if (str[i] == '(' )
			s.Push(str[i]);	
		if (str[i] == ')')
		{
			if (str[i + 1] == '('||s.Empty() )//")"和"("相邻 不合法	
			{			
				state = true;//"("和")"不对应 不合法
				goto error;
			}
			else if (!s.Empty() && s.Top() == '(')//左括号碰到右括号相消
				s.Pop();
		}
	}
	if (!s.Empty())
	{
		state = true;//"("和")"不对应 不合法
		goto error;
	}
	error://遇到错误跳出 标签
	return state;
}