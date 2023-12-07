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
	~Stack() { delete[] elements; };		//析构函数
	void Push(T x);		//新元素入栈
	int Pop();			//栈顶元素出栈，由x返回
	T getTop();		//读取栈顶元素，由x返回
	bool IsEmpty();			//判断栈是否为空
	bool IsFull();			//判断栈是否满
	int getSize();			//计算栈中的元素个数
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
	T* elements;				//存放栈元素的数组
	int top;					//栈顶指针
	int maxSize;				//栈可最大可容纳元素个数
	void overflowProcess();		//栈的溢出处理		
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
	// 实现getTop函数的代码
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
	// 实现IsEmpty函数的代码
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
	// 实现Pop函数的代码			
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
	// 实现IsFull函数的代码
}

template<class T>
int Stack<T>::getSize()
{

	return top + 1;
	// 实现getSize函数的代码
}

template<class T>
void Stack<T>::overflowProcess()
{
	T* newArray = new T[maxSize * 2];
	if (newArray == NULL)
	{
		cerr << "存储分配失败" << endl;
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
		if (isdigit(*OPTR) || *OPTR == '.') // 判断是否是数字或小数点
		{
			while (isdigit(*OPTR) || *OPTR == '.') // 循环读取数字或小数点
			{
				OPND[i++] = *OPTR; // 将数字或小数点加入到OPND数组中
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
				// 将整数转换为浮点数
				c = (double)b / (float)a;
				st.Push(c);
			}
			else
			{
				cout << "除零错误!" << endl;
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
		cout << "请输入算式(输入exit退出）："<<endl;
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