#pragma once
#include<iostream>
#include<fstream>;
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
	SeqList();
	void StuInsert();
	void StuCheck();
	void StuErase(string num, string name);
	void writeToFile();
protected:
	Student* a;
	int last;
	int Maxsize;
};


