#include<fstream>
#include<iostream>
#include"rdatabase.h"
using namespace std;
RDatabase::RDatabase()
{
	Reader s;
	top = -1;
	ifstream file;
	file.open("reader.dat", ios::in | ios::binary);

	while (1)
	{
		file.read((char*)&s, sizeof(s));
		if (!file)break;
		top++;
		read[top] = s;
	}
	file.close();
}
void RDatabase::clear()
{
	top = -1;
	ofstream file;
	file.open("reader.dat", ios::out | ios::binary);
	file.close();
}
Reader* RDatabase::query(int readerid)
{
	for (int i = 0; i <= top; i++)
		if (read[i].getnumber() == readerid && read[i].getnote() == 0)
			return &read[i];
	return NULL;
}
int RDatabase::addreader(int n, char* na)
{
	Reader* p = query(n);
	if (p == NULL)
	{
		top++;
		read[top].addreader(n, na);
		return 1;
	}
	return 0;
}
void RDatabase::list()
{
	for (int i = 0; i <= top; i++)
		read[i].list();
}
RDatabase::~RDatabase()
{
	fstream file;
	file.open("reader.dat", ios::out | ios::binary);
	for (int i = 0; i <= top; i++)
		if (read[i].getnote() == 0)
			file.write((char*)&read[i], sizeof(read[i]));
		file.close();
}
void RDatabase::readerdata()
{
	int choice = 1;
	char readername[20];
	long long readerid;
	Reader* r;
	while (choice != 0)
	{
		cout << "����ά���� " << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "1:���� 2������ 3��ɾ�� 4������ 5����ʾ 6��ȫɾ 0���˳�" << endl;
		cin >> choice;
		cout << "---------------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:cout << "������߱�ţ� " << endl;
			cin >> readerid;
			cout << "������������� " << endl;
			cin >> readername;
			addreader(readerid, readername); break;
		case 2:cout << "������߱�ţ� " << endl;
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ� " << endl;
				break;
			}
			cout << "������������� " << endl;
			cin >> readername;
			r->setname(readername); break;
		case 3:cout << "������߱�ţ� " << endl;
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ�" << endl;
				break;
			} // ���ö��ߵ� note ��Ϊ 1����ʾ��ɾ��
			cout << "�ö�����ɾ����" << endl;
		case 4:
			cout << "������߱�ţ� " << endl;
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ�" << endl;
				break;
			}
			r->list(); break;
		case 5:list(); break;
		case 6:
			clear();
			break;
		}//end swtich
	}//end while
}