#pragma once
#include <iostream>
#include <string>
using namespace std;
const int INIT_SIZE = 30;//默认初始化栈长为30
template<class T>
class Linear_Stack
{
public:
	Linear_Stack();
	Linear_Stack(const int &length);
	~Linear_Stack();
////////////////////////////////////////////
	T Pop();
	void Push(const T &x);
	T Top();
////////////////////////////////////////////
	void InitStack();
	void InitStack(const int &length);
	void DestroyStack();
////////////////////////////////////////////	
	bool Empty();
	const int Length();
	void Clear();
private:
	int MAX_SIZE;
	T *base;//栈底指针
	T *top;//栈顶指针
	int count;//记录栈内元素数目
};
////////////////////////////////////////////////////////////////////////////////////////
template <class T>
Linear_Stack<T>::Linear_Stack()//构造函数初始化栈 默认栈长为30
{
	InitStack();
}
template <class T>
void Linear_Stack<T>::InitStack()//初始化栈 默认栈长为30
{
	base = new T[INIT_SIZE];//动态分配内存
	if (!base) { cout << "Overflow" << endl; exit(1); }//内存分配失败
	top = base;//栈顶指针与栈底指针初始化
	count = -1;//初始栈长度为0  count作为数组下标
	MAX_SIZE = INIT_SIZE;//设置最大栈长
}
template <class T>
Linear_Stack<T>::Linear_Stack(const int &length)//构造函数初始化栈 自定义栈长
{
	InitStack(length);
}
template <class T>
void Linear_Stack<T>::InitStack(const int &length)//初始化栈 自定义栈长
{
	base = new T[length];//动态分配内存
	if (!base) { cout << "Overflow" << endl; exit(1); }//内存分配失败
	top = base;//栈顶指针与栈底指针初始化
	count = -1;//初始栈长度为0  count作为数组下标
	MAX_SIZE = length;//设置最大栈长
}
////////////////////////////////////////////////////////////////////////////////////////
template <class T>
Linear_Stack<T>::~Linear_Stack()//析构函数销毁栈
{
	DestroyStack();
}
template <class T>
void Linear_Stack<T>::DestroyStack()//销毁栈
{
	top = base;
	delete[]base;
}
////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Linear_Stack<T>::Pop()//将栈顶元素弹出
{
	if (Empty())//栈空无元素
		return NULL;
	else { return *--top; count--; *(top + 1) = NULL; }
}
template<class T>
void Linear_Stack<T>::Push(const T &x)//将元素压入栈顶
{
	if (top - base >= MAX_SIZE)//栈满溢出
		cout << "Error!栈满." << endl;
	else
	{
		*top = x;//压入元素
		top++;
		count++;//栈长+1
	}
}
template<class T>
T Linear_Stack<T>::Top()//返回栈顶元素
{
	if (Empty())//栈空无元素
	{
		cout << "Error! 栈空" << endl;
		return NULL;
	}
	else return *(top - 1);//返回栈顶元素
}
////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool Linear_Stack<T>::Empty()//检测栈是否为空
{
	bool state = true;//初始栈为空
	if (top == base)state = true;//栈顶指针与栈底指针地址相同即空
	else state = false;
	return state;
}
template <class T>
const int Linear_Stack<T>::Length()//返回栈长
{
	return (count + 1);
}
template <class T>
void Linear_Stack<T>::Clear()//清空栈
{
	for (int i = 0; i < count + 1; i++, top--)
		*top = NULL;
	top = base;
	count = -1;
}
////////////////////////////////////////////////////////////////////////////////////////
