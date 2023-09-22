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
	Student* next;
};
class StuList
{
public:
	void StuList1();
	void Stuadd();
	void StuFind();
	void StuErase();
	void writeToFile();
	void readFile();
	void Stushow();
protected:
	Student* head;
};
void menu();


