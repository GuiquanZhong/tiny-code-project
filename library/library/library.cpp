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
	cout << "欢迎进入“小小图书馆”管理软件" << endl;
	cout << "----------------------------------" << endl;
	while (choice != 0)
	{
		cout << "**********************************" << endl;
		cout << "************ 1：借书  ************" << endl;
		cout << "************ 2：还书  ************" << endl;
		cout << "************ 3：图书维护  ********" << endl;
		cout << "************ 4：读者维护  ********" << endl;
		cout << "************ 0：离开  ************" << endl;
		cout << "**********************************" << endl;
		cout << "----------------------------------" << endl;
		cin >> choice;
		cout << "----------------------------------" << endl;
		switch (choice)
		{
		case 1:
			cout << "输入借书读者编号" << endl;
			cin >> readerid;
			cout << "输入图书编号" << endl;
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在，不能借书！" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在，不能借书！" << endl;
				break;
			}
			if (b->borrowbook() == 0) {
				cout << "该图书已借出，不能借书！" << endl;
				break;
			}
			r->borrowbook(b->getnumber(),b); break;
		case 2:
			cout << "输入还书读者编号" << endl;
			cin >> readerid;
			cout << "输入图书编号" << endl;
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在，不能还书！" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在，不能还书！" << endl;
				break;
			}
			b->retbook();
			r->retbook(b->getnumber()); break;
		case 3:BookDB.bookdata(); break;
		case 4:
			ReaderDB.readerdata(); break;

		}//end switch
	}//end while
	cout << "欢迎下次使用！" << endl;
	return 0;
}