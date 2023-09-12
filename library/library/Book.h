#pragma once
#ifndef _book_h_
#define _book_h_
#include<iostream>
using namespace std;
class Book
{
private:
	int note;//删除标记（1：已删，0：未删）
	int number;//图书编号
	char name[100];//书名
	int onshelf;//上架标志
public:
	Book() {};
	char* getname();
	int getnote();
	int getnumber();
	void setname(char na[]);
	void delbook();
	void addbook(int n, char* na);
	int borrowbook();
	void retbook();
	void list();
	void setonshelf(int n);
};
#endif