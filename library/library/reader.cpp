#define _CRT_SECURE_NO_WARNINGS
#include<iomanip>
#include"reader.h"
#include"Book.h"
#include<iostream>
char* Reader::getname()
{
	return name;
}
int Reader::getnote()
{
	return note;
}
int Reader::getnumber()
{
	return number;
}
void Reader::setname(char na[])
{
	strcpy(name, na);
}
void Reader::addreader(int n, char* na)
{
	note = 0;
	number = n;
	strcpy(name, na);
	for (int i = 0; i < Maxbor; i++)
	{
		borbook[i] = 0;
	}
}
	void Reader::delbook()
	{
		note = 1;
	}
	//void Reader::setnote(int n)
	//{
	//	note = n;
	//}
	//void Reader::delreader(long long readerid)
	//{
	//	for (int i = 0; i < Maxbor; i++)
	//	{
	//		if (borbook[i] != 0)
	//		{
	//			cout << "该读者还有未归还的书，不能删除！" << endl;
	//			return;
	//		}
	//	}
	//	/*setnote(1); */// 将读者状态设置为已删除
	//}
	void Reader::borrowbook(int bookid,Book *b)
	{

		for (int i = 0; i < Maxbor; i++)
		{
			if (borbook[i] == 0)
			{
				borbook[i] = bookid;
				b->setonshelf(0);
				return; 
			}
		}
	}
	int Reader::retbook(int bookid)
	{
		for (int i = 0; i < Maxbor; i++)
		{
			if (borbook[i] = bookid) { borbook[i] = 0; return 1; }
		}
		return 0;
	}
	void Reader::list()
	{
		cout << setw(5) << number << setw(10) << name << "借书编号: [";
		for (int i = 0; i < Maxbor; i++)
		{
			if (borbook[i] == 0)cout << borbook[i] << " ";
			else if (borbook[i] != 0)
			{
				cout << borbook[i] << " ";
			}
		}
		cout << "]" << endl;
	}