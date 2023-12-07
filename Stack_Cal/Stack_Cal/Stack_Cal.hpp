#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<assert.h>
#define MaxSize 100
using namespace std;

template<class T>
class Stack
{
public:
	Stack(int sz=50);
	~Stack() { delete[] elements; };		//��������
	void Push(T x);		//��Ԫ����ջ
	int Pop();			//ջ��Ԫ�س�ջ����x����
	T getTop();		//��ȡջ��Ԫ�أ���x����
	bool IsEmpty();			//�ж�ջ�Ƿ�Ϊ��
	bool IsFull();			//�ж�ջ�Ƿ���
	int getSize();			//����ջ�е�Ԫ�ظ���
	//ostream& operator << (ostream& os, Stack<T>& s)
	//{
	//	os << "top =" << s.pop << endl;
	//	for (int i = 0; i <= s.top; i++)
	//	{
	//		os << s.elements[i] << " ";
	//	}
	//	os << endl;
	//	return os;
	//}
private:
	T* elements;				//���ջԪ�ص�����
	int top;					//ջ��ָ��
	int maxSize;				//ջ����������Ԫ�ظ���
	void overflowProcess();		//ջ���������		
};


template<class T>
Stack<T>::Stack(int sz) :top(-1), maxSize(sz)
{
	elements = new T[maxSize];
	assert(elements != NULL);
}

template<class T>
void Stack<T>::Push(T x)
{
	if (top == -1 || top == maxSize - 1)
	{
		overflowProcess();
	}
	top++;
	elements[top] = x;
}



template<class T>
T Stack<T>::getTop()
{
	if (IsEmpty())
	{
		return 0;
	}
	return elements[top];
	// ʵ��getTop�����Ĵ���
}

template<class T>
bool Stack<T>::IsEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
	// ʵ��IsEmpty�����Ĵ���
}

template<class T>
int Stack<T>::Pop()
{
	int x = 0;
	if (!IsEmpty())
	{
		x = elements[top];
		top--;
	}
	return x;
	// ʵ��Pop�����Ĵ���			
}

template<class T>
bool Stack<T>::IsFull()
{
	if (top == maxSize-1)
	{
		return true;
	}
	else
	{
		return false;
	}
	// ʵ��IsFull�����Ĵ���
}

template<class T>
int Stack<T>::getSize()
{

	return top + 1;
	// ʵ��getSize�����Ĵ���
}

template<class T>
void Stack<T>::overflowProcess()
{
	T* newArray = new T[maxSize * 2];
	if (newArray == NULL)
	{
		cerr << "�洢����ʧ��" << endl;
		exit(1);
	}
	for (int i = 0; i <= top; i++)
	{
		newArray[i] = elements[i];
	}
	maxSize *= 2;
	delete[] elements;
	elements = newArray;
}


void trans(char OPTR[],char OPND[])
{
	Stack<char> op;
	int i = 0;
	while (*OPTR != '\0')
	{
		if (isdigit(*OPTR) || *OPTR == '.') // �ж��Ƿ������ֻ�С����
		{
			while (isdigit(*OPTR) || *OPTR == '.') // ѭ����ȡ���ֻ�С����
			{
				OPND[i++] = *OPTR; // �����ֻ�С������뵽OPND������
				OPTR++;
			}
			OPND[i++] = '#';
		}
		else if (*OPTR == '(')
		{
			op.Push(*OPTR);
			OPTR++;
		}
		else if (*OPTR == ')')
		{
			while (op.getTop() != '(')
			{
				OPND[i++] = op.getTop();
				op.Pop();
			}
			op.Pop();
			OPTR++;
		}
		else if (*OPTR == '+' || *OPTR == '-')
		{
			while (!op.IsEmpty() && op.getTop() != '(')
			{
				OPND[i++] = op.getTop();
				op.Pop();
			}
			op.Push(*OPTR);
			OPTR++;
		}
		else if (*OPTR == '*' || *OPTR == '/')
		{
			while (!op.IsEmpty() && (op.getTop() == '*' || op.getTop() == '/'))
			{
				OPND[i++] = op.getTop();
				op.Pop();
			}
			op.Push(*OPTR);
			OPTR++;
		}
	}
	while (!op.IsEmpty())
	{
		OPND[i++] = op.getTop();
		op.Pop();
	}
}

double compvalue(char OPND[])
{
	Stack<double> st;
	double a, b, c, d;
	while (*OPND != '\0')
	{
		if (*OPND == '+')
		{
			a = st.getTop();
			st.Pop();
			b = st.getTop();
			st.Pop();
			c = b + a;
			st.Push(c);
		}
		else if (*OPND == '-')
		{
			a = st.getTop();
			st.Pop();
			b = st.getTop();
			st.Pop();
			c = b - a;
			st.Push(c);
		}
		else if (*OPND == '*')
		{
			a = st.getTop();
			st.Pop();
			b = st.getTop();
			st.Pop();
			c = b * a;
			st.Push(c);
		}
		else if (*OPND == '/')
		{
			a = st.getTop();
			st.Pop();
			b = st.getTop();
			st.Pop();
			if (a != 0)
			{
				// ������ת��Ϊ������
				c = (double)b / (float)a;
				st.Push(c);
			}
			else
			{
				cout << "�������!" << endl;
				exit(0);
			}
		}
		else
		{
			d = 0;
			bool isFraction = false;
			while (isdigit(*OPND) || *OPND == '.')
			{
				if (*OPND == '.')
				{
					isFraction = true;
				}
				else if (isFraction)
				{
					d = d + (*OPND - '0') * pow(0.1, isFraction);
					isFraction++;
				}
				else
				{
					d = d * 10 + (*OPND - '0');
				}
				OPND++;
			}
			st.Push(d);
		}
		OPND++;
	}
	return st.getTop();
}



void menu()
{
	
	while (true)
	{
		char OPTR[MaxSize];
		char OPND[MaxSize] = { 0 };
		cout << "��������ʽ(����exit�˳�����"<<endl;
		cin >> OPTR;
		if (*OPTR == 'e')
		{
			break;
		}
		trans(OPTR, OPND);
		cout << OPND << endl;
		float x = compvalue(OPND);
		cout << fixed << setprecision(3) << x << endl;;
	}
	system("pause");
}