#pragma once
#ifndef _book_h_
#define _book_h_
#include<iostream>
using namespace std;
class Book
{
private:
	int note;//ɾ����ǣ�1����ɾ��0��δɾ��
	int number;//ͼ����
	char name[100];//����
	int onshelf;//�ϼܱ�־
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