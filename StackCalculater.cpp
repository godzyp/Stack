#include <iostream>
#include <string>
#include "Formula_Filter.h"
#include "Formula_illegal.h"
#include "Calculater.h"
using namespace std;
#define test
int main()
{
#ifdef test
	string formula;//存储运算式 
	for (int a = 1; a != 0;)
	{
		cout << "请输入算式:" << endl;
		cin >> formula;//获取算式(其中包含空格)
		formula = Filter(formula);//过滤非法字符
		if (illegal(formula))//检测算式合法性
			cerr << "Error!输入算式有误" << endl;
		else
			cout << "Success!结果为:" << calculate(formula) << endl;//输出结果*/
		cin >> a;
	}
	return 0;
#endif // test

#ifndef test
	string formula;//存储运算式 
		cout << "请输入算式:" << endl;
		cin >> formula;//获取算式(其中包含空格)
		//getline(cin, formula);
		formula = Filter(formula);//过滤非法字符
		if (illegal(formula))//检测算式合法性
			cerr << "Error!输入算式有误";
		else
			cout << "Success!结果为:" << calculate(formula) << endl;//输出结果*/
		return 0;
#endif // !test
}

