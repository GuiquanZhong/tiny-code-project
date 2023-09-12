#define _CRT_SECURE_NO_WARNINGS
#include"bdatabase.h"
#include"reader.h"
#include"Book.h"
#include"rdatabase.h"
#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int choice = 1;
	long long bookid,readerid;
	RDatabase ReaderDB;
	BDatabase BookDB;
	Reader* r;
	Book* b;
	cout << "��ӭ���롰ССͼ��ݡ��������" << endl;
	cout << "----------------------------------" << endl;
	while (choice != 0)
	{
		cout << "**********************************" << endl;
		cout << "************ 1������  ************" << endl;
		cout << "************ 2������  ************" << endl;
		cout << "************ 3��ͼ��ά��  ********" << endl;
		cout << "************ 4������ά��  ********" << endl;
		cout << "************ 0���뿪  ************" << endl;
		cout << "**********************************" << endl;
		cout << "----------------------------------" << endl;
		cin >> choice;
		cout << "----------------------------------" << endl;
		switch (choice)
		{
		case 1:
			cout << "���������߱��" << endl;
			cin >> readerid;
			cout << "����ͼ����" << endl;
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ����ܽ��飡" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ����ܽ��飡" << endl;
				break;
			}
			if (b->borrowbook() == 0) {
				cout << "��ͼ���ѽ�������ܽ��飡" << endl;
				break;
			}
			r->borrowbook(b->getnumber(),b); break;
		case 2:
			cout << "���뻹����߱��" << endl;
			cin >> readerid;
			cout << "����ͼ����" << endl;
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ����ܻ��飡" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ����ܻ��飡" << endl;
				break;
			}
			b->retbook();
			r->retbook(b->getnumber()); break;
		case 3:BookDB.bookdata(); break;
		case 4:
			ReaderDB.readerdata(); break;

		}//end switch
	}//end while
	cout << "��ӭ�´�ʹ�ã�" << endl;
	return 0;
}