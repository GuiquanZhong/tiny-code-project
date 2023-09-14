#pragma once
#include<iostream>
#include<fstream>;
#include<string>
using namespace std;
struct Student
{
	string number;
	string name, birthday, sex;
	string healthy;
};
class SeqList
{
public:
	void SeqList1();
	void Stuadd();
	void StuFind();
	void StuInsert();
	void StuCheck();
	void StuErase(string num, string name);
	void writeToFile();
	void readFile();
	void Stushow();
protected:
	Student* a;
	int last;
	int Maxsize;
};
void menu();


