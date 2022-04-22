#pragma once
#include <iostream>
#include <string>
using namespace std;
const int INIT_SIZE = 30;//Ĭ�ϳ�ʼ��ջ��Ϊ30
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
	T *base;//ջ��ָ��
	T *top;//ջ��ָ��
	int count;//��¼ջ��Ԫ����Ŀ
};
////////////////////////////////////////////////////////////////////////////////////////
template <class T>
Linear_Stack<T>::Linear_Stack()//���캯����ʼ��ջ Ĭ��ջ��Ϊ30
{
	InitStack();
}
template <class T>
void Linear_Stack<T>::InitStack()//��ʼ��ջ Ĭ��ջ��Ϊ30
{
	base = new T[INIT_SIZE];//��̬�����ڴ�
	if (!base) { cout << "Overflow" << endl; exit(1); }//�ڴ����ʧ��
	top = base;//ջ��ָ����ջ��ָ���ʼ��
	count = -1;//��ʼջ����Ϊ0  count��Ϊ�����±�
	MAX_SIZE = INIT_SIZE;//�������ջ��
}
template <class T>
Linear_Stack<T>::Linear_Stack(const int &length)//���캯����ʼ��ջ �Զ���ջ��
{
	InitStack(length);
}
template <class T>
void Linear_Stack<T>::InitStack(const int &length)//��ʼ��ջ �Զ���ջ��
{
	base = new T[length];//��̬�����ڴ�
	if (!base) { cout << "Overflow" << endl; exit(1); }//�ڴ����ʧ��
	top = base;//ջ��ָ����ջ��ָ���ʼ��
	count = -1;//��ʼջ����Ϊ0  count��Ϊ�����±�
	MAX_SIZE = length;//�������ջ��
}
////////////////////////////////////////////////////////////////////////////////////////
template <class T>
Linear_Stack<T>::~Linear_Stack()//������������ջ
{
	DestroyStack();
}
template <class T>
void Linear_Stack<T>::DestroyStack()//����ջ
{
	top = base;
	delete[]base;
}
////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Linear_Stack<T>::Pop()//��ջ��Ԫ�ص���
{
	if (Empty())//ջ����Ԫ��
		return NULL;
	else { return *--top; count--; *(top + 1) = NULL; }
}
template<class T>
void Linear_Stack<T>::Push(const T &x)//��Ԫ��ѹ��ջ��
{
	if (top - base >= MAX_SIZE)//ջ�����
		cout << "Error!ջ��." << endl;
	else
	{
		*top = x;//ѹ��Ԫ��
		top++;
		count++;//ջ��+1
	}
}
template<class T>
T Linear_Stack<T>::Top()//����ջ��Ԫ��
{
	if (Empty())//ջ����Ԫ��
	{
		cout << "Error! ջ��" << endl;
		return NULL;
	}
	else return *(top - 1);//����ջ��Ԫ��
}
////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool Linear_Stack<T>::Empty()//���ջ�Ƿ�Ϊ��
{
	bool state = true;//��ʼջΪ��
	if (top == base)state = true;//ջ��ָ����ջ��ָ���ַ��ͬ����
	else state = false;
	return state;
}
template <class T>
const int Linear_Stack<T>::Length()//����ջ��
{
	return (count + 1);
}
template <class T>
void Linear_Stack<T>::Clear()//���ջ
{
	for (int i = 0; i < count + 1; i++, top--)
		*top = NULL;
	top = base;
	count = -1;
}
////////////////////////////////////////////////////////////////////////////////////////
