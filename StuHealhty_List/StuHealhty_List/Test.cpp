#include"StuHea_List.h"

int main()
{
	
	while (true)
	{
		
		menu();
		cout << "��ѡ�����" << endl;
		int x;
		cin >> x;
		system("cls");
		StuList s1;
		switch (x)
		{
		case 1:
		{
			s1.StuList1();
			break;
		}
		case 2:
		{
			s1.Stuadd();
			break;
		}
		case 4:
		{
			s1.StuErase();
			break;
		}
		case 3:
		{
			s1.StuFind();
			break;
		}
		case 6:
		{
			s1.readFile();
			break;
		}
		case 5:
		{
			s1.writeToFile();
			break;
		}
		case 7:
		{
			s1.Stushow();
			break;
		}
		case 8:
		{
			cout << "�˳��ɹ�" << endl;
			exit(0);
			break;
		}
		default:cout << "�����������������" << endl;
		}
		
	}



	return 0;
}