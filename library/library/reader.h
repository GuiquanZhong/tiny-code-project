#pragma once
#ifndef _reader_h_
#define _reader_h_
#include<iostream>
#include<cstring>
#include"Book.h"
using namespace std;
const int Maxbor = 5;
class Reader
{
private:
	int note;
	long long number;
	char name[100];
	int borbook[Maxbor];
public:
	Reader() {};
	char* getname();
	int getnote();
	void setnote(int n);
	int getnumber();
	void setname(char na[]);
	void delbook();
	void addreader(int n, char* na);
	void delreader(long long number);
	void borrowbook(int bookid,Book *b);
	int retbook(int bookid);
	void list();
};
#endif